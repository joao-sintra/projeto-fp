#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#ifndef FUNCOES_H
#define FUNCOES_H

#include "constantes.h"
#include "menus.h"

typedef struct{
    int indetificador;
    char nome[31];
    char escola[7];
    char nif[10];
    char email[51];
    char telefone[10];

}participante;

void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES]);
void mostra_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES]);
void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]);

void regista_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES]){
    FILE *fp;
    fp = fopen("participantes.bin", "ab");
    int contador = 1;
    participantes[contador].indetificador = contador;
    printf("Introduza o nome do participante: ");
    scanf("%s", &participantes[contador].nome);
    printf("Introduza a escola do participante: ");
    scanf("%s", &participantes[contador].escola);
    printf("Introduza o nif do participante: ");
    scanf("%s", &participantes[contador].nif);
    printf("Introduza o email do participante: ");
    scanf("%s", &participantes[contador].email);
    printf("Introduza o telefone do participante: ");
    scanf("%s", &participantes[contador].telefone);
    fwrite(participantes, sizeof(participante), NUMERO_MAXIMO_ESTUDANTES, fp);
    contador++;
    printf("contador: %d",contador);
    fclose(fp);
    
}
void mostra_participante(participante participantes[NUMERO_MAXIMO_ESTUDANTES]){
    
   
    FILE *fp;
     fp = fopen("participantes.bin", "rb");
    int numero_estudantes=0;
    while(fread(&participantes[numero_estudantes], sizeof(participante), NUMERO_MAXIMO_ESTUDANTES, fp)==1){
         numero_estudantes++;
      
    }
    printf("%d\n\n", numero_estudantes);
    fclose(fp);
     printf("%d, %s, %s, %s, %s, %s",participantes[0].indetificador,participantes[0].nome, participantes[0].escola, participantes[0].nif, participantes[0].email, participantes[0].telefone);
    for(int i=0;i<numero_estudantes;i++){
       // printf("%d, %s, %s, %s, %s, %s\n",participantes[i].indetificador,participantes[i].nome, participantes[i].escola, participantes[i].nif, participantes[i].email, participantes[i].telefone);
    }
   
    // printf("Valor lido: %s", participantes);
    
}
void preenche_participantes(participante participantes[NUMERO_MAXIMO_ESTUDANTES]){
     FILE *fp;
     fp = fopen("participantes.bin", "rb");
    fread(participantes, sizeof(participante), NUMERO_MAXIMO_ESTUDANTES, fp);
    fclose(fp);
}

#endif