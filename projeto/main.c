#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes.h"
#include "menus.h"


int main() {
    setlocale(LC_ALL,"Portuguese");
    char escolhaMenuPrincipal, escolhaRegistar, escolhaConsultar, escolhaEstatistica, escolhaSaida;

    do {
        printf("*********************** Menu ção Principal ***********************\n");
        printf("[1] Registar\n");
        printf("[2] Consultar\n");
        printf("[3] Estatisticas\n");
        printf("[0] Sair\n\n");
        printf("Opcao -> ");
        scanf(" %c", &escolhaMenuPrincipal);

        switch(escolhaMenuPrincipal) {
        case '1':
            do {
                printf("*********************** Menu Registar ***********************\n");
                printf("[1] Registar os dados dos participantes\n");
                printf("[2] Registar os dados das atividades\n");
                printf("[3] Registar os dados das inscrições\n");
                printf("[0] Voltar\n\n");
                printf("Opcao -> ");
                scanf(" %c", &escolhaRegistar);
            switch(escolhaRegistar) {

                case '1':
                    printf("Registar os dados dos participantes\n");
                    break;
                case '2':
                    printf("Registar os dados das atividades\n");
                    break;
                case '3':
                    printf("Registar os dados das inscrições\n");
                    break;
                case '0':

                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while(escolhaRegistar!='0');
            break;
        case '2':
            do {
                printf("*********************** Menu Consultar ***********************\n");
                printf("[1] Consultar os dados dos participantes\n");
                printf("[2] Consultar os dados das atividades\n");
                printf("[3] Consultar os dados das inscrições\n");
                printf("[0] Voltar\n\n");
                printf("Opcao -> ");
                scanf(" %c", &escolhaConsultar);
                switch(escolhaConsultar) {

                case '1':
                    printf("Consultar os dados dos participantes\n");
                    break;
                case '2':
                    printf("Consultar os dados das atividades\n");
                    break;
                case '3':
                    printf("Consultar os dados das inscrições\n");
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while(escolhaConsultar!='0');
            break;
        case '3':
            do {
                printf("*********************** Menu Estatisticas ***********************\n \n");
                printf("[1] Estatisticas do numero de atividades realizadas por cada associacao\n");
                printf("[2] Estatisticas da percentagem de inscrições por escola\n");
                printf("[3] Estatisticas do valor total das inscrições entre duas datas por tipo de atividade\n");
                printf("[0] Voltar\n\n");
                printf("Opcao -> ");
                scanf(" %c", &escolhaEstatistica);
                switch(escolhaEstatistica) {

                case '1':
                    printf("Estatisticas do numero de atividades realizadas por cada associacao\n");
                    break;
                case '2':
                    printf("Estatisticas da percentagem de inscrições por escola\n");
                    break;
                case '3':
                    printf("Estatisticas do valor total das inscrições entre duas datas por tipo de atividade\n");
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while(escolhaEstatistica!='0');
            break;
        case '0':
            printf("Pretende sair? 'S'im ou 'N'ao: ");
            scanf(" %c", &escolhaSaida );
            escolhaSaida = toupper(escolhaSaida);
            break;

        default:
            printf("Opção invalida\n");
            break;
        }

    } while(escolhaSaida!='S');

    return 0;
}
