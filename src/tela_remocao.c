/*
Autor: Milena
Data: 10/11/24.
Membros:
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Desenha tela de remoção de cadastros de conta
void Tela_Remocao(Lista *lista_co, ListaFinanceira *lista_fi)
{

    int opcao = 0;

    do
    {
        tela();

        gotoxy(27, 3);
        printf("[Remocao de conta]");
        gotoxy(4, 6);
        printf("1 - Remover conta (Final da lista). ");
        gotoxy(4, 8);
        printf("2 - Remover conta (Inicio da lista). ");
        gotoxy(4, 10);
        printf("3 - Remover conta (Em uma posicao da lista). ");
        gotoxy(4, 12);
        printf("0 - Voltar. ");
    
        do
        {
            gotoxy(7, 23);
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Opcao invalida!");
                limpar_campo_opcao();
            }
        }while(opcao < 0 || opcao > 3);

        switch (opcao)
        {
            case 1:
                Remover(lista_co, lista_fi, opcao);
                break;
            case 2:
                Remover(lista_co, lista_fi, opcao);
                break;
            case 3:
                Remover(lista_co, lista_fi, opcao);
                break;
            default:
                return;
                break;
        }
    }while(opcao != 0);
}