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

    // Criar lista
    Lista lista;
    lista = LerLista();

    do 
    {
        tela();

        gotoxy(4, 6);
        printf("1 - Cadastro de conta.");
        gotoxy(4, 8);
        printf("2 - Movimentacao financeira.");
        gotoxy(4, 10);
        printf("3 - Sair.");
        
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
                Tela_Cadastro(&lista);
                break;
            case 2:
                //financeiro
                break;
            default:
                break;
        }
    }while (opcao != 0);

    // Salvar Lista
    SalvarLista(&lista);

    // Limpar Memória
    LimparMemoria(&lista);

    return 0;
}