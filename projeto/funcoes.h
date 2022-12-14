#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#ifndef FUNCOES_H
#define FUNCOES_H

#include "constantes.h"
#include "menus.h"

typedef struct {
    int identificador;
    char nome[31];
    char escola[7];
    char nif[10];
    char email[51];
    char telefone[10];
} participante;

//---------- typedef struct do Registo das Atividades -----------------//
typedef struct {
    int identificador;
    char nome[31];
    char data[11];
    char hora[6];
    char local[21];
    char tipo[21];
    char associacao[10];
    char valorInscricao[6];
} atividade;
//---------------------------//---------------------------//

//---------- typedef struct do Registo das Inscrições -----------------//
typedef struct {
    int identificador;
    char identificadorParticipante[5];
    char identificadorAtividade[4];
    char valorPago[6];
    char data[11];
    char hora[9];
} inscricao;
//---------------------------//---------------------------//

void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* posicao, int* quantidade_participantes_por_adicionar);
void mostra_participante(int posicao);
void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]);
void guarda_participantes_ficheiro(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* quantidade_participantes_por_adicionar, int posicao);
int obter_ultima_posicao_participantes(void);

//---------- Funções para Registar as Atividades e Consultar -----------------//
void regista_atividade(atividade atividades[NUMERO_MAXIMO_ATIVIDADES], int* posicao, int* quantidade_atividades_por_adicionar);
void mostra_atividade(int posicao);
void preenche_atividades(atividade atividades[NUMERO_MAXIMO_ATIVIDADES]);
void guarda_atividades_ficheiro(atividade atividades[NUMERO_MAXIMO_ATIVIDADES], int* quantidade_atividades_por_adicionar, int posicao);
int obter_ultima_posicao_atividades(void);
//---------------------------//---------------------------//

//---------- Funções para Registar as Incrições e Consultar -----------------//
void regista_inscricao(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES], int* posicao, int* quantidade_inscricoes_por_adicionar);
void mostra_inscricao(int posicao);
void preenche_inscricoes(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES]);
void guarda_inscricoes_ficheiro(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES], int* quantidade_inscricoes_por_adicionar, int posicao);
int obter_ultima_posicao_inscricoes(void);
//---------------------------//---------------------------//

void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* posicao, int* quantidade_participantes_por_adicionar) {
    int pos_aux = *posicao;
    char escolas[5][7] = { "ESTG","ESECS","ESSLEI", "ESAD", "ESTM" };
    int numero_escola;

    printf("Posicao_aux do array: %d\n", pos_aux);
    participantes[*posicao].identificador = *posicao;

    printf("Introduza o nome do participante: ");
    scanf("%s", &participantes[*posicao].nome);
    printf("Introduza a escola do participante\n1 - ESTG\n2 - ESECS\n3 - ESSLEI\n4 - ESAD\n5 - ESTM\n --> ");
    scanf("%d", &numero_escola);
    strcpy(participantes[*posicao].escola, escolas[numero_escola - 1]);
    printf("Introduza o nif do participante: ");
    scanf("%s", &participantes[*posicao].nif);
    printf("Introduza o email do participante: ");
    scanf("%s", &participantes[*posicao].email);
    printf("Introduza o telefone do participante: ");
    scanf("%s", &participantes[*posicao].telefone);

    *posicao = pos_aux + 1;
    *quantidade_participantes_por_adicionar += 1;
}

//---------- Função para Registar as Atividades -----------------//
void regista_atividade(atividade atividades[NUMERO_MAXIMO_ATIVIDADES], int* posicao, int* quantidade_atividades_por_adicionar) {
    int pos_aux = *posicao;
    printf("Posicao_aux do array: %d\n\n", pos_aux);
    atividades[*posicao].identificador = *posicao;

    printf("Introduza o nome da atividade: ");
    scanf("%s", &atividades[*posicao].nome);
    printf("Introduza a data da atividade (DD-MM-YYYY): ");
    scanf("%s", &atividades[*posicao].data);
    printf("Introduza a hora da atividade (HH:MM): ");
    scanf("%s", &atividades[*posicao].hora);
    printf("Introduza o local da atividade: ");
    scanf("%s", &atividades[*posicao].local);
    printf("Introduza o tipo da atividade: ");
    scanf("%s", &atividades[*posicao].tipo);
    printf("Introduza o associacao da atividade: ");
    scanf("%s", &atividades[*posicao].associacao);
    printf("Introduza o valor da inscricao da atividade (€): ");
    scanf("%s", &atividades[*posicao].valorInscricao);

    *posicao = pos_aux + 1;
    *quantidade_atividades_por_adicionar += 1;
    printf("Posicao do array: %d\n", *posicao);
    printf("Quantidade de atividades por adicionar: %d\n", *quantidade_atividades_por_adicionar);
}
//---------------------------//---------------------------//

//---------- Função para Registar as Inscrições -----------------//
void regista_inscricao(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES], int* posicao, int* quantidade_inscricoes_por_adicionar) {
    int pos_aux = *posicao;
    printf("Posicao_aux do array: %d\n\n", pos_aux);
    inscricoes[*posicao].identificador = *posicao;

    printf("Introduza o ID do participante: ");
    scanf("%s", &inscricoes[*posicao].identificadorParticipante);
    printf("Introduza o ID da atividade: ");
    scanf("%s", &inscricoes[*posicao].identificadorAtividade);
    printf("Introduza o valor pago (€) da inscricao: ");
    scanf("%s", &inscricoes[*posicao].valorPago);
    printf("Introduza a data da inscricao (DD-MM-YYYY): ");
    scanf("%s", &inscricoes[*posicao].data);
    printf("Introduza o ID da atividade (HH:MM:SS): ");
    scanf("%s", &inscricoes[*posicao].hora);

    *posicao = pos_aux + 1;
    *quantidade_inscricoes_por_adicionar += 1;
    printf("Posicao do array: %d\n", *posicao);
    printf("Quantidade de inscricoes por adicionar: %d\n", *quantidade_inscricoes_por_adicionar);
}
//---------------------------//---------------------------//

void guarda_participantes_ficheiro(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* quantidade_participantes_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen("participantes.bin", "ab");
    aux_posicao = posicao - *quantidade_participantes_por_adicionar;
    if (*quantidade_participantes_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {

            fwrite(&participantes[i], sizeof(participante), 1, fp);

        }
        printf("Participantes guardados no ficheiro com sucesso.");
        *quantidade_participantes_por_adicionar = 0;

    }

    else {
        printf("Não existem participantes novos para guardar no ficheiro");
    }
    fclose(fp);
}

//---------- Função para Guardar as Atividades no ficheiro -----------------//
void guarda_atividades_ficheiro(atividade atividades[NUMERO_MAXIMO_ATIVIDADES], int* quantidade_atividades_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen("atividades.bin", "ab");
    aux_posicao = posicao - *quantidade_atividades_por_adicionar;
    if (*quantidade_atividades_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {
            fwrite(&atividades[i], sizeof(atividade), 1, fp);
        }
        printf("Atividades guardadas no ficheiro com sucesso.");
        *quantidade_atividades_por_adicionar = 0;
    } else {
        printf("Nao existem atividades novas para guardar no ficheiro!");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

//---------- Função para Guardar as Inscrições no ficheiro -----------------//
void guarda_inscricoes_ficheiro(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES], int* quantidade_inscricoes_por_adicionar, int posicao) {
    FILE* fp;
    int aux_posicao;
    fp = fopen("inscricoes.bin", "ab");
    aux_posicao = posicao - *quantidade_inscricoes_por_adicionar;
    if (*quantidade_inscricoes_por_adicionar > 0) {
        for (int i = aux_posicao; i < posicao; i++) {
            fwrite(&inscricoes[i], sizeof(inscricao), 1, fp);
        }
        printf("Inscricoes guardadas no ficheiro com sucesso.");
        *quantidade_inscricoes_por_adicionar = 0;
    } else {
        printf("Nao existem inscricoes novas para guardar no ficheiro!");
    }
    fclose(fp);
}
//---------------------------//---------------------------//

void mostra_participante(int posicao) {


    FILE* fp;
    participante participantes[NUMERO_MAXIMO_ESTUDANTES];
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossível abrir ficheiro");
    } else {



        //printf("%d, %s, %s, %s, %s, %s", participantes[3].identificador, participantes[3].nome, participantes[3].escola, participantes[3].nif, participantes[3].email, participantes[3].telefone);
        for (int i = 0; i < posicao; i++) {
            //if (participantes[i].identificador != 0)
            fread(&participantes[i], sizeof(participante), 1, fp);
            //if (participantes[i].identificador != 0)
            printf("%d - %d, %s, %s, %s, %s, %s\n", i, participantes[i].identificador, participantes[i].nome, participantes[i].escola, participantes[i].nif, participantes[i].email, participantes[i].telefone);


        }
        fclose(fp);
        // printf("Valor lido: %s", participantes);
    }
}

//---------- Função para Mostra as Atividades que já foram guardadas (Consultar atividades) -----------------//
void mostra_atividade(int posicao) {
    FILE* fp;
    atividade atividades[NUMERO_MAXIMO_ATIVIDADES];
    fp = fopen("atividades.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir o ficheiro!");
    } else {
        //printf("%d, %s, %s, %s, %s, %s", participantes[3].identificador, participantes[3].nome, participantes[3].escola, participantes[3].nif, participantes[3].email, participantes[3].telefone);
        for (int i = 0; i < posicao; i++) {
            //if (participantes[i].identificador != 0)
            fread(&atividades[i], sizeof(atividade), 1, fp);
            //if (participantes[i].identificador != 0)
            printf("%d - %d, %s, %s, %s, %s, %s, %s, %s\n", i, atividades[i].identificador, atividades[i].nome, atividades[i].data, atividades[i].hora, atividades[i].local,
                   atividades[i].tipo, atividades[i].associacao, atividades[i].valorInscricao);
        }
        fclose(fp);
        // printf("Valor lido: %s", participantes);
    }
}
//---------------------------//---------------------------//

//---------- Função para Mostra as Inscrições que já foram guardadas (Consultar incrições) -----------------//
void mostra_inscricao(int posicao) {
    FILE* fp;
    inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES];
    fp = fopen("inscricoes.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir o ficheiro!");
    } else {
        //printf("%d, %s, %s, %s, %s, %s", participantes[3].identificador, participantes[3].nome, participantes[3].escola, participantes[3].nif, participantes[3].email, participantes[3].telefone);
        for (int i = 0; i < posicao; i++) {
            //if (participantes[i].identificador != 0)
            fread(&inscricoes[i], sizeof(inscricao), 1, fp);
            //if (participantes[i].identificador != 0)
            printf("%d - %d, %s, %s, %s, %s, %s\n", i, inscricoes[i].identificador, inscricoes[i].identificadorParticipante, inscricoes[i].identificadorAtividade,
                   inscricoes[i].valorPago, inscricoes[i].data, inscricoes[i].hora);
        }
        fclose(fp);
        // printf("Valor lido: %s", participantes);
    }
}
//---------------------------//---------------------------//

void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]) {
    FILE* fp;
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossível abrir ficheiro");
    } else {
        for (int i = 0; i < NUMERO_MAXIMO_ESTUDANTES; i++) {
            fread(&participantes[i], sizeof(participante[i]), 1, fp);
        }
        fclose(fp);
    }
}

//---------- Função que coloca os dados das Atividades no ficheiro de "atividades.bin" -----------------//
void preenche_atividades(atividade atividades[NUMERO_MAXIMO_ATIVIDADES]) {
    FILE* fp;
    fp = fopen("atividades.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    } else {
        for (int i = 0; i < NUMERO_MAXIMO_ATIVIDADES; i++) {
            fread(&atividades[i], sizeof(atividade[i]), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

//---------- Função que coloca os dados das Inscrições no ficheiro de "inscricoes.bin" -----------------//
void preenche_inscricoes(inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES]) {
    FILE* fp;
    fp = fopen("inscricoes.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
    } else {
        for (int i = 0; i < NUMERO_MAXIMO_INSCRICOES; i++) {
            fread(&inscricoes[i], sizeof(inscricao[i]), 1, fp);
        }
        fclose(fp);
    }
}
//---------------------------//---------------------------//

int obter_ultima_posicao_participantes(void) {
    FILE* fp;
    participante participantes, participantes_aux[NUMERO_MAXIMO_ESTUDANTES];

    int ultima_pos = 0, contador = 0;
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossível abrir ficheiro");
        ultima_pos = 0;
    } else {

        while ((fread(&participantes, sizeof(participante), 1, fp) == 1)) {
            printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, participantes.identificador, participantes.nome, participantes.escola, participantes.nif, participantes.email, participantes.telefone);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}

//---------- Função que dá a última atividade adicionada no ficheiro "atividades.bin" -----------------//
int obter_ultima_posicao_atividades(void) {
    FILE* fp;
    atividade atividades, atividades_aux[NUMERO_MAXIMO_ATIVIDADES];

    int ultima_pos = 0, contador = 0;
    fp = fopen("atividades.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    } else {
        while ((fread(&atividades, sizeof(atividade), 1, fp) == 1)) {
            printf("%d - %d, %s, %s, %s, %s, %s, %s, %s\n", ultima_pos, atividades.identificador, atividades.nome, atividades.data, atividades.hora, atividades.local,
                   atividades.tipo, atividades.associacao, atividades.valorInscricao);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}
//---------------------------//---------------------------//

//---------- Função que dá a última inscrição adicionada no ficheiro "inscricoes.bin" -----------------//
int obter_ultima_posicao_inscricoes(void) {
    FILE* fp;
    inscricao inscricoes, inscricoes_aux[NUMERO_MAXIMO_INSCRICOES];

    int ultima_pos = 0, contador = 0;
    fp = fopen("inscricoes.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    } else {
        while ((fread(&inscricoes, sizeof(inscricao), 1, fp) == 1)) {
            printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, inscricoes.identificador, inscricoes.identificadorParticipante, inscricoes.identificadorAtividade,
                   inscricoes.valorPago, inscricoes.data, inscricoes.hora);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}
//---------------------------//---------------------------//

#endif
