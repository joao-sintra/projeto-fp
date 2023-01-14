/*************************************************
                    Projeto FP
    Unidade Curricular: Fundamentos de Programação
    Docente: Carmen Francisco
    Elaborado por:
    João Sintra, 2220865
    Francisco Furtado, 2220870
    Grupo 7 - PL2
****************************************************/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

//Constantes do número máximo de estudantes, atividades e incrições
#define NUMERO_MAXIMO_ESTUDANTES 5000
#define NUMERO_MAXIMO_ATIVIDADES 200
#define NUMERO_MAXIMO_INSCRICOES 10000

//Constantes dos nomes dos ficheiros
#define FICHEIRO_PARTICIPANTES "participantes.bin"
#define FICHEIRO_ATIVIDADES "atividades.bin"
#define FICHEIRO_INSCRICOES "inscricoes.bin"

#define TAMANHO_NOME 30
#define TAMANHO_NOME_ATIVIDADE 50
#define TAMANHO_EMAIL 30
#define TAMANHO_LOCAL 20


//---------- typedef struct das hora -----------------//
typedef struct {
    int horas;
    int minutos;
    int segundos;
} t_hora;
//---------------------------//---------------------------//
//---------- typedef struct da data -----------------//
typedef struct {
    int dia;
    int mes;
    int ano;
} t_data;

//---------- typedef struct do Registo dos Participantes -----------------//
typedef struct {
    int identificador;
    char nome[TAMANHO_NOME + 1];
    char escola[7];
    char nif[10];
    char email[TAMANHO_EMAIL + 1];
    char telefone[10];
} t_participante;
//---------------------------//---------------------------//

//---------- typedef struct do Registo das Atividades -----------------//
typedef struct {
    int identificador;
    char nome[TAMANHO_NOME_ATIVIDADE + 1];
    t_data data;
    t_hora hora;
    char local[TAMANHO_LOCAL + 1];
    char tipo[12];
    char associacao[11];
    float valor_inscricao;
} t_atividade;
//---------------------------//---------------------------//

//---------- typedef struct do Registo das Inscrições -----------------//
typedef struct {
    int identificador;
    int identificador_participante;
    int identificador_atividade;
    float valor_pago;
    t_data data;
    t_hora hora;
} t_inscricao;
//---------------------------//---------------------------//

//---------- Protótipos das funções para os menus -----------------//
char menu_principal(void);
char menu_registar(void);
char menu_consultar(void);
char menu_estatisticas(void);
char menu_saida(void);
//---------------------------//---------------------------//

//----------Protótipos das funções para Registar os Participantes e Consultar -----------------//
void regista_participante(t_participante participantes[], int* posicao, int* quantidade_participantes_por_adicionar);
char* devolve_escola();
void mostra_participante(int posicao);
void mostra_lista_paginada_participantes(int posicao, t_participante participantes[]);
void preenche_participantes(t_participante participantes[], int posicao);
void guarda_participantes_ficheiro(t_participante participantes[], int* quantidade_participantes_por_adicionar, int posicao);
int obter_ultima_posicao_participantes(void);
//---------------------------//---------------------------//

//----------Protótipos das funções para Registar as Atividades e Consultar -----------------//
void regista_atividade(t_atividade atividades[], int* posicao, int* quantidade_atividades_por_adicionar);
char* devolve_associacao();
char* devolve_tipo_atividade();
void mostra_atividade(int posicao);
void mostra_lista_paginada_atividades(int posicao, t_atividade atividades[]);
void preenche_atividades(t_atividade atividades[], int posicao);
void guarda_atividades_ficheiro(t_atividade atividades[], int* quantidade_atividades_por_adicionar, int posicao);
int obter_ultima_posicao_atividades(void);
//---------------------------//---------------------------//

//---------- Protótipos das funções para Registar as Incrições e Consultar -----------------//
void regista_inscricao(t_inscricao inscricoes[], t_atividade atividades[], int* posicao, int posicao_participantes, int posicao_atividade, int* quantidade_inscricoes_por_adicionar);
void mostra_inscricao(int posicao);
void mostra_lista_paginada_inscricoes(int posicao, t_inscricao inscricoes[]);
void preenche_inscricoes(t_inscricao inscricoes[], int posicao);
void guarda_inscricoes_ficheiro(t_inscricao inscricoes[], int* quantidade_inscricoes_por_adicionar, int posicao);
int obter_ultima_posicao_inscricoes(void);
//---------------------------//---------------------------//

//---------- Protótipo da função para Mostrar o número de Atividades realizadas por associação -----------------//
void numero_atividades_realizadas_por_associacao(t_atividade atividades[]);
//---------------------------//---------------------------//

//---------- Protótipo da função para Mostrar a percentagem de Inscrições por escola -----------------//
void percentagem_inscricoes_por_escola(t_inscricao inscricoes[], t_participante participantes[]);
//---------------------------//---------------------------//

//---------- Protótipos das funções para validar as datas inseridas pelo utilizador e Mostrar o valor total das inscrções entre duas datas por tipo de atividade -----------------//
void valida_horizonte_temporal(t_inscricao inscricoes[], int posicao, t_atividade atividades[]);
//---------------------------//---------------------------//

//---------- Protótipos das funções para a leitura e validação de dados -----------------//
char* le_nome(void);
int le_numero_intervalo(int min, int max);
char* le_nome_atividade(void);
char* le_email(void);
char* le_nif(t_participante participantes[], int posicao);
char* le_telefone(void);
int valida_dia(int dia, int mes);
int valida_mes(int mes);
int valida_ano(int ano);
int valida_horas(int hora);
int valida_minutos(int minutos);
int valida_segundos(int segundos);
t_hora le_hora(void);
t_hora le_horas_inscricao(void);
t_data le_data(void);
char* le_local(void);
float le_valor_atividade(void);
float le_valor_pago(t_atividade atividades[], int id_atividade);
int valida_formato_data(int check);
int valida_formato_hora(int check);
int valida_primeira_data_vetor(t_inscricao inscricoes[], t_inscricao inscricoes_aux[], int posicao, t_data primeira_data);
int valida_diferencas_datas(t_data primeira_data, t_data segunda_data);
int valida_segunda_data_vetor(t_inscricao inscricoes_aux[], t_inscricao inscricoes_validadas[], int posicao, t_data data);
void mostra_valores_por_tipo_atividade(int contador, t_inscricao inscricoes_validadas[], t_atividade atividades[]);
t_data valida_data_inscricao(t_atividade atividades[], int posicao);
t_hora valida_hora_inscricao(t_atividade atividades[], int posicao, t_data data_inscricao);
void valida_indentificadores_participantes_atividades(t_inscricao inscricoes[], int posicao, int posicao_atividade);
//---------------------------//---------------------------//

int main() {
    setlocale(LC_ALL, "Portuguese");
    char escolha_menu_principal, escolha_registar, escolha_consultar, escolha_estatistica, escolha_saida;
    int posicao_participantes = 0, posicao_atividades = 0, posicao_inscricoes = 0, quantidade_participantes_por_adicionar = 0, quantidade_atividades_por_adicionar = 0, quantidade_inscricoes_por_adicionar = 0;
    t_participante participantes[NUMERO_MAXIMO_ESTUDANTES];
    t_atividade atividades[NUMERO_MAXIMO_ATIVIDADES];
    t_inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES];

    posicao_participantes = obter_ultima_posicao_participantes();
    posicao_atividades = obter_ultima_posicao_atividades();
    posicao_inscricoes = obter_ultima_posicao_inscricoes();
    // posicao = 4;

    do {
        system("cls");
        preenche_participantes(participantes, posicao_participantes);
        preenche_atividades(atividades, posicao_atividades);
        preenche_inscricoes(inscricoes, posicao_inscricoes);
        //printf("Posicao Participantes: %d\n", posicao_participantes);
       // printf("Posicao Atividades: %d\n", posicao_atividades);
        //printf("Posicao Inscricoes: %d\n", posicao_inscricoes);
        escolha_menu_principal = menu_principal();
        fflush(stdin);
        switch (escolha_menu_principal) {
        case '1':
            do {
                system("cls");
                escolha_registar = menu_registar();
                fflush(stdin);
                switch (escolha_registar) {
                case '1':
                    regista_participante(participantes, &posicao_participantes, &quantidade_participantes_por_adicionar);
                    fflush(stdin);
                    break;
                case '2':
                    //printf("Registar os dados das atividades\n");
                    regista_atividade(atividades, &posicao_atividades, &quantidade_atividades_por_adicionar);
                    fflush(stdin);
                    break;
                case '3':
                    //printf("Registar os dados das inscricoes\n");
                    regista_inscricao(inscricoes, atividades, &posicao_inscricoes, posicao_participantes - quantidade_participantes_por_adicionar, posicao_atividades - quantidade_atividades_por_adicionar, &quantidade_inscricoes_por_adicionar);
                    fflush(stdin);
                    break;
                case '4'://guardar no ficheiro
                    guarda_participantes_ficheiro(participantes, &quantidade_participantes_por_adicionar, posicao_participantes);
                    guarda_atividades_ficheiro(atividades, &quantidade_atividades_por_adicionar, posicao_atividades);
                    guarda_inscricoes_ficheiro(inscricoes, &quantidade_inscricoes_por_adicionar, posicao_inscricoes);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '0':

                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while (escolha_registar != '0');
            break;
        case '2':
            do {
                system("cls");
                escolha_consultar = menu_consultar();
                fflush(stdin);
                switch (escolha_consultar) {

                case '1':
                    //printf("Consultar os dados dos participantes\n");
                    mostra_participante(posicao_participantes - quantidade_participantes_por_adicionar);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '2':
                    //printf("Consultar os dados das atividades\n");
                    mostra_atividade(posicao_atividades - quantidade_atividades_por_adicionar);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '3':
                    //printf("Consultar os dados das inscricoes\n");
                    mostra_inscricao(posicao_inscricoes - quantidade_inscricoes_por_adicionar);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
            } while (escolha_consultar != '0');
            break;
        case '3':
            do {
                system("cls");
                escolha_estatistica = menu_estatisticas();
                fflush(stdin);
                switch (escolha_estatistica) {
                case '1':
                    printf("Estatisticas do numero de atividades realizadas por cada associacao: \n");
                    numero_atividades_realizadas_por_associacao(atividades);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '2':
                    printf("Estatisticas da percentagem de inscricoes por escola\n");
                    percentagem_inscricoes_por_escola(inscricoes, participantes);
                    fflush(stdin);
                    printf("\n(ENTER) para continuar");
                    getchar();
                    break;
                case '3':
                    printf("Estatisticas do valor total das inscricoes entre duas datas por tipo de atividade\n");
                    valida_horizonte_temporal(inscricoes, posicao_inscricoes, atividades);
                    fflush(stdin);
                    printf("\n\n(ENTER) para continuar");
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while (escolha_estatistica != '0');
            break;

        case '0':
            system("cls");
            escolha_saida = menu_saida();
            fflush(stdin);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }

    } while (escolha_saida != 'S');

    guarda_participantes_ficheiro(participantes, &quantidade_participantes_por_adicionar, posicao_participantes);
    guarda_atividades_ficheiro(atividades, &quantidade_atividades_por_adicionar, posicao_atividades);
    guarda_inscricoes_ficheiro(inscricoes, &quantidade_inscricoes_por_adicionar, posicao_inscricoes);

    return 0;
}

//---------- Função do Menu principal -----------------//
char menu_principal(void) {
    char opcao;
    do {
        printf("*********************** Menu Principal ***********************\n");
        printf("[1] Registar\n");
        printf("[2] Consultar\n");
        printf("[3] Estatisticas\n");
        printf("[0] Sair\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida\n");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função do Menu dos registos -----------------//
char menu_registar(void) {
    char opcao;
    do {
        printf("*********************** Menu Registar ***********************\n");
        printf("[1] Registar os dados dos participantes\n");
        printf("[2] Registar os dados das atividades\n");
        printf("[3] Registar os dados das inscricoes\n");
        printf("[4] Guardar no ficheiro\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0' && opcao != '4')
            printf("Opcao invalida\n");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0' && opcao != '4');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função do Menu das consultas -----------------//
char menu_consultar(void) {
    char opcao;
    do {
        printf("*********************** Menu Consultar ***********************\n");
        printf("[1] Consultar os dados dos participantes\n");
        printf("[2] Consultar os dados das atividades\n");
        printf("[3] Consultar os dados das inscricoes\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida\n");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função do Menu das estatísticas -----------------//
char menu_estatisticas(void) {
    char opcao;
    do {
        printf("*********************** Menu Estatisticas ***********************\n");
        printf("[1] Estatisticas do numero de atividades realizadas por cada associacao\n");
        printf("[2] Estatisticas da percentagem de inscricoes por escola\n");
        printf("[3] Estatisticas do valor total das inscricoes entre duas datas por tipo de atividade\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida\n");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função do Menu de saída -----------------//
char menu_saida(void) {
    char opcao;
    do {

        printf("Pretende sair? 'S'im ou 'N'ao: ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        if (opcao != 'S' && opcao != 'N')
            printf("Opcao invalida\n");
    } while (opcao != 'S' && opcao != 'N');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função para Registar os Participantes -----------------//
void regista_participante(t_participante participantes[], int* posicao, int* quantidade_participantes_por_adicionar) {
    int pos_aux = *posicao;
    if (pos_aux < NUMERO_MAXIMO_ESTUDANTES - 1) {
        participantes[*posicao].identificador = *posicao;

        strcpy(participantes[*posicao].nome, le_nome());
        fflush(stdin);
        strcpy(participantes[*posicao].escola, devolve_escola());
        fflush(stdin);
        strcpy(participantes[*posicao].nif, le_nif(participantes, pos_aux));
        strcpy(participantes[*posicao].email, le_email());
        strcpy(participantes[*posicao].telefone, le_telefone());
        *posicao = pos_aux + 1;
        *quantidade_participantes_por_adicionar += 1;
    }
    else
        printf("O numero maximo de participantes excedido\n");
}
//---------------------------//---------------------------//

//---------- Função para devolver a escola -----------------//
char* devolve_escola() {
    char escolas[5][7] = { "ESTG","ESECS","ESSLEI", "ESAD", "ESTM" };
    static char escola_escolhida[7];
    int numero_escola;
    do {
        fflush(stdin);
        printf("Intoduza a escola do participante \n1-ESTG \n2-ESECS\n3-ESSLEI\n4-ESAD\n5-ESTM\n\t--> ");
        scanf("%d", &numero_escola);
        if (numero_escola < 0 || numero_escola>5)
            printf("Escolha invalida\n");
        else
            strcpy(escola_escolhida, escolas[numero_escola - 1]);
    } while (numero_escola < 0 || numero_escola>5);
    return escola_escolhida;
}
//---------------------------//---------------------------//

//---------- Função para devolver a associação -----------------//
char* devolve_associacao() {
    char associacao[5][10] = { "AE-ESTG","AE-ESECS","AE-ESSLEI", "AE-ESAD", "AE-ESTM" };
    static char associacao_escolhida[7];
    int numero_associacao;
    do {
        fflush(stdin);
        printf("Introduza o associacao da atividade: \n1 - AE-ESTG \n2 - AE-ESECS\n3 - AE-ESSLEI\n4 - AE-ESAD\n5 - AE-ESTM\n\t--> ");
        scanf("%d", &numero_associacao);
        if (numero_associacao < 0 || numero_associacao>5)
            printf("Escolha invalida");
        else
            strcpy(associacao_escolhida, associacao[numero_associacao - 1]);
    } while (numero_associacao < 0 || numero_associacao>5);
    return associacao_escolhida;
}
//---------------------------//---------------------------//

//---------- Função para devolver o tipo da atividade -----------------//
char* devolve_tipo_atividade() {
    char tipo_atividade[6][11] = { "Academica", "Lazer","Cultura","Desporto","Formacao","Outra" };
    static char tipo_atividade_escolhida[7];
    int numero_tipo_atividade;
    do {
        fflush(stdin);
        printf("Introduza o tipo da atividade: \n1 - Academica \n2 - Lazer\n3 - Cultura\n4 - Desporto\n5 - Formacao\n6 - Outra\n\t--> ");
        scanf("%d", &numero_tipo_atividade);
        if (numero_tipo_atividade < 0 || numero_tipo_atividade>6)
            printf("Escolha invalida");
        else
            strcpy(tipo_atividade_escolhida, tipo_atividade[numero_tipo_atividade - 1]);
    } while (numero_tipo_atividade < 0 || numero_tipo_atividade>6);
    return tipo_atividade_escolhida;
}
//---------------------------//---------------------------//

//---------- Função para Registar as Atividades -----------------//
void regista_atividade(t_atividade atividades[], int* posicao, int* quantidade_atividades_por_adicionar) {
    int pos_aux = *posicao;
    if (pos_aux < NUMERO_MAXIMO_ATIVIDADES - 1) {
        atividades[*posicao].identificador = *posicao;
        strcpy(atividades[*posicao].nome, le_nome_atividade());
        fflush(stdin);
        atividades[*posicao].data = le_data();
        fflush(stdin);
        atividades[*posicao].hora = le_hora();
        fflush(stdin);
        strcpy(atividades[*posicao].local, le_local());
        fflush(stdin);
        strcpy(atividades[*posicao].tipo, devolve_tipo_atividade());
        fflush(stdin);
        strcpy(atividades[*posicao].associacao, devolve_associacao());
        atividades[*posicao].valor_inscricao = le_valor_atividade();
        *posicao = pos_aux + 1;
        *quantidade_atividades_por_adicionar += 1;
    }
    else
        printf("O numero maximo de atividades excedido\n");
}
//---------------------------//---------------------------//

//---------- Função para Registar as Inscrições -----------------//
void regista_inscricao(t_inscricao inscricoes[], t_atividade atividades[], int* posicao, int posicao_participantes, int posicao_atividade, int* quantidade_inscricoes_por_adicionar) {
    int pos_aux = *posicao;
    if (pos_aux < NUMERO_MAXIMO_INSCRICOES - 1) {
        if (posicao_atividade == 0 || posicao_participantes == 0) {
            printf("Nao existe atividades ou participantes para realizar uma inscricao");
            getchar();
        }
        else {
            inscricoes[*posicao].identificador = *posicao;
            mostra_participante(posicao_participantes);
            printf("\nIntroduza o ID do participante: ");
            inscricoes[*posicao].identificador_participante = le_numero_intervalo(0, posicao_participantes - 1);
            valida_indentificadores_participantes_atividades(inscricoes, pos_aux, posicao_atividade);
            inscricoes[*posicao].valor_pago = le_valor_pago(atividades, inscricoes[*posicao].identificador_atividade);
            inscricoes[*posicao].data = valida_data_inscricao(atividades, inscricoes[*posicao].identificador_atividade);
            fflush(stdin);
            inscricoes[*posicao].hora = valida_hora_inscricao(atividades, inscricoes[*posicao].identificador_atividade, atividades[inscricoes[*posicao].identificador_atividade].data);
            *posicao = pos_aux + 1;
            *quantidade_inscricoes_por_adicionar += 1;
        }
    }
    else
        printf("O numero maximo de inscricoes excedido\n");
}
//Funcao valida se o participante já esá registado na atividade inscrita
void valida_indentificadores_participantes_atividades(t_inscricao inscricoes[], int posicao, int posicao_atividade) {
    int posicao_aux = 0, aux = 0;
    do {
        aux = 0;
        mostra_atividade(posicao_atividade);
        printf("\nIntroduza o ID da atividade: ");
        inscricoes[posicao].identificador_atividade = le_numero_intervalo(0, posicao_atividade - 1);
        for (int i = 0;i < posicao;i++) {
            if ((inscricoes[i].identificador_participante == inscricoes[posicao].identificador_participante)) {
                posicao_aux = i;
                if (inscricoes[posicao].identificador_atividade == inscricoes[posicao_aux].identificador_atividade) {
                    printf("\n-----O participante ja esta registado na atividade inscrita!-------\n");
                    aux = 1;
                }
            }
        }
    } while (aux == 1);
}
//---------- Função para Guardar os Participantes no ficheiro -----------------//
void guarda_participantes_ficheiro(t_participante participantes[], int* quantidade_participantes_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen(FICHEIRO_PARTICIPANTES, "ab");
    aux_posicao = posicao - *quantidade_participantes_por_adicionar;
    if (*quantidade_participantes_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {
            fwrite(&participantes[i], sizeof(t_participante), 1, fp);
        }
        printf("Participantes guardados no ficheiro com sucesso.\n");
        *quantidade_participantes_por_adicionar = 0;
    }
    else {
        printf("Nao existem participantes novos para guardar no ficheiro\n");
    }
    fclose(fp);
}

//---------- Função para Guardar as Atividades no ficheiro -----------------//
void guarda_atividades_ficheiro(t_atividade atividades[], int* quantidade_atividades_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen(FICHEIRO_ATIVIDADES, "ab");
    aux_posicao = posicao - *quantidade_atividades_por_adicionar;
    if (*quantidade_atividades_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {
            fwrite(&atividades[i], sizeof(t_atividade), 1, fp);
        }
        printf("Atividades guardadas no ficheiro com sucesso.\n");
        *quantidade_atividades_por_adicionar = 0;
    }
    else {
        printf("Nao existem atividades novas para guardar no ficheiro!\n");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

//---------- Função para Guardar as Inscricoes no ficheiro -----------------//
void guarda_inscricoes_ficheiro(t_inscricao inscricoes[], int* quantidade_inscricoes_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen(FICHEIRO_INSCRICOES, "ab");
    aux_posicao = posicao - *quantidade_inscricoes_por_adicionar;
    if (*quantidade_inscricoes_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {
            fwrite(&inscricoes[i], sizeof(t_inscricao), 1, fp);
        }
        printf("Inscricoes guardadas no ficheiro com sucesso.\n");
        *quantidade_inscricoes_por_adicionar = 0;
    }
    else {
        printf("Nao existem inscricoes novas para guardar no ficheiro!\n");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

//---------- Função para Mostrar os Particpantes que já foram guardados (Consultar participantes) -----------------//
void mostra_participante(int posicao) {
    FILE* fp;
    t_participante participantes[NUMERO_MAXIMO_ESTUDANTES];


    fp = fopen(FICHEIRO_PARTICIPANTES, "rb");
    printf("\n*Para visualizar os registos adicionados e necessario guardar dados no ficheiro\n");
    if (fp == NULL)
        printf("Nenhum registo de participantes");
    else {


        for (int i = 0; i < posicao; i++) {
            fread(&participantes[i], sizeof(t_participante), 1, fp);
        }
        mostra_lista_paginada_participantes(posicao, participantes);
    }
    fclose(fp);
}
//funcao mostra lista paginada dos paticipantes
void mostra_lista_paginada_participantes(int posicao, t_participante participantes[]) {
    int paginas, paginas_restantes, pagina_escolhida;
    char nomes_campos[6][15] = { "ID", "Nome", "Escola", "NIF", "Email", "Telefone" };
    do {
        paginas = (posicao / 10) + 1;
        paginas_restantes = posicao % 10;
        printf("\nQuantidade de registos: %d\nQuatidade de paginas: %d\nINTRODUZA (0) PARA TERMINAR A LISTAGEM \nIntroduza a pagina que desejada visualizar os registos dos participantes: ", posicao, paginas);
        scanf("%d", &pagina_escolhida);
        if (pagina_escolhida != 0) {
            printf("\n%-6s | %-30s | %-7s | %-9s | %-30s | %-9s\n------ | ------------------------------ | ------- | --------- | ------------------------------ | ---------\n", nomes_campos[0], nomes_campos[1], nomes_campos[2], nomes_campos[3], nomes_campos[4], nomes_campos[5]);
            for (int i = 10 * (pagina_escolhida - 1); i < 10 * pagina_escolhida; i++) {
                printf("%-6d | %-30s | %-7s | %-9s | %-30s | %-9s\n", participantes[i].identificador, participantes[i].nome, participantes[i].escola, participantes[i].nif, participantes[i].email, participantes[i].telefone);
            }
        }

    } while (pagina_escolhida != 0);
}
//---------- Função para Mostrar as Atividades que já foram guardadas (Consultar atividades) -----------------//
void mostra_atividade(int posicao) {
    FILE* fp;
    t_atividade atividades[NUMERO_MAXIMO_ATIVIDADES];

    fp = fopen(FICHEIRO_ATIVIDADES, "rb");
    printf("\n*Para visualizar os registos adicionados e necessario guardar dados no ficheiro\n");
    if (fp == NULL)
        printf("Nenhum registo de atividades");
    else {
        for (int i = 0; i < posicao; i++) {
            fread(&atividades[i], sizeof(t_atividade), 1, fp);
        }
        mostra_lista_paginada_atividades(posicao, atividades);
    }fclose(fp);
}
void mostra_lista_paginada_atividades(int posicao, t_atividade atividades[]) {
    char nomes_campos[8][15] = { "ID", "Nome", "Data", "Hora", "Local", "Tipo", "Associacao","Valor" };
    int paginas, paginas_restantes, pagina_escolhida;
    do {
        paginas = (posicao / 10) + 1;
        paginas_restantes = posicao % 10;
        printf("Quantidade de registos: %d\nQuatidade de paginas: %d\nINTRODUZA (0) PARA TERMINAR A LISTAGEM \nIntroduza a pagina que desejada visualizar os registos das atividades: ", posicao, paginas);
        scanf("%d", &pagina_escolhida);
        if (pagina_escolhida != 0) {
            printf("\n%-4s | %-30s | %-10s | %-5s | %-20s | %-10s | %-10s | %-7s\n---- | ------------------------------ | ---------- | ----- | -------------------- | ---------- | ---------- | -----\n", nomes_campos[0], nomes_campos[1], nomes_campos[2], nomes_campos[3], nomes_campos[4], nomes_campos[5], nomes_campos[6], nomes_campos[7]);
            for (int i = 10 * (pagina_escolhida - 1); i < 10 * pagina_escolhida; i++) {
                printf("%-4d | %-30s | %02d-%02d-%04d | %02d:%02d | %-20s | %-10s | %-10s | %-7.2f\n", atividades[i].identificador, atividades[i].nome, atividades[i].data.dia, atividades[i].data.mes, atividades[i].data.ano, atividades[i].hora.horas, atividades[i].hora.minutos, atividades[i].local, atividades[i].tipo, atividades[i].associacao, atividades[i].valor_inscricao);
            }
        }
    } while (pagina_escolhida != 0);
}

//---------- Função para Mostrar as Inscrições que já foram guardadas (Consultar inscricoes) -----------------//
void mostra_inscricao(int posicao) {
    FILE* fp;
    t_inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES];

    fp = fopen(FICHEIRO_INSCRICOES, "rb");
    printf("\n*Para visualizar os registos adicionados e necessario guardar dados no ficheiro\n");
    if (fp == NULL)
        printf("Nenhum registo de inscricoes");
    else {

        for (int i = 0; i < posicao; i++) {
            fread(&inscricoes[i], sizeof(t_inscricao), 1, fp);
        }
        mostra_lista_paginada_inscricoes(posicao, inscricoes);
    }
    fclose(fp);
}
void mostra_lista_paginada_inscricoes(int posicao, t_inscricao inscricoes[]) {
    char nomes_campos[6][16] = { "ID", "ID Participante", "ID Atividade", "Valor Pago", "Data", "Hora" };
    int paginas, paginas_restantes, pagina_escolhida;

    do {
        paginas = (posicao / 10) + 1;
        paginas_restantes = posicao % 10;
        printf("Quantidade de registos: %d\nQuatidade de paginas: %d\nINTRODUZA (0) PARA TERMINAR A LISTAGEM \nIntroduza a pagina que desejada visualizar os registos das inscricoes: ", posicao, paginas);
        scanf("%d", &pagina_escolhida);
         if (pagina_escolhida != 0) {
        printf("\n%-6s | %-15s | %-12s | %-10s | %-10s | %-8s\n------ | --------------- | ------------ | ---------- | ---------- | --------\n", nomes_campos[0], nomes_campos[1], nomes_campos[2], nomes_campos[3], nomes_campos[4], nomes_campos[5]);

        for (int i = 10 * (pagina_escolhida - 1); i < 10 * pagina_escolhida; i++) {
            printf("%-6d | %-15d | %-12d | %-10.2f | %02d-%02d-%04d | %02d:%02d:%02d\n", inscricoes[i].identificador, inscricoes[i].identificador_participante, inscricoes[i].identificador_atividade, inscricoes[i].valor_pago, inscricoes[i].data.dia, inscricoes[i].data.mes, inscricoes[i].data.ano, inscricoes[i].hora.horas, inscricoes[i].hora.minutos, inscricoes[i].hora.segundos);
        }
         }
    } while (pagina_escolhida != 0);


}

//---------- Função que coloca os dados dos Participantes no ficheiro de "particpantes.bin" -----------------//
void preenche_participantes(t_participante participantes[], int posicao) {
    FILE* fp;
    fp = fopen(FICHEIRO_PARTICIPANTES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    }
    else {
        for (int i = 0; i < posicao; i++) {
            fread(&participantes[i], sizeof(t_participante), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que coloca os dados das Atividades no ficheiro de "atividades.bin" -----------------//
void preenche_atividades(t_atividade atividades[], int posicao) {
    FILE* fp;
    fp = fopen(FICHEIRO_ATIVIDADES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    }
    else {
        for (int i = 0; i < posicao; i++) {
            fread(&atividades[i], sizeof(t_atividade), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que coloca os dados das Inscrições no ficheiro de "inscricoes.bin" -----------------//
void preenche_inscricoes(t_inscricao inscricoes[], int posicao) {
    FILE* fp;
    fp = fopen(FICHEIRO_INSCRICOES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    }
    else {
        for (int i = 0; i < posicao; i++) {
            fread(&inscricoes[i], sizeof(t_inscricao), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que devolve a última posição no ficheiro "participantes.bin" -----------------//
int obter_ultima_posicao_participantes(void) {
    FILE* fp;
    t_participante participantes;
    int ultima_pos = 0;
    fp = fopen(FICHEIRO_PARTICIPANTES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    }
    else {
        while ((fread(&participantes, sizeof(t_participante), 1, fp) == 1)) {
            //  printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, participantes.identificador, participantes.nome, participantes.escola, participantes.nif, participantes.email, participantes.telefone);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}

//---------- Função que devolve a última posição no ficheiro "atividades.bin" -----------------//
int obter_ultima_posicao_atividades(void) {
    FILE* fp;
    t_atividade atividades;
    int ultima_pos = 0;
    fp = fopen(FICHEIRO_ATIVIDADES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    }
    else {
        while ((fread(&atividades, sizeof(t_atividade), 1, fp) == 1)) {
            //  printf("%d - %d, %s, %s, %s, %s, %s, %s, %s\n", ultima_pos, atividades.identificador, atividades.nome, atividades.data, atividades.hora, atividades.local, atividades.tipo, atividades.associacao, atividades.valor_inscricao);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}
//---------------------------//---------------------------//

//---------- Função que devolve a última posição no ficheiro "inscricoes.bin" -----------------//
int obter_ultima_posicao_inscricoes(void) {
    FILE* fp;
    t_inscricao inscricoes;

    int ultima_pos = 0;
    fp = fopen(FICHEIRO_INSCRICOES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    }
    else {
        while ((fread(&inscricoes, sizeof(t_inscricao), 1, fp) == 1)) {
            // printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, inscricoes.identificador, inscricoes.identificador_participante, inscricoes.identificador_atividade, inscricoes.valor_pago, inscricoes.data, inscricoes.hora);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}
//---------------------------//---------------------------//

//---------- Função para validar um intervalo de números inteiros -----------------//
int le_numero_intervalo(int min, int max) {
    int numero;
    do {
        scanf("%d", &numero);
        if (numero < min)
            printf("Introduza uma numero entre %d e %d\n", min, max);
        else if (numero > max)
            printf("Introduza uma numero entre %d e %d\n", min, max);
    } while (numero<min || numero>max);
    return numero;
}
//---------------------------//---------------------------//

//---------- Função para validar o nome introduzido -----------------//
char* le_nome(void) {
    static char nome[TAMANHO_NOME + 1];
    do {
        printf("Introduza o nome: ");
        gets(nome);

        if (strlen(nome) > TAMANHO_NOME || strlen(nome) < 3)
            printf("O tamanho do nome nao deve ser maior que %d nem menor que 3\n", TAMANHO_NOME);
    } while (strlen(nome) > TAMANHO_NOME || strlen(nome) < 3);

    return nome;
}
//---------------------------//---------------------------//

//---------- Função para validar o nome da atividade introduzida -----------------//
char* le_nome_atividade(void) {
    static char nome[TAMANHO_NOME_ATIVIDADE + 1];
    do {
        printf("Introduza o nome da atividade: ");
        //scanf("%s[^\n]", &nome);
        gets(nome);

        if (strlen(nome) > TAMANHO_NOME_ATIVIDADE || strlen(nome) < 3)
            printf("O tamanho do nome nao deve ser maior que %d nem menor que 3\n", TAMANHO_NOME_ATIVIDADE);
    } while (strlen(nome) > TAMANHO_NOME_ATIVIDADE || strlen(nome) < 3);

    return nome;
}
//---------------------------//---------------------------//

//---------- Função para validar o email introduzido -----------------//
char* le_email(void) {
    static char email[TAMANHO_EMAIL + 1];
    int aux = 0;
    do {
        aux = 0;
        printf("Introduza o email do participante: ");
        gets(email);
        if (strlen(email) > TAMANHO_EMAIL || strlen(email) < 10) {
            printf("O tamanho do email nao deve ser maior que %d nem menor que 10\n", TAMANHO_NOME);
            aux = 1;

        }
        else if (strstr(email, "@") == NULL) {
            printf("O email nao contem @\n");
            aux = 1;
        }
    } while (aux == 1);
    return email;
}
//---------------------------//---------------------------//

//---------- Função para validar o NIF em termos de comprimento e de caracteres indesejados e também valida se o NIF é único -----------------//
char* le_nif(t_participante participantes[], int posicao) {
    static char nif[10];
    int aux = 0;
    do {
        aux = 0;
        printf("Introduza o nif do participante: ");
        gets(nif);
        for (int j = 0;j < posicao;j++) {
            if (strcmp(nif, participantes[j].nif) == 0) {
                printf("NIF ja existente\n");
                aux = 1;
            }
        }
        for (int i = 0; i < sizeof(nif) - 1; i++) {
            if (!isdigit(nif[i]) && aux != 1) {
                printf("NIF invalido\n");
                aux = 1;
            }
        }
        if (strlen(nif) != 9 && aux != 1) {
            printf("NIF invalido\n");
            aux = 1;
        }
    } while (aux == 1);
    return nif;
}
//---------------------------//---------------------------//

//---------- Função para validar o número de telefone introduzido em termos de comprimento e de  -----------------//
char* le_telefone(void) {
    static char  telefone[10];
    int aux = 0;
    do {
        aux = 0;
        printf("Introduza o telefone do participante: ");
        gets(telefone);
        for (int i = 0; i < sizeof(telefone) - 1; i++) {
            if (!isdigit(telefone[i]) && aux != 1) {
                printf("Numero de telefone invalido\n");
                aux = 1;
            }
        }
        if (strlen(telefone) != 9 && aux != 1) {
            printf("Numero de telefone invalido\n");
            aux = 1;
        }
    } while (aux == 1);
    return telefone;
}
//---------- Função para validar o número de telefone introduzido -----------------//
int valida_dia(int dia, int mes) {
    int aux = 0;
    if ((!(dia >= 1 && dia <= 31) && !(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) && (!(dia >= 1 && dia <= 30) && !(mes == 4 || mes == 6 || mes == 9 || mes == 11)) && (!(dia >= 1 && dia <= 28) && !(mes == 2))) {
        aux = 1;
        printf("Dia invalido\n");
    }
    return aux;
}
//---------- Função para validar o mês introduzido -----------------//
int valida_mes(int mes) {
    int aux = 0;
    if (!(mes >= 1 && mes <= 12)) {
        aux = 1;
        printf("Mes invalido\n");
    }
    return aux;
}
//---------- Função para validar o ano introduzido -----------------//
int valida_ano(int ano) {
    int aux = 0;
    if (!(ano > 2000 && ano < 3000)) {
        aux = 1;
        printf("Ano invalido\n");
    }
    return aux;
}

//---------- Função para validar as horas introduzidas -----------------//
int valida_horas(int hora) {
    int aux = 0;
    if (!(hora <= 23 && hora >= 0)) {
        printf("Horas invalidas\n");
        aux = 1;
    }
    return aux;


}
//---------- Função para validar os minutos introduzidos -----------------//
int valida_minutos(int minutos) {
    int aux = 0;
    if (!(minutos >= 0 && minutos <= 59)) {
        printf("Minutos invalidos\n");
        aux = 1;
    }
    return aux;
}
//---------- Função para validar os segundos introduzidos -----------------//
int valida_segundos(int segundos) {
    int aux = 0;
    if (!(segundos >= 0 && segundos <= 59)) {
        printf("Segundos invalidos\n");
        aux = 1;
    }
    return aux;
}
//---------- Função para validar o formato da hora introduzida -----------------//
int valida_formato_hora(int check) {
    int aux = 0;
    if (check != 2) {
        printf("Formato invalido\n");
        aux = 1;
    }
    return aux;
}
//---------- Função para validar o formato da data introduzida -----------------//
int valida_formato_data(int check) {
    int aux = 0;
    if (check != 3) {
        printf("Formato invalido\n");
        aux = 1;
    }
    return aux;
}
//---------------------------//---------------------------//
//---------- Função para ler a data introduzida no formato (DD-MM-YYYY) -----------------//
t_data le_data(void) {
    t_data data;
    //static char data_formatada[11];
    int aux = 0, aux_dia = 0, aux_mes = 0, aux_ano = 0, check;
    do {
        aux_dia = 0;
        aux_mes = 0;
        aux_ano = 0;
        aux = 0;
        printf("Introduza a data no seguinte formato (DD-MM-YYYY): ");
        check = scanf("%d-%d-%d", &data.dia, &data.mes, &data.ano);
        aux = valida_formato_data(check);
        aux_mes = valida_mes(data.mes);
        aux_dia = valida_dia(data.dia, data.mes);
        aux_ano = valida_ano(data.ano);
        fflush(stdin);
    } while (aux_mes == 1 || aux_ano == 1 || aux_dia == 1 || aux == 1);
    return data;
}

//---------- Função para ler as horas introduzidas no formato (hh:mm) -----------------//
t_hora le_hora(void) {
    t_hora hora;
    int aux = 0, check, aux_horas = 0, aux_minutos = 0;
    do {
        aux = 0;
        aux_horas = 0;
        aux_minutos = 0;
        printf("Introduza as horas no formato (hh:mm): ");
        check = scanf("%d:%d", &hora.horas, &hora.minutos);
        aux = valida_formato_hora(check);
        aux_horas = valida_horas(hora.horas);
        aux_minutos = valida_minutos(hora.minutos);
        fflush(stdin);
    } while (aux == 1 || aux_horas == 1 || aux_minutos == 1);
    return hora;
}

//---------- Função para ler as horas da incrição introduzida -----------------//
t_hora le_horas_inscricao(void) {
    t_hora hora;
    int aux = 0, check, aux_horas = 0, aux_minutos = 0, aux_segundos = 0;
    do {
        aux = 0;
        aux_horas = 0;
        aux_minutos = 0;
        aux_segundos = 0;
        printf("Introduza as horas da inscricao no formato (hh:mm:ss): ");
        check = scanf("%d:%d:%d", &hora.horas, &hora.minutos, &hora.segundos);
        aux = valida_formato_data(check);
        aux_horas = valida_horas(hora.horas);
        aux_minutos = valida_minutos(hora.minutos);
        aux_segundos = valida_segundos(hora.segundos);
        fflush(stdin);
    } while (aux == 1 || aux_horas == 1 || aux_minutos == 1 || aux_segundos == 1);
    return hora;
}

//---------- Função para ler o local introduzido -----------------//
char* le_local(void) {
    static char local[TAMANHO_LOCAL + 1];
    do {
        printf("Introduza o local da atividade: ");
        gets(local);
        if (strlen(local) > TAMANHO_NOME || strlen(local) < 3)
            printf("O tamanho do local nao deve ser maior que %d nem menor que 3\n", TAMANHO_LOCAL);
    } while (strlen(local) > TAMANHO_NOME || strlen(local) < 3);
    fflush(stdin);
    return local;
}
//---------------------------//---------------------------//

//---------- Função para validar o valor da inscrição introduzida -----------------//
float le_valor_atividade() {
    float valor;
    do {
        printf("Introduza o valor da atividade: ");
        scanf("%f", &valor);
        if (valor < 0)
            printf("O valor nao pode ser negativo\n");
    } while (valor < 0);
    return valor;
}

float le_valor_pago(t_atividade atividades[], int id_atividade) {
    float valor;
    do {
        printf("Introduza o valor pago da inscricao: ");
        scanf("%f", &valor);
        if (valor != atividades[id_atividade].valor_inscricao) {
            printf("O valor nao pode diferente ao valor da atividade\n");
        }
        if (valor < 0)
            printf("O valor nao pode ser negativo\n");
    } while (valor < 0 || valor != atividades[id_atividade].valor_inscricao);
    return valor;
}
//---------------------------//---------------------------//


//---------------------------//---------------------------//

//---------- Função que mostra o número de atividades realizadas por associação -----------------//
void numero_atividades_realizadas_por_associacao(t_atividade atividades[]) {
    int num_atividade_AE_ESTG = 0, num_atividade_AE_ESECS = 0, num_atividade_AE_ESSLEI = 0, num_atividade_AE_ESAD = 0, num_atividade_AE_ESTM = 0, quant_total_atividades = 0;
    quant_total_atividades = obter_ultima_posicao_atividades();
    for (int i = 0; i < quant_total_atividades; i++) {
        if (strcmp(atividades[i].associacao, "AE-ESTG") == 0)
            num_atividade_AE_ESTG++;
        else if (strcmp(atividades[i].associacao, "AE-ESECS") == 0)
            num_atividade_AE_ESECS++;
        else if (strcmp(atividades[i].associacao, "AE-ESSLEI") == 0)
            num_atividade_AE_ESSLEI++;
        else if (strcmp(atividades[i].associacao, "AE-ESAD") == 0)
            num_atividade_AE_ESAD++;
        else if (strcmp(atividades[i].associacao, "AE-ESTM") == 0)
            num_atividade_AE_ESTM++;
    }
    printf("\nAssociacao | Numero de atividades \nAE-ESTG    | %d\nAE-ESECS   | %d\nAE-ESSLEI  | %d\nAE-ESAD    | %d\nAE-ESTM    | %d", num_atividade_AE_ESTG, num_atividade_AE_ESECS, num_atividade_AE_ESSLEI, num_atividade_AE_ESAD, num_atividade_AE_ESTM);
}
//---------------------------//---------------------------//

//---------- Função que mostra a percentagem (%) de inscrições por escola -----------------//
void percentagem_inscricoes_por_escola(t_inscricao inscricoes[], t_participante participantes[]) {
    int num_inscricoes_ESTG = 0, num_inscricoes_ESECS = 0, num_inscricoes_ESSLEI = 0, num_inscricoes_ESAD = 0, num_inscricoes_ESTM = 0, identificador_participante, quant_total_inscricoes = 0, percentagem_ESTG, percentagem_ESSECS, percentagem_ESSLEI, percentagem_ESAD, percentagem_ESTM;
    quant_total_inscricoes = obter_ultima_posicao_inscricoes();
    for (int i = 0; i < quant_total_inscricoes; i++) {
        identificador_participante = inscricoes[i].identificador_participante;
        if (strcmp(participantes[identificador_participante].escola, "ESTG") == 0)
            num_inscricoes_ESTG++;
        else if (strcmp(participantes[identificador_participante].escola, "ESECS") == 0)
            num_inscricoes_ESECS++;
        else if (strcmp(participantes[identificador_participante].escola, "ESSLEI") == 0)
            num_inscricoes_ESSLEI++;
        else if (strcmp(participantes[identificador_participante].escola, "ESAD") == 0)
            num_inscricoes_ESAD++;
        else if (strcmp(participantes[identificador_participante].escola, "ESTM") == 0)
            num_inscricoes_ESTM++;
    }
    percentagem_ESTG = (num_inscricoes_ESTG * 100) / quant_total_inscricoes;
    percentagem_ESSECS = (num_inscricoes_ESECS * 100) / quant_total_inscricoes;
    percentagem_ESSLEI = (num_inscricoes_ESSLEI * 100) / quant_total_inscricoes;
    percentagem_ESAD = (num_inscricoes_ESAD * 100) / quant_total_inscricoes;
    percentagem_ESTM = (num_inscricoes_ESTM * 100) / quant_total_inscricoes;
    printf("\nEscola  | Percentagem de inscricoes \nESTG    | %d%%\nESECS   | %d%%\nESSLEI  | %d%%\nESAD    | %d%%\nESTM    | %d%%", percentagem_ESTG, percentagem_ESSECS, percentagem_ESSLEI, percentagem_ESAD, percentagem_ESTM);
}
//---------------------------//---------------------------//


//Esta funcao valida o horizonte temporal das datas inseridas e vai buscar todas as inscrições que estiverem nesse horizonte temporal
void valida_horizonte_temporal(t_inscricao inscricoes[], int posicao, t_atividade atividades[]) {
    t_data primeira_data, segunda_data;
    t_inscricao inscricoes_aux[NUMERO_MAXIMO_INSCRICOES], inscricoes_validadas[NUMERO_MAXIMO_INSCRICOES];
    int contador1 = 0, contador2 = 0, aux = 0;

    do {
        printf("Primeira data - ");
        primeira_data = le_data();
        printf("Segunda data - ");
        segunda_data = le_data();
        aux = valida_diferencas_datas(primeira_data, segunda_data);
        if (aux == 1)
            printf("Segunda data menor que a primeira\n");
    } while (aux == 1);
    contador1 = valida_primeira_data_vetor(inscricoes, inscricoes_aux, posicao, primeira_data);
    contador2 = valida_segunda_data_vetor(inscricoes_aux, inscricoes_validadas, contador1, segunda_data);
    mostra_valores_por_tipo_atividade(contador2, inscricoes_validadas, atividades);
}
//Esta funcção mostra a soma dos valores das inscricoes por tipo de ativdade
void mostra_valores_por_tipo_atividade(int contador, t_inscricao inscricoes_validadas[], t_atividade atividades[]) {
    float soma_valor_desporto = 0.0, soma_valor_lazer = 0.0, soma_valor_academica = 0.0, soma_valor_cultura = 0.0, soma_valor_formacao = 0.0, soma_valor_outra = 0.0;
    for (int i = 0;i < contador;i++) {
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Desporto") == 0) {
            soma_valor_desporto += inscricoes_validadas[i].valor_pago;
        }
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Lazer") == 0) {
            soma_valor_lazer += inscricoes_validadas[i].valor_pago;
        }
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Academica") == 0) {
            soma_valor_academica += inscricoes_validadas[i].valor_pago;
        }
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Cultura") == 0) {
            soma_valor_cultura += inscricoes_validadas[i].valor_pago;
        }
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Formacao") == 0) {
            soma_valor_formacao += inscricoes_validadas[i].valor_pago;
        }
        if (strcmp(atividades[inscricoes_validadas[i].identificador_atividade].tipo, "Outra") == 0) {
            soma_valor_outra += inscricoes_validadas[i].valor_pago;
        }
    }
    printf("\nTipo Atividade | Valor Total\n-------------- | -----------\nAcademica      | %-12.2f\nLazer          | %-12.2f\nCultura        | %-12.2f\nDesporto       | %-12.2f\nFormacao       | %-12.2f\nOutra          | %-12.2f\n-------------- | -----------\nTotal          | %.2f", soma_valor_academica, soma_valor_lazer, soma_valor_cultura, soma_valor_desporto, soma_valor_formacao, soma_valor_outra, soma_valor_academica + soma_valor_cultura + soma_valor_desporto + soma_valor_formacao + soma_valor_lazer + soma_valor_outra);
}
//Esta funcção valida se o data_vetor que é a data de cada inscrição é maior que a primeira data do horizonte temporal
int valida_primeira_data_vetor(t_inscricao inscricoes[], t_inscricao inscricoes_aux[], int posicao, t_data data) {
    int cont = 0;
    t_data data_vetor;
    for (int i = 0;i < posicao;i++) {
        data_vetor = inscricoes[i].data;

        if (data_vetor.ano > data.ano) {
            inscricoes_aux[cont] = inscricoes[i];
            cont++;
        }
        else if (data_vetor.ano == data.ano) {
            if (data_vetor.mes >= data.mes) {
                if (data_vetor.dia >= data.dia) {
                    inscricoes_aux[cont] = inscricoes[i];
                    cont++;
                }
            }
        }
    }
    return cont;
}
//Esta função escreve num vetor de inscricoes auxiliar as inscricoes que estão dentro do horizonte temporal e devolve a ultima posicao do vetor auxiliar
int valida_segunda_data_vetor(t_inscricao inscricoes_aux[], t_inscricao inscricoes_validadas[], int posicao, t_data data) {
    int cont = 0;
    t_data data_vetor;
    for (int i = 0;i < posicao;i++) {
        data_vetor = inscricoes_aux[i].data;
        if (data.ano > data_vetor.ano) {
            inscricoes_validadas[cont] = inscricoes_aux[i];
            cont++;
        }
        else if (data.ano == data_vetor.ano) {
            if (data.mes >= data_vetor.mes) {
                if (data.dia >= data_vetor.dia) {
                    inscricoes_validadas[cont] = inscricoes_aux[i];
                    cont++;
                }
            }
        }
    }
    return cont;
}
//Esta função valida a diferença entre duas datas
//e devolve 0 ou 1, 0 significa que a segunda data é maior que a primeira e o 1 é o inverso
int valida_diferencas_datas(t_data primeira_data, t_data segunda_data) {
    int aux = 0;
    if (segunda_data.ano > primeira_data.ano) {
        aux = 0;
    }
    else if (segunda_data.ano == primeira_data.ano) {
        if (segunda_data.mes < primeira_data.mes)
            aux = 1;
        else if (segunda_data.mes >= primeira_data.mes) {
            if (segunda_data.dia < primeira_data.dia)
                aux = 1;
            else if (segunda_data.dia >= primeira_data.dia) {
                aux = 0;
            }
        }
    }
    else {
        aux = 1;
    }
    return aux;
}
//valida e devolve a data da inscricao e verifica se a data inserida é menor do que a data das atividades
t_data valida_data_inscricao(t_atividade atividades[], int posicao) {
    int aux = 0;
    t_data data;
    do {
        aux = 0;
        data = le_data();
        aux = valida_diferencas_datas(data, atividades[posicao].data);
        if (aux == 1)
            printf("A data inserida e superior a data da atividade\n");
    } while (aux == 1);
    return data;
}
// valida e devolve a hora da inscricao se o dia for igual ao da atividade e valida se a hora é maior do que a da atividade
t_hora valida_hora_inscricao(t_atividade atividades[], int posicao, t_data data_inscricao) {
    int aux = 0;
    t_hora hora;
    do {
        aux = 0;
        hora = le_horas_inscricao();
        if (atividades[posicao].data.dia == data_inscricao.dia && atividades[posicao].data.mes == data_inscricao.mes && atividades[posicao].data.ano == data_inscricao.ano) {
            if (hora.horas > atividades[posicao].hora.horas) {
                printf("As horas nao podem ser maiores do que as da atividade\n");
                aux = 1;
            }
            if (hora.horas == atividades[posicao].hora.horas && hora.minutos > atividades[posicao].hora.minutos) {
                printf("Os minutos nao podem ser maiores do que os da atividade\n");
                aux = 1;
            }
            else
                aux = 0;
        }
        else
            aux = 0;
    } while (aux == 1);
    return hora;
}
