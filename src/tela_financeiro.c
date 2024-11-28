/*
Autor: Marcos.
Data: 22/10/24.
Membros: 
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// Bibliotecas
#include "global.h"

// Desenha a tela de movimentação financeira
void Tela_Financeiro(ListaFinanceira *lista_fi, Lista *lista_co)
{
    // Variáveis
    int opcao = 0;

    do 
    {
        tela();
        
        gotoxy(25, 3);
        printf("[Movimentacao Financeira]");

        gotoxy(4, 6);
        printf("1 - Movimentacao de Credito e Debito.");
        gotoxy(4, 8);
        printf("2 - Consultar movimentacoes bancarias.");
        gotoxy(4, 10);
        printf("0 - Voltar.");

        do 
        {
            gotoxy(7, 23);
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 2)
            {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Opcao invalida!");
                limpar_campo_opcao();
            }
        }while(opcao < 0 || opcao > 2);

        switch (opcao) 
        {
            case 1:
                Cadastro_Financeiro(lista_fi, lista_co);
                break;
            case 2:
                ConsultaMovimentacaoFinanceira(lista_fi, lista_co);
                break;
            default:
                return;
                break;
        }

    }while(opcao != 0);
}