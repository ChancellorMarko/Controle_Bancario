/*
Autor: Milena
Data: 19/11/24.
Membros:
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Tela de consulta de contas
void Consulta_geral(Lista *lista)
{
    Apontador aux;
    int opcao;

    do
    {
        tela();
        gotoxy(20, 3);
        printf("[Consulta geral de todas as contas]");

        aux = lista->primeiro;

        if (aux == NULL)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("A lista esta vazia.");
        }
        else
        {
            while (aux != NULL)
            {
                gotoxy(6, 6);
                printf("Codigo da conta: %d", aux->conteudo.codigo_conta);
                gotoxy(6, 8);
                printf("Nome do banco..: %s", aux->conteudo.banco);
                gotoxy(6, 10);
                printf("Numero da conta: %s", aux->conteudo.numero_conta);
                gotoxy(6, 12);
                printf("Tipo da conta..: %s", aux->conteudo.tipo_conta);
                gotoxy(6, 14);
                printf("Saldo da conta.: %.f", aux->conteudo.vl_saldo);
                gotoxy(6, 16);
                printf("Limite da conta: %.f", aux->conteudo.vl_limite);
                gotoxy(6, 18);
                printf("Status da conta: %s", aux->conteudo.status);

                // Pergunta ao usuário se deseja continuar
                escrever_msg("Pressione qualquer outra tecla para continuar...");
                getch(); 

                aux = aux->proximo;
            }
        }

        // Verificar se o usuário quer ver novamente
        do
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Quer realizar a consulta novamente? [1-S, 2-N]: ");
            scanf("%d",&opcao);
            if(opcao < 1 || opcao > 2)
            {
                limpar_campo_opcao();
                escrever_msg("Valor invalido! Digite novamente...");
                getch();
                limpar_campo_opcao();
            }
        }while(opcao < 1 || opcao > 2); 
    } while (opcao != 2);
    getch();
    return;
}
