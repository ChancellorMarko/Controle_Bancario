/*
Autor: Milena
Data: 10/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Tela_Remocao(Lista *lista)
{

    int opcao = 0;

    do
    {
        tela();

        gotoxy(32, 3);
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

        switch (opcao);
        {
            case 1:
                Cadastro(lista, opcao);
                break;
            case 2:
                Cadastro(lista, opcao);
                break;
            case 3:
                Cadastro(lista, opcao);
                break;
            default:
                return;
                break;
        }

    }while(opcao != 0);
}