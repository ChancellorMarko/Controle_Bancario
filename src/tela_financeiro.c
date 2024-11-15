/*
Autor: Marcos.
Data: 22/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// Bibliotecas
#include "global.h"

// Desenha a tela de movimentação financeira
void Tela_Financeiro(Lista *lista)
{
    // Variáveis
    int opcao = 0;

    do 
    {
        tela();
        
        gotoxy(30, 3);
        printf("[Movimentacao Financeira]");

        gotoxy(4, 6);
        printf("1 - Movimentacao de Credito e Debito.");
        gotoxy(4, 8);
        printf("2 - Cunsultar movimentacoes bancarias.");
        gotoxy(4, 10);
        printf("0 - Voltar.");

        do 
        {
            gotoxy(7, 23);
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 5)
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
                // Tela de movimentação financeira
                break;
            case 2:
                Consulta_Contas_Bancarias(lista);
                break;
            default:
                return;
                break;
        }

    }while(opcao =! 0);
}