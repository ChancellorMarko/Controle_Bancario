// Tela de cadastro de conta

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "global.h"

void Tela_Cadastro(Lista *lista)
{
    // Variaveis
    int opcao;

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
        gotoxy(4, 6);
        printf("4 - Remover Conta.");

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
                //TelaInclusao
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
                break;
        }

    }while(opcao =! 0);
}