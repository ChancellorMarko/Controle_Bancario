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

// Desenhar a tela de informações
Conteudo_Conta tela_cadastro_conta(Lista *lista);

// Limpar o campo de opções
void limpar_campo_opcao();

// Desenhar a tela de cadastro de contas
void Tela_Cadastro();

// Desenhar a tela de inclusão de cadastros na lista
void Tela_Inclusao();

// Função que conta quantos cadastros estão presentes na lista
int Contar_Elementos_Lista(Lista *lista);

// Função que verifica se o código de funcionario já foi utilizado
Apontador Verificar_Existencia(Lista *lista, int codigo_conta);

// Função de castro de contas
void Cadastro(Lista *lista, int posicao_na_lista);

#endif