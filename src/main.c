/*
Autor: Marcos.
Data: 22/10/24.
Membros: 
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
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

    // Criar lista de contas
    Lista lista_co;
    lista_co = LerLista();

    // Criar lista de movimentação financeiras
    ListaFinanceira Lista_fi;
    Lista_fi = LerListaFinanceira();

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
                Tela_Cadastro(&lista_co, &Lista_fi);
                break;
            case 2:
                Tela_Financeiro(&Lista_fi, &lista_co);
                break;
            case 3:
                limpar_campo_opcao();
                escrever_msg("Saindo...");
                getch();
                break;
            default:
                break;
        }
    }while (opcao != 3);

    // Salvar Lista Contas
    SalvarLista(&lista_co);

    // Limpar Memória Contas
    Limpar_Mem_Contas(&lista_co);

    // Salvar Lista Financeira
    SalvarListaFinanceira(&Lista_fi);

    //Limpar Memória Financeira
    Limpar_Mem_Finan(&Lista_fi);

    return 0;
}