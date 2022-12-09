#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#ifndef MENUS_H
#define MENUS_H

#include "constantes.h"
#include "funcoes.h"

char menu_principal(void);
char menu_registar(void);
char menu_consultar(void);
char menu_estatisticas(void);
char menu_saida(void);

//Funcão do Menu principal
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
//Funcão do Menu dos registos
char menu_registar(void) {
    char opcao;
    do {
        printf("*********************** Menu Registar ***********************\n");
        printf("[1] Registar os dados dos participantes\n");
        printf("[2] Registar os dados das atividades\n");
        printf("[3] Registar os dados das inscrições\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//Funcão do Menu das consultas
char menu_consultar(void) {
    char opcao;
    do {
        printf("*********************** Menu Consultar ***********************\n");
        printf("[1] Consultar os dados dos participantes\n");
        printf("[2] Consultar os dados das atividades\n");
        printf("[3] Consultar os dados das inscrições\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//Funcão do Menu das estatisticas
char menu_estatisticas(void) {
    char opcao;
    do {
        printf("*********************** Menu Estatisticas ***********************\n \n");
        printf("[1] Estatisticas do numero de atividades realizadas por cada associacao\n");
        printf("[2] Estatisticas da percentagem de inscrições por escola\n");
        printf("[3] Estatisticas do valor total das inscrições entre duas datas por tipo de atividade\n");
        printf("[0] Voltar\n\n");
        printf("Opcao -> ");
        scanf(" %c", &opcao);
        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0')
            printf("Opcao invalida");
    } while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0');
    return opcao;
}
//Funcão do Menu de saida
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
#endif