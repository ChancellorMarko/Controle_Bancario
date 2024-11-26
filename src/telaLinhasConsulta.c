/*
Autor: Milena
Data: 23/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Função para posicionar o cursor em um determinado ponto da tela

// void gotoxy(int x, int y)
// {
//     COORD coord;
//     coord.X = (short)x;
//     coord.Y = (short)y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }

void TelaLinhasConsulta()
{

    // int lin;
    int col = 0;

    system("cls");

    gotoxy(col, 6);
    printf("-- ------------------- ---- -------- -------------- ----------- ---------- --");

    gotoxy(2, 5);
    printf("Cd");

    gotoxy(5, 5);
    printf("Banco");

    gotoxy(25, 5);
    printf("Agenc");

    gotoxy(31, 5);
    printf("Conta");

    gotoxy(40, 5);
    printf("Tipo Conta");

    gotoxy(55, 5);
    printf("Saldo");

    gotoxy(67, 5);
    printf("Limite");

    gotoxy(78, 5);
    printf("St");

    gotoxy(43, 14);
    printf("Saldo Total: R$           R$");
}
