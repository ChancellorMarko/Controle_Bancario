/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"


// Função para posicionar o cursor em um determinado ponto da tela
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Função da tela padrão
void tela()
{
    int lin;
    int col;

    system("cls");
    system("color CE");
    for (lin = 1; lin < 25; lin++)
    {
        gotoxy(01, lin);
        printf("|");

        gotoxy(79, lin);
        printf("|");
    }
    for (col = 1; col < 80; col++)
    {
        gotoxy(col, 01);
        printf("-");

        gotoxy(col, 04);
        printf("-");

        gotoxy(col, 22);
        printf("-");

        gotoxy(col, 24);
        printf("-");
    }
    gotoxy(01, 01);
    printf("+");
    gotoxy(79, 01);
    printf("+");

    gotoxy(01, 04);
    printf("+");
    gotoxy(79, 04);
    printf("+");

    gotoxy(01, 22);
    printf("+");
    gotoxy(79, 22);
    printf("+");

    gotoxy(01, 24);
    printf("+");
    gotoxy(79, 24);
    printf("+");

    gotoxy(02, 02);
    printf("UNICV");

    gotoxy(59, 02);
    printf("Gerenciador Bancario");

    gotoxy(64, 03);
    printf("Milena e Marcos");

    gotoxy(02, 23);
    printf("MSG: ");
}

// Limpar o campo de opções da tela
void limpar_campo_opcao()
{
    gotoxy(7, 23);
    printf("                                                                        ");
}

// Desenhar a tela de informações
void tela_conta(Item *ItemLista)
{
    gotoxy(6,6);
    printf("Codigo da Conta.....: %d.", ItemLista->conteudo.codigo_conta);

    gotoxy(6,8);
    printf("1 - Nome do Banco...: %s.", ItemLista->conteudo.banco);

    gotoxy(6,10);
    printf("2 - Agencia.........: %s.", ItemLista->conteudo.agencia);

    gotoxy(6,12);
    printf("3 - Numero da Conta.: %s.", ItemLista->conteudo.numero_conta);

    gotoxy(6,14);
    printf("4 - Tipo da Conta...: %s.", ItemLista->conteudo.tipo_conta);

    gotoxy(6,16);
    printf("5 - Saldo da Conta..: R$%.2lf.", ItemLista->conteudo.vl_saldo);

    gotoxy(6,18);
    printf("6 - Limite da Conta.: R$%.2lf.", ItemLista->conteudo.vl_limite);

    gotoxy(6,20);
    printf("7 - Status da Conta.: %s.", ItemLista->conteudo.status);
}

// Escrever mensagem no campo destina a mensagens
void escrever_msg(const char* mensagem[70])
{
    limpar_campo_opcao();
    gotoxy(7, 23);
    printf("%s", mensagem);
}

// Desenha a tela de consulta de movimentação financeira
void tela_consulta_Financeira()
{
    // Variaveis
    int x;

    tela();

    gotoxy(2, 6);
    for(x = 0; x <= 76; x++)
    {
        printf("-");
    }

    gotoxy(1, 6);
    printf("+");
    gotoxy(79, 6);
    printf("+");

    // Campo do código da conta
    gotoxy(2, 5);
    printf("Codigo da Conta: ");

    // Parte da data
    gotoxy(2, 7);
    printf("Data:     |");
    gotoxy(2, 8);
    printf("----------|");

    // Parte do Destinatário
    gotoxy(13, 7);
    printf("Destinatario:                 |");
    gotoxy(13, 8);
    printf("------------------------------|");

    // Parte do tipo de movimentação
    gotoxy(44, 7);
    printf("Tipo:   |");
    gotoxy(44, 8);
    printf("--------|");

    // parte do valor
    gotoxy(53, 7);
    printf("Vl.Trans:    |");
    gotoxy(53, 8);
    printf("-------------|");

    // Parte do saldo ao final da transação
    gotoxy(67, 7);
    printf("Saldo:      ");
    gotoxy(67, 8);
    printf("------------");
}

// Desenha a tela de cadastro de movimentações financeiras
void tela_cadastro_financeiro(ListaFinanceira *lista_fi, Item *conta)
{
    // Variáveis
    int x;
    int quant_mov = 0;

    quant_mov = Contar_movimentacao_financerira(lista_fi);

    gotoxy(6, 6);
    printf("Sequencia de Movimentacao: %d", quant_mov + 1);
    gotoxy(6, 7);
    printf("Codigo da conta..........: %d", conta->conteudo.codigo_conta);
    gotoxy(6, 8);
    printf("Banco....................: %s", conta->conteudo.banco);
    gotoxy(6, 9);
    printf("Agencia..................: %s", conta->conteudo.agencia);
    gotoxy(6, 10);
    printf("Numero da conta..........: %s", conta->conteudo.numero_conta);
    gotoxy(6, 11);
    printf("Tipo de conta............: %s", conta->conteudo.tipo_conta);
    gotoxy(6, 12);
    printf("Saldo....................: %.2lf", conta->conteudo.vl_saldo);
    gotoxy(6, 13);
    printf("Limite...................: %.2lf", conta->conteudo.vl_limite);
    gotoxy(6, 14);
    printf("Total (Saldo + Limite)...: %.2lf", conta->conteudo.vl_saldo + conta->conteudo.vl_limite);

    for(x = 2; x <+ 79; x++)
    {
        gotoxy(x, 15);
        printf("-");
    }

    gotoxy(6, 16);
    printf("Data da movimentacao.....: ");
    gotoxy(6, 17);
    printf("Tipo de movimnetacao.....: ");
    gotoxy(6, 18);
    printf("Descricao................: ");
    gotoxy(6, 19);
    printf("Valor da movimentacao....: R$");
    gotoxy(6, 20);
    printf("Novo saldo...............: R$");
}