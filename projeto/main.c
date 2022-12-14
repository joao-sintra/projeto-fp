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
#include <string.h>

#include "constantes.h"
#include "funcoes.h"
#include "menus.h"


int main() {

    char escolhaMenuPrincipal, escolhaRegistar, escolhaConsultar, escolhaEstatistica, escolhaSaida;
    int posicaoParticipantes = 0, posicaoAtividades = 0, posicaoInscricoes = 0, quantidade_participantes_por_adicionar = 0, quantidade_atividades_por_adicionar = 0, quantidade_inscricoes_por_adicionar = 0;

    participante participantes[NUMERO_MAXIMO_ESTUDANTES], participantes_por_adicionar[NUMERO_MAXIMO_ESTUDANTES];
    atividade atividades[NUMERO_MAXIMO_ATIVIDADES], atividades_por_adicionar[NUMERO_MAXIMO_ATIVIDADES];
    inscricao inscricoes[NUMERO_MAXIMO_INSCRICOES], inscricoes_por_adicionar[NUMERO_MAXIMO_INSCRICOES];

    posicaoParticipantes = obter_ultima_posicao_participantes();
    posicaoAtividades = obter_ultima_posicao_atividades();
    posicaoInscricoes = obter_ultima_posicao_inscricoes();
    // posicao = 4;

    do {
        system("cls");
        preenche_participantes(participantes);
        preenche_atividades(atividades);
        preenche_inscricoes(inscricoes);
        printf("Posicao Participantes: %d\n", posicaoParticipantes);
        printf("Posicao Atividades: %d\n", posicaoAtividades);
        printf("Posicao Inscrições: %d\n", posicaoInscricoes);
        escolhaMenuPrincipal = menu_principal();

        switch (escolhaMenuPrincipal) {
        case '1':
            do {
                system("cls");
                escolhaRegistar = menu_registar();
                switch (escolhaRegistar) {
                case '1':
                    regista_participante(participantes, &posicaoParticipantes, &quantidade_participantes_por_adicionar);
                    fflush(stdin);
                    getchar();
                    break;
                case '2':
                    //printf("Registar os dados das atividades\n");
                    regista_atividade(atividades, &posicaoAtividades, &quantidade_atividades_por_adicionar);
                    //guarda_participantes_ficheiro(participantes, &quantidade_participantes_por_adicionar, posicaoParticipantes);
                    fflush(stdin);
                    getchar();
                    break;
                case '3':
                    //printf("Registar os dados das inscricoes\n");
                    regista_inscricao(inscricoes, &posicaoInscricoes, &quantidade_inscricoes_por_adicionar);
                    fflush(stdin);
                    getchar();
                    break;
                case '0':

                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while (escolhaRegistar != '0');
            break;
        case '2':
            do {
                system("cls");
                escolhaConsultar = menu_consultar();
                switch (escolhaConsultar) {

                case '1':
                    //printf("Consultar os dados dos participantes\n");
                    mostra_participante(posicaoParticipantes);
                    fflush(stdin);
                    getchar();
                    break;
                case '2':
                    //printf("Consultar os dados das atividades\n");
                    mostra_atividade(posicaoAtividades);
                    fflush(stdin);
                    getchar();
                    break;
                case '3':
                    //printf("Consultar os dados das inscricoes\n");
                    mostra_inscricao(posicaoInscricoes);
                    fflush(stdin);
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
            } while (escolhaConsultar != '0');
            break;
        case '3':
            do {
                system("cls");
                escolhaEstatistica = menu_estatisticas();
                switch (escolhaEstatistica) {

                case '1':
                    printf("Estatisticas do numero de atividades realizadas por cada associacao\n");
                    fflush(stdin);
                    getchar();
                    break;
                case '2':
                    printf("Estatisticas da percentagem de inscricoes por escola\n");
                    fflush(stdin);
                    getchar();
                    break;
                case '3':
                    printf("Estatisticas do valor total das inscricoes entre duas datas por tipo de atividade\n");
                    fflush(stdin);
                    getchar();
                    break;
                case '0':
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }

            } while (escolhaEstatistica != '0');

        case '0':
            system("cls");
            escolhaSaida = menu_saida();

            break;

        default:
            printf("Opção invalida\n");
            break;
        }

    } while (escolhaSaida != 'S');

    guarda_participantes_ficheiro(participantes, &quantidade_participantes_por_adicionar, posicaoParticipantes);
    guarda_atividades_ficheiro(atividades, &quantidade_atividades_por_adicionar, posicaoAtividades);
    guarda_inscricoes_ficheiro(inscricoes, &quantidade_inscricoes_por_adicionar, posicaoInscricoes);

    return 0;
}
