#ifndef GLOBAL_H
#define GLOBAL_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// --------------- Estruturas de dados --------------- 

// Definir conteudo da conta
typedef struct 
{
    int codigo_conta;
    char banco[50];
    char agencia[50];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
} Conteudo_Conta;

// Definir o apontador que aponta para o item
typedef struct Item *Apontador;

// Definir o tipo de item da lista
typedef struct Item
{
    Conteudo_Conta conteudo;
    Apontador proximo;
} Item;

// Definir lista: inicio e fim
typedef struct
{
    Apontador primeiro;
    Apontador ultimo;
} Lista;

// --------------------------------------------------- 

// Função para posicionar o cursor em um determinado ponto da tela
void gotoxy(int x, int y);

// Desenha a tela padrão
void tela();

// Limpar o campo de opções
void limpar_campo_opcao();

// Desenhar a tela de cadastro de contas
void Tela_Cadastro();

#endif