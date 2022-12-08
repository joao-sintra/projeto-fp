/*************************************************
                    Projeto FP
    Unidade Curricular: Fundamentos de Programação
    Docente: Carmen Francisco
    Elaborado por:
    João Sintra, 2220865
    Francisco Furtado, 2220870
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#include "constantes.h"
#include "funcoes.h"
#include "menus.h"


int main() {
    setlocale(LC_ALL,"Portuguese");
    char escolhaMenuPrincipal, escolhaRegistar, escolhaConsultar, escolhaEstatistica, escolhaSaida;

    do {
        system("cls");
       escolhaMenuPrincipal = menu_principal();
        switch(escolhaMenuPrincipal) {
        case '1':
           do{
                system("cls");
             escolhaRegistar= menu_registar();
            switch(escolhaRegistar) {
                case '1':
                    printf("Registar os dados dos participantes\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '2':
                    printf("Registar os dados das atividades\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '3':
                    printf("Registar os dados das inscrições\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '0':

                    break;
                default:
                    printf("Opcao invalidaq\n");
                    break;
                }

            } while(escolhaRegistar!='0');
           break;
        case '2':
            do {
                system("cls");
                escolhaConsultar = menu_consultar();
                switch(escolhaConsultar) {

                case '1':
                    printf("Consultar os dados dos participantes\n");
                    fflush(stdin);
                    getchar();
                    break;
                case '2':
                    printf("Consultar os dados das atividades\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '3':
                    printf("Consultar os dados das inscrições\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalidaq\n");
                    break;
                }

            } while(escolhaConsultar!='0');
            break;
        case '3':
            do {
                system("cls");
                escolhaEstatistica = menu_estatisticas();
                switch(escolhaEstatistica) {

                case '1':
                    printf("Estatisticas do numero de atividades realizadas por cada associacao\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '2':
                    printf("Estatisticas da percentagem de inscrições por escola\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '3':
                    printf("Estatisticas do valor total das inscrições entre duas datas por tipo de atividade\n");
                     fflush(stdin);
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalidaq\n");
                    break;
                }

            } while(escolhaEstatistica!='0');

        case '0':
        system("cls");
            escolhaSaida= menu_saida();
            break;

        default:
            printf("Opção invalidaq\n");
            break;
        }

    } while(escolhaSaida!='S');

    return 0;
}
