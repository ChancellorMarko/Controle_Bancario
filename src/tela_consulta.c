/*
Autor: Milena
Data: 17/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Consulta_Contas_Bancarias(Lista *lista)
{

    int opcao = 0;

    do
    {

        tela();

        gotoxy(32, 3);
        printf("[Menu de Consulta de conta]");

        gotoxy(4, 8);
        printf("1 - Consultar geral(todas as contas)");
        gotoxy(4, 10);
        printf("2 - Consultar por codigo");
        gotoxy(4, 12);
        printf("3 - Consultar por ordem codigo");
        gotoxy(4, 14);
        printf("4 - Consultar por ordem alfabetica");
        gotoxy(4, 16);
        printf("0 - Sair");

        do
        {

            gotoxy(7, 23);
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);

            if (opcao < 0 || opcao > 4)
            {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Opcao invalida! Digite novamente.");
                limpar_campo_opcao();
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            Consulta_geral(lista);
            break;
        case 2:
            // consulta_codigo
            break;
        case 3:
            // consulta_ordemCodigo
            break;
        case 4:
            // consulta_alfabetica
        default:
            break;
        }
    }while(opcao != 0);

    // return lista;
}