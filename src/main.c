/*
Autores: Milena e Marcos.
Data: 22/10/24.
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "global.h"

int main()
{
    // Variaveis
    int opcao = 0;

    do 
    {
        tela();

        gotoxy(6, 6);
        printf("1 - Cadastro de conta.");
        gotoxy(6, 8);
        printf("0 - Sair.");
        
        do 
        {
        gotoxy(7, 23);
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);
        if(opcao < 0 || opcao > 6)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Opcao invalida!");
            limpar_campo_opcao();
        }
        }while(opcao < 0 || opcao > 6);

        switch (opcao) 
        {
            case 1:
                break;
            default:
                break;
        }
    }while (opcao != 0 );

    return 0;
}