/*
Autor: Milena.
Data: 24/11/24.
Membros:
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void TelaExibirConta(Apontador aux)
{

    // Coloca na tela as informações da conta escolhida
    gotoxy(6, 6);
    printf("Codigo da conta: %d", aux->conteudo.codigo_conta);
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
}
