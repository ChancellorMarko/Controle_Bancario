/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Desenha a tela que servirá para direcionar o usuário as funções de cadastro de conta
void Tela_Cadastro(Lista *lista, ListaFinanceira *lista_fi)
{
    // Variaveis
    int opcao = 0;

    do 
    {
        tela();
        
        gotoxy(27, 3);
        printf("[Cadastro de conta]");

        gotoxy(4, 6);
        printf("1 - Incluir Conta.");
        gotoxy(4, 8);
        printf("2 - Alterar Conta.");
        gotoxy(4, 10);
        printf("3 - Consultar Conta.");
        gotoxy(4, 12);
        printf("4 - Remover Conta.");
        gotoxy(4, 14);
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
        }while(opcao < 0 || opcao > 5);

        switch (opcao) 
        {
            case 1:
                Tela_Inclusao(lista);
                break;
            case 2:
                Tela_Alteracao(lista);
                break;
            case 3:
                Consulta_Contas_Bancarias(lista);
                break;
            case 4:
                Tela_Remocao(lista, lista_fi);
                break;
            default:
                return;
                break;
        }

    }while(opcao != 0);
}