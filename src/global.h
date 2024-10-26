#ifndef GLOBAL_H
#define GLOBAL_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// Função para posicionar o cursor em um determinado ponto da tela
void gotoxy(int x, int y);

// Desenha a tela padrão
void tela();

// Limpar o campo de opções
void limpar_campo_opcao();

#endif