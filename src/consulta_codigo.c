/*
Autor: Milena
Data: 19/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Função de consulta o código da conta para a função de remoção
/*
void Consulta_codigo(Lista *lista)
{
    int resp = 0;

    tela();
    gotoxy(20, 3);
    printf("[Consulta pelo codigo da conta]");

    if (codigo_conta < 0)
    {
        limpar_campo_opcao();
        gotoxy(7, 23);
        printf("Codigo invalido! Digite novamente...");
        getch();
        limpar_campo_opcao();
    }

    // Criando um apontador auxiliar para inicializar apontando pra o primeiro da lista
    Apontador aux = lista->primeiro;

    while (codigo_conta != aux->conteudo.codigo_conta)
    {
        aux = aux->proximo;

        if (aux == NULL)
        {
            limpar_campo_opcao();
            gotoxy(23, 7);
            printf("Codigo nao encontrado.");
            getch();
            limpar_campo_opcao();
            return;
        }
    }
    do
    {
        if(resp == 1){
        gotoxy(6, 6);
        printf("Codigo da conta: ");
        scanf("%d", &codigo_conta);
        gotoxy(6, 8);
        printf("Nome do banco..: %s", aux->conteudo.banco);
        gotoxy(6, 10);
        printf("Numero da conta: %s", aux->conteudo.numero_conta);
        gotoxy(6, 12);
        printf("Tipo da conta..: %s", aux->conteudo.tipo_conta);
        gotoxy(6, 14);
        printf("Saldo da conta.: %.2f", aux->conteudo.vl_saldo);
        gotoxy(6, 16);
        printf("Limite da conta: %.2f", aux->conteudo.vl_limite);
        gotoxy(6, 18);
        printf("Status da conta: %s", aux->conteudo.status);

        gotoxy(7, 23);
        printf("Deseja consultar outra conta? [1-S, 2-N]: ");
        gotoxy(49, 23);
        scanf("%d", &resp);
        limpar_campo_opcao();
        }

        if (resp < 0 || resp > 3)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Entrada invalida! Digite novamente...");
            getch();
            limpar_campo_opcao();
        }
    } while (resp == 1);

    if (resp == 2)
    {
        return;
    }
}
*/