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
    int indetificador;
    char nome[31];
    char escola[7];
    char nif[10];
    char email[51];
    char telefone[10];

}participante;


void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* posicao, int* quantidade_participantes_por_adicionar);
void mostra_participante(int posicao);
void guarda_participantes_ficheiro(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* quantidade_participantes_por_adicionar, int posicao);
void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]);
int obter_ultima_posicao(void);


void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES], int* posicao, int* quantidade_participantes_por_adicionar) {
    int pos_aux = *posicao;
    char escolas[5][7] = { "ESTG","ESECS","ESSLEI", "ESAD", "ESTM" };
    int numero_escola;

    printf("Posicao_aux do array: %d\n", pos_aux);
    participantes[*posicao].indetificador = *posicao;

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
    // printf("Posicao do array: %d\n", *posicao);
     //printf("quantidade participantes por adicionar: %d\n", *quantidade_participantes_por_adicionar);

}
void mostra_participante(int posicao) {


    FILE* fp;
    participante participantes[NUMERO_MAXIMO_ESTUDANTES];
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossível abrir ficheiro");
    }
    else {
        for (int i = 0;i < posicao;i++) {
            fread(&participantes[i], sizeof(participante), 1, fp);
            printf("%d - %d, %s, %s, %s, %s, %s\n", i, participantes[i].indetificador, participantes[i].nome, participantes[i].escola, participantes[i].nif, participantes[i].email, participantes[i].telefone);
        }
        fclose(fp);
    }
}

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
        printf("Não existe participantes novos para guardar no ficheiro");
    }
    fclose(fp);
}


void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]) {
    FILE* fp;
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossível abrir ficheiro");
    }
    else {
        for (int i = 0; i < NUMERO_MAXIMO_ESTUDANTES; i++) {
            fread(&participantes[i], sizeof(participante[i]), 1, fp);
        }
        fclose(fp);
    }

}

int obter_ultima_posicao(void) {
    FILE* fp;
    participante participantes, participantes_aux[NUMERO_MAXIMO_ESTUDANTES];

    int ultima_pos = 0, contador = 0;
    fp = fopen("participantes.bin", "rb");
    if (fp == NULL) {
        printf("Impossivel abrir ficheiro");
        ultima_pos = 0;
    }
    else {
        while ((fread(&participantes, sizeof(participante), 1, fp) == 1))
        {
            printf("%d - %d, %s, %s, %s, %s, %s\n", ultima_pos, participantes.indetificador, participantes.nome, participantes.escola, participantes.nif, participantes.email, participantes.telefone);
            ultima_pos++;
        }
        fclose(fp);
    }
    return ultima_pos;
}


#endif
