/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Tela_Cadastro(Lista *lista)
{
    // Variaveis
    int opcao = 0;

    do 
    {
        tela();
        
        gotoxy(32, 3);
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
                //TelaEdicao
                break;
            case 3:
                //TelaConsulta
                break;
            case 4:
                //TelaRemocao
                break;
            default:
                return;
                break;
        }

    }while(opcao =! 0);
}