/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// testando git - milena


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
    printf("6 - Status da Conta.: %s.", ItemLista->conteudo.status);
}

// Escrever mensagem no campo destina a mensagens
void escrever_msg(char* mensagem[70])
{
    gotoxy(7, 23);
    printf("%s", mensagem);
}