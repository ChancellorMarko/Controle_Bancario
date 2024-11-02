// Tela de inclusão de conta

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "global.h"

void Tela_Inclusao(Lista *lista)
{
    // Variaveis
    int opcao;

    do 
    {
        tela();
        
        gotoxy(32, 3);
        printf("[Inclusao de conta]");

        gotoxy(4, 6);
        printf("1 - Incluir Conta (Final da Lista).");
        gotoxy(4, 8);
        printf("2 - Incluir Conta (Inicio da Lista).");
        gotoxy(4, 10);
        printf("3 - Incluir Conta (Uma posicao da Lista).");
        gotoxy(4, 12);
        printf("0 - Voltar.");

        do 
        {
            gotoxy(7, 23);
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 4)
            {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Opcao invalida!");
                limpar_campo_opcao();
            }
        }while(opcao < 0 || opcao > 4);

        switch (opcao) 
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
                break;
        }

    }while(opcao != 0);
}