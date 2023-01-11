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
    char data[11];
    char hora[6];
    char local[TAMANHO_LOCAL + 1];
    char tipo[12];
    char associacao[11];
    float valorInscricao;
} t_atividade;
//---------------------------//---------------------------//

//---------- typedef struct do Registo das Inscrições -----------------//
typedef struct {
    int identificador;
    int identificadorParticipante;
    int identificadorAtividade;
    float valorPago;
    char data[11];
    char hora[9];
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
void preenche_participantes(t_participante participantes[], int posicao);
void guarda_participantes_ficheiro(t_participante participantes[], int* quantidade_participantes_por_adicionar, int posicao);
int obter_ultima_posicao_participantes(void);
//---------------------------//---------------------------//

//----------Protótipos das funções para Registar as Atividades e Consultar -----------------//
void regista_atividade(t_atividade atividades[], int* posicao, int* quantidade_atividades_por_adicionar);
char* devolve_associacao();
char* devolve_tipo_atividade();
void mostra_atividade(int posicao);
void preenche_atividades(t_atividade atividades[], int posicao);
void guarda_atividades_ficheiro(t_atividade atividades[], int* quantidade_atividades_por_adicionar, int posicao);
int obter_ultima_posicao_atividades(void);
//---------------------------//---------------------------//

//---------- Protótipos das funções para Registar as Incrições e Consultar -----------------//
void regista_inscricao(t_inscricao inscricoes[], int* posicao, int posicao_participantes, int posicao_atividade, int* quantidade_inscricoes_por_adicionar);
void mostra_inscricao(int posicao);
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
void valida_data_maior(void);
//---------------------------//---------------------------//

//---------- Protótipos das funções para a leitura de dados e validações de dados -----------------//
char* le_nome(void);
int le_numero_intrevalo(int min, int max);
char* le_nome_atividade(void);
char* le_email(void);
char* le_nif(void);
char* le_telefone();
int valida_dia(int dia, int mes);
int valida_mes(int mes);
int valida_ano(int ano);
char* le_hora(void);
char* le_horas_inscricao(void);
char* le_data(void);
char* le_local(void);
float le_valor_inscricao(void);
int valida_formato_data_hora(int check);
//---------------------------//---------------------------//

int main() {
    setlocale(LC_ALL, "Portuguese");
    char escolha_menu_principal, escolha_registar, escolha_consultar, escolha_estatistica, escolha_saida;
    int posicao_participantes = 0, posicao_atividades = 0, posicao_inscricoes = 0, quantidade_participantes_por_adicionar = 0, quantidade_atividades_por_adicionar = 0, quantidade_inscricoes_por_adicionar = 0;
    printf("%d", NUMERO_MAXIMO_INSCRICOES);
    t_participante participantes[NUMERO_MAXIMO_ESTUDANTES];
    t_atividade atividades[NUMERO_MAXIMO_ATIVIDADES];
    t_inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES];

    posicao_participantes = obter_ultima_posicao_participantes();
    posicao_atividades = obter_ultima_posicao_atividades();
    posicao_inscricoes = obter_ultima_posicao_inscricoes();
    // posicao = 4;

    do {
        system("cls");
        preenche_participantes(participantes,posicao_participantes);
        preenche_atividades(atividades, posicao_atividades);
        preenche_inscricoes(inscricoes,posicao_inscricoes);
        printf("Posicao Participantes: %d\n", posicao_participantes);
        printf("Posicao Atividades: %d\n", posicao_atividades);
        printf("Posicao Inscricoes: %d\n", posicao_inscricoes);
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
                    regista_inscricao(inscricoes, &posicao_inscricoes, posicao_participantes, posicao_atividades, &quantidade_inscricoes_por_adicionar);
                    fflush(stdin);
                    break;
                case '4'://guardar no ficheiro
                    guarda_participantes_ficheiro(participantes, &quantidade_participantes_por_adicionar, posicao_participantes);
                    guarda_atividades_ficheiro(atividades, &quantidade_atividades_por_adicionar, posicao_atividades);
                    guarda_inscricoes_ficheiro(inscricoes, &quantidade_inscricoes_por_adicionar, posicao_inscricoes);
                    fflush(stdin);
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
                    mostra_participante(posicao_participantes);
                    fflush(stdin);
                    getchar();
                    break;
                case '2':
                    //printf("Consultar os dados das atividades\n");
                    mostra_atividade(posicao_atividades);
                    fflush(stdin);
                    getchar();
                    break;
                case '3':
                    //printf("Consultar os dados das inscricoes\n");
                    mostra_inscricao(posicao_inscricoes);
                    fflush(stdin);
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
                    getchar();
                    break;
                case '2':
                    printf("Estatisticas da percentagem de inscricoes por escola\n");
                    percentagem_inscricoes_por_escola(inscricoes, participantes);
                    fflush(stdin);
                    getchar();
                    break;
                case '3':
                    printf("Estatisticas do valor total das inscricoes entre duas datas por tipo de atividade\n");
                    valida_data_maior();
                    fflush(stdin);
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
            printf("Opcao invalida");
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
            printf("Opcao invalida");
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
            printf("Opcao invalida");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//---------------------------//---------------------------//

//---------- Função do Menu das estatísticas -----------------//
char menu_estatisticas(void) {
    char opcao;
    do {
        printf("*********************** Menu Estatisticas ***********************\n \n");
        printf("[1] Estatisticas do numero de atividades realizadas por cada associacao\n");
        printf("[2] Estatisticas da percentagem de inscricoes por escola\n");
        printf("[3] Estatisticas do valor total das inscricoes entre duas datas por tipo de atividade\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida");
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
}
//---------------------------//---------------------------//

//---------- Função para Registar os Participantes -----------------//
void regista_participante(t_participante participantes[], int* posicao, int* quantidade_participantes_por_adicionar) {
    int pos_aux = *posicao, numero_escola;
    char escolas[5][7] = { "ESTG","ESECS","ESSLEI", "ESAD", "ESTM" };
    printf("Posicao_aux do array: %d\n", pos_aux);
    participantes[*posicao].identificador = *posicao;

    strcpy(participantes[*posicao].nome, le_nome());
    fflush(stdin);
    strcpy(participantes[*posicao].escola, devolve_escola());
    strcpy(participantes[*posicao].nif, le_nif());
    strcpy(participantes[*posicao].email, le_email());
    strcpy(participantes[*posicao].telefone, le_telefone());
    *posicao = pos_aux + 1;
    *quantidade_participantes_por_adicionar += 1;
}
//---------------------------//---------------------------//

//---------- Função para devolver a escola -----------------//
char* devolve_escola() {
    char escolas[5][7] = { "ESTG","ESECS","ESSLEI", "ESAD", "ESTM" };
    static char escola_escolhida[7];
    int numero_escola;
    do {
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
        printf("Introduza o associacao da atividade: \n1 - AE-ESTG \n2 - AE-ESECS\n3 - AE-ESSLEI\n4 - AE-ESAD\n5 - AE-ESTM\n\t--> ");
        scanf("%d", &numero_associacao);
        if (numero_associacao < 0 && numero_associacao>5)
            printf("Escolha invalida");
        else
            strcpy(associacao_escolhida, associacao[numero_associacao - 1]);
    } while (numero_associacao < 0 && numero_associacao>5);
    return associacao_escolhida;
}
//---------------------------//---------------------------//

//---------- Função para devolver o tipo da atividade -----------------//
char* devolve_tipo_atividade() {
    char tipo_atividade[6][11] = { "Academica", "Lazer","Cultura","Desporto","Formacao","Outra" };
    static char tipo_atividade_escolhida[7];
    int numero_tipo_atividade;
    do {
        printf("Introduza o tipo da atividade: \n1 - Academica \n2 - Lazer\n3 - Cultura\n4 - Desporto\n5 - Formacao\n6 - Outra\n\t--> ");
        scanf("%d", &numero_tipo_atividade);
        if (numero_tipo_atividade < 0 && numero_tipo_atividade>6)
            printf("Escolha invalida");
        else
            strcpy(tipo_atividade_escolhida, tipo_atividade[numero_tipo_atividade - 1]);
    } while (numero_tipo_atividade < 0 && numero_tipo_atividade>6);
    return tipo_atividade_escolhida;
}
//---------------------------//---------------------------//

//---------- Função para Registar as Atividades -----------------//
void regista_atividade(t_atividade atividades[], int* posicao, int* quantidade_atividades_por_adicionar) {
    int pos_aux = *posicao;

    atividades[*posicao].identificador = *posicao;
    strcpy(atividades[*posicao].nome, le_nome_atividade());
    fflush(stdin);
    strcpy(atividades[*posicao].data, le_data());
    fflush(stdin);
    strcpy(atividades[*posicao].hora, le_hora());
    fflush(stdin);
    strcpy(atividades[*posicao].local, le_local());

    strcpy(atividades[*posicao].tipo, devolve_tipo_atividade());
    strcpy(atividades[*posicao].associacao, devolve_associacao());
    atividades[*posicao].valorInscricao = le_valor_inscricao();
    *posicao = pos_aux + 1;
    *quantidade_atividades_por_adicionar += 1;
}
//---------------------------//---------------------------//

//---------- Função para Registar as Inscrições -----------------//
void regista_inscricao(t_inscricao inscricoes[], int* posicao, int posicao_participantes, int posicao_atividade, int* quantidade_inscricoes_por_adicionar) {
    int pos_aux = *posicao;
    //printf("Posicao_aux do array: %d\n\n", pos_aux);
    inscricoes[*posicao].identificador = *posicao;
    mostra_participante(posicao_participantes);
    printf("\nIntroduza o ID do participante: ");
    inscricoes[*posicao].identificadorParticipante = le_numero_intrevalo(0, posicao_participantes);
    mostra_atividade(posicao_atividade);
    printf("\nIntroduza o ID da atividade: ");
    inscricoes[*posicao].identificadorAtividade = le_numero_intrevalo(0, posicao_atividade);
    inscricoes[*posicao].valorPago = le_valor_inscricao();
    strcpy(inscricoes[*posicao].data, le_data());
    strcpy(inscricoes[*posicao].hora, le_horas_inscricao());
    //-----------------------------------------------------------------------------
    //VALIDAR CASO NÃO EXISTA PARTICIPANRES OU ATIVIDADES NAO DAR PARA FAZER NADA
    //-----------------------------------------------------------------------------
    *posicao = pos_aux + 1;
    *quantidade_inscricoes_por_adicionar += 1;
    //printf("Posicao do array: %d\n", *posicao);
    //printf("Quantidade de inscricoes por adicionar: %d\n", *quantidade_inscricoes_por_adicionar);
}
//---------------------------//---------------------------//

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
    } else {
        printf("Nao existem participantes novos para guardar no ficheiro\n");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

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
    } else {
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
    } else {
        printf("Nao existem inscricoes novas para guardar no ficheiro!\n");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

//---------- Função para Mostrar os Particpantes que já foram guardados (Consultar participantes) -----------------//
void mostra_participante(int posicao) {
    FILE* fp;
    t_participante participantes[NUMERO_MAXIMO_ESTUDANTES];
    int paginas, paginas_restantes, pagina_escolhida;
    char nomes_campos[6][15] = { "ID", "Nome", "Escola", "NIF", "Email", "Telefone" };
    fp = fopen(FICHEIRO_PARTICIPANTES, "rb");
    if (fp == NULL) {
        printf("Nenhum registo de participantes");
    } else {
        //paginas=posicao/10;
        //paginas_restantes = posicao%10;
        //printf("\nQuatidade de paginas: %d\nIntoduza a pagina desejada: ",paginas);
        // scanf("%d", &pagina_escolhida);
        printf("\nQuantidade de registos: %d\n%-6s | %-30s | %-7s | %-9s | %-30s | %-9s\n------ | ------------------------------ | ------- | --------- | ------------------------------ | ---------\n", posicao, nomes_campos[0], nomes_campos[1], nomes_campos[2], nomes_campos[3], nomes_campos[4], nomes_campos[5]);
        for (int i = 0; i < posicao; i++) {
            fread(&participantes[i], sizeof(t_participante), 1, fp);
            //}
            //for (int i = 10*(pagina_escolhida-1); i < 10*pagina_escolhida; i++) {
            printf("%-6d | %-30s | %-7s | %-9s | %-30s | %-9s\n", participantes[i].identificador, participantes[i].nome, participantes[i].escola, participantes[i].nif, participantes[i].email, participantes[i].telefone);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função para Mostrar as Atividades que já foram guardadas (Consultar atividades) -----------------//
void mostra_atividade(int posicao) {
    FILE* fp;
    t_atividade atividades[NUMERO_MAXIMO_ATIVIDADES];
    char nomes_campos[8][15] = { "ID", "Nome", "Data", "Hora", "Local", "Tipo", "Associacao","Valor" };

    fp = fopen(FICHEIRO_ATIVIDADES, "rb");
    if (fp == NULL) {
        printf("Nenhum registo de atividades");
    } else {
        printf("\nQuantidade de registos: %d\n%-4s | %-30s | %-10s | %-5s | %-20s | %-10s | %-10s | %-7s\n", posicao, nomes_campos[0], nomes_campos[1], nomes_campos[2], nomes_campos[3], nomes_campos[4], nomes_campos[5], nomes_campos[6], nomes_campos[7]);
        for (int i = 0; i < posicao; i++) {
            fread(&atividades[i], sizeof(t_atividade), 1, fp);
            printf("%-4d | %-30s | %-10s | %-5s | %-20s | %-10s | %-10s | %-7.2f\n", atividades[i].identificador, atividades[i].nome, atividades[i].data, atividades[i].hora, atividades[i].local, atividades[i].tipo, atividades[i].associacao, atividades[i].valorInscricao);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função para Mostrar as Inscrições que já foram guardadas (Consultar inscricoes) -----------------//
void mostra_inscricao(int posicao) {
    FILE* fp;
    t_inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES];
    fp = fopen(FICHEIRO_INSCRICOES, "rb");
    if (fp == NULL) {
        printf("Nenhum registo de inscricoes");
    } else {
        for (int i = 0; i < posicao; i++) {
            fread(&inscricoes[i], sizeof(t_inscricao), 1, fp);
            printf("%d, %d, %d, %.2f, %s, %s\n", inscricoes[i].identificador, inscricoes[i].identificadorParticipante, inscricoes[i].identificadorAtividade, inscricoes[i].valorPago, inscricoes[i].data, inscricoes[i].hora);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que coloca os dados dos Participantes no ficheiro de "particpantes.bin" -----------------//
void preenche_participantes(t_participante participantes[], int posicao) {
    FILE* fp;
    fp = fopen(FICHEIRO_PARTICIPANTES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    } else {
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
    } else {
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
    } else {
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
    } else {
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
    } else {
        while ((fread(&atividades, sizeof(t_atividade), 1, fp) == 1)) {
            //  printf("%d - %d, %s, %s, %s, %s, %s, %s, %s\n", ultima_pos, atividades.identificador, atividades.nome, atividades.data, atividades.hora, atividades.local, atividades.tipo, atividades.associacao, atividades.valorInscricao);
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
    } else {
        while ((fread(&inscricoes, sizeof(t_inscricao), 1, fp) == 1)) {
            // printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, inscricoes.identificador, inscricoes.identificadorParticipante, inscricoes.identificadorAtividade, inscricoes.valorPago, inscricoes.data, inscricoes.hora);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}
//---------------------------//---------------------------//

//---------- Função para validar um intervalo de números inteiros -----------------//
int le_numero_intrevalo(int min, int max) {
    int numero;
    do {
        scanf("%d", &numero);
        if (numero < min)
            printf("Introduza uma numero entre %d e %d", min, max);
        else if (numero > max)
            printf("Introduza uma numero entre %d e %d", min, max);
    } while (numero<min && numero>max);
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

        } else if (strstr(email, "@") == NULL) {
            printf("O email nao contem @\n");
            aux = 1;
        }
    } while (aux == 1);
    return email;
}
//---------------------------//---------------------------//

//---------- Função para validar o nif em termos de comprimento e de caracteres indesejados -----------------//
char* le_nif(void) {
    static char  nif[10];
    int aux = 0;
    fflush(stdin);
    do {
        aux = 0;
        printf("Introduza o nif do participante: ");
        gets(nif);
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

//---------- Função para validar o número de telefone introduzido -----------------//
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
//---------------------------//---------------------------//

//---------- Função para validar o número de telefone introduzido -----------------//
int valida_dia(int dia, int mes) {
    int aux = 0;
    if ((!(dia >= 1 && dia <= 31) && !(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) && (!(dia >= 1 && dia <= 30) && !(mes == 4 || mes == 6 || mes == 9 || mes == 11)) && (!(dia >= 1 && dia <= 28) && !(mes == 2))) {
        aux = 1;
        printf("Dia invalido\n");
    }
    return aux;
}
//---------------------------//---------------------------//

//---------- Função para validar o mês introduzido -----------------//
int valida_mes(int mes) {
    int aux = 0;
    if (!(mes >= 1 && mes <= 12)) {
        aux = 1;
        printf("Mes invalido\n");
    }
    return aux;
}
//---------------------------//---------------------------//

//---------- Função para validar o ano introduzido -----------------//
int valida_ano(int ano) {
    int aux = 0;
    if (!(ano > 2000 && ano < 3000)) {
        aux = 1;
        printf("Ano invalido\n");
    }
    return aux;
}
//---------------------------//---------------------------//

//---------- Função para validar a data introduzida no formato (DD-MM-YYYY) -----------------//
char* le_data(void) {
    int dia, mes, ano, aux = 0, aux_dia = 0, aux_mes = 0, aux_ano = 0, check;
    static char data[11];
    do {
        aux_dia = 0;
        aux_mes = 0;
        aux_ano = 0;
        aux = 0;
        printf("Introduza a data no seguinte formato (DD-MM-YYYY): ");
        check = scanf("%d-%d-%d", &dia, &mes, &ano);

        aux = valida_formato_data_hora(check);
        aux_mes = valida_mes(mes);
        aux_dia = valida_dia(dia, mes);
        aux_ano = valida_ano(ano);
        if (aux_mes != 1 || aux_ano != 1 || aux_dia != 1 || aux != 1)
            sprintf(data, "%02d-%02d-%02d", dia, mes, ano);
    } while (aux_mes == 1 || aux_ano == 1 || aux_dia == 1 || aux == 1);
    return data;
}
//---------------------------//---------------------------//

//---------- Função para validar o formato da data introduzida -----------------//
int valida_formato_data_hora(int check) {
    int aux = 0;
    if (check != 3 && check != 2) {
        //printf("check: %d",check);
        printf("Formato invalido\n");
        aux = 1;
    }
    return aux;
}
//---------------------------//---------------------------//

//---------- Função para validar as horas introduzidas no formato (hh:mm) -----------------//
char* le_hora(void) {
    int horas, minutos, aux = 0, check;
    static char hora[5];
    do {
        aux = 0;
        printf("Introduza as horas no formato (hh:mm): ");
        check = scanf("%d:%d", &horas, &minutos);
        aux = valida_formato_data_hora(check);
        if (!(horas <= 23 && horas >= 0)) {
            printf("Horas invalidas");
            aux = 1;
        } else if (!(minutos >= 0 && minutos <= 59)) {
            printf("Minutos invalidos");
            aux = 1;
        }
        if (aux == 0)
            sprintf(hora, "%02d:%02d", horas, minutos);
    } while (aux == 1);
    fflush(stdin);
    return hora;
}
//---------------------------//---------------------------//

//---------- Função para validar as horas da incrição introduzida -----------------//
char* le_horas_inscricao(void) {
    int horas, minutos, segundos, aux = 0, check;
    static char hora[9];
    do {
        aux = 0;
        printf("Introduza as horas da inscricao no formato (hh:mm:ss): ");
        check = scanf("%d:%d:%d", &horas, &minutos, &segundos);
        aux = valida_formato_data_hora(check);
        if (!(horas <= 23 && horas >= 0)) {
            printf("Horas invalidas\n");
            aux = 1;
        } else if (!(minutos >= 0 && minutos <= 59)) {
            printf("Minutos invalidos\n");
            aux = 1;
        } else if (!(segundos >= 0 && segundos <= 59)) {
            printf("Segundos invalidos\n");
            aux = 1;
        }
        if (aux == 0)
            sprintf(hora, "%02d:%02d:%02d", horas, minutos, segundos);
        fflush(stdin);
    } while (aux == 1);
    return hora;
}
//---------------------------//---------------------------//

//---------- Função para validar o local introduzido -----------------//
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
float le_valor_inscricao(void) {
    float valor;
    do {
        printf("Introduza o valor da inscricao da atividade: ");
        scanf("%f", &valor);
        if (valor < 0)
            printf("O valor nao pode ser negativo\n");
    } while (valor < 0);
    return valor;
}
//---------------------------//---------------------------//

//---------- Função que lê o ficheiro das atividades -----------------//
void le_ficheiro_atividades(t_atividade atividades[]) {
    FILE* fp;
    fp = fopen(FICHEIRO_ATIVIDADES, "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    } else {
        for (int i = 0; i < NUMERO_MAXIMO_ATIVIDADES; i++) {
            fread(&atividades[i], sizeof(t_atividade[i]), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que mostra o número de atividades realizadas por associação -----------------//
void numero_atividades_realizadas_por_associacao(t_atividade atividades[]) {
    int num_atividade_AE_ESTG = 0, num_atividade_AE_ESECS = 0, num_atividade_AE_ESSLEI = 0, num_atividade_AE_ESAD = 0, num_atividade_AE_ESTM = 0, quant_total_atividades = 0;
    quant_total_atividades  = obter_ultima_posicao_atividades();
    for(int i=0; i < quant_total_atividades; i++) {
        if(strcmp(atividades[i].associacao, "AE-ESTG") == 0)
            num_atividade_AE_ESTG++;
        else if(strcmp(atividades[i].associacao, "AE-ESECS") == 0)
            num_atividade_AE_ESECS++;
        else if(strcmp(atividades[i].associacao, "AE-ESSLEI") == 0)
            num_atividade_AE_ESSLEI++;
        else if(strcmp(atividades[i].associacao, "AE-ESAD") == 0)
            num_atividade_AE_ESAD++;
        else if(strcmp(atividades[i].associacao, "AE-ESTM") == 0)
            num_atividade_AE_ESTM++;
    }
    printf("\nAssociacao | Numero de atividades \nAE-ESTG    | %d\nAE-ESECS   | %d\nAE-ESSLEI  | %d\nAE-ESAD    | %d\nAE-ESTM    | %d", num_atividade_AE_ESTG, num_atividade_AE_ESECS, num_atividade_AE_ESSLEI, num_atividade_AE_ESAD, num_atividade_AE_ESTM);
}
//---------------------------//---------------------------//

//---------- Função que mostra a percentagem (%) de inscrições por escola -----------------//
void percentagem_inscricoes_por_escola(t_inscricao inscricoes[], t_participante participantes[]) {
    int num_inscricoes_ESTG = 0, num_inscricoes_ESECS = 0, num_inscricoes_ESSLEI = 0, num_inscricoes_ESAD = 0, num_inscricoes_ESTM = 0, identificador_participante, quant_total_inscricoes = 0, percentagem_ESTG, percentagem_ESSECS, percentagem_ESSLEI, percentagem_ESAD, percentagem_ESTM;
    quant_total_inscricoes  = obter_ultima_posicao_inscricoes();
    for(int i=0; i < quant_total_inscricoes; i++) {
        identificador_participante = inscricoes[i].identificadorParticipante;
        if(strcmp(participantes[identificador_participante].escola, "ESTG") == 0)
            num_inscricoes_ESTG++;
        else if(strcmp(participantes[identificador_participante].escola, "ESECS") == 0)
            num_inscricoes_ESECS++;
        else if(strcmp(participantes[identificador_participante].escola, "ESSLEI") == 0)
            num_inscricoes_ESSLEI++;
        else if(strcmp(participantes[identificador_participante].escola, "ESAD") == 0)
            num_inscricoes_ESAD++;
        else if(strcmp(participantes[identificador_participante].escola, "ESTM") == 0)
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


//Se o segundo ano for maior que o primeiro ano, então o mês e o dia podem ser inferiores ao primeiro ano. Ou seja, não precisa de validações.
//Se o segundo ano for igual ao primeiro ano, então verifica-se o mês e o dia do segundo ano.
void valida_data_maior() {
    char datas[2][11], aux_dia[2][2], aux_mes[2][2], aux_ano[2][4];
    int dia[2], mes[2], ano[2];
    strcpy(datas[0],le_data());
    strcpy(datas[1],le_data());

    for(int i=0; i<2; i++) {
        printf("--%d--", i);
        aux_dia[i][0] = datas[i][0];
        aux_dia[i][1] = datas[i][1];
        dia[i] = atoi(aux_dia[i]);

        aux_mes[i][0] = datas[i][3];
        aux_mes[i][1] = datas[i][4];
        mes[i] = atoi(aux_mes[i]);

        aux_ano[i][0] = datas[i][6];
        aux_ano[i][1] = datas[i][7];
        aux_ano[i][2] = datas[i][8];
        aux_ano[i][3] = datas[i][9];
        ano[i] = atoi(aux_ano[i]);

    }
    printf("%d, %d, %d\n", dia[0], mes[0], ano[0]);
    printf("%d, %d, %d\n", dia[1], mes[1], ano[1]);
}
