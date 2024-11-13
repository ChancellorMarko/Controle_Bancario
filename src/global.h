/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#ifndef GLOBAL_H
#define GLOBAL_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// --------------- Estrutura de dados - Simplesmente encadeada --------------- 

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

// ------------------------------------------------------------ 

// --------------- Estrutura de dados - Simplesmente encadeada --------------- 

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
} Conteudo_Financeiro;

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

// ------------------------------------------------------------

// Função para posicionar o cursor em um determinado ponto da tela
void gotoxy(int x, int y);

// Desenha a tela padrão
void tela();

// Desenhar a tela de informações
void tela_conta(Item *ItemLista);

// Limpar o campo de opções
void limpar_campo_opcao();

// Desenhar a tela de cadastro de contas
void Tela_Cadastro(Lista *lista);

// Desenhar a tela de inclusão de cadastros na lista
void Tela_Inclusao(Lista *lista);

// Desenhar a tela de alteração de itens na lista
void Tela_Alteracao(Lista *lista);

// Função que conta quantos cadastros estão presentes na lista
int Contar_Elementos_Lista(Lista *lista);

// Função que verifica se o código de funcionario já foi utilizado
Apontador Verificar_Existencia(Lista *lista, int codigo_conta);

// Função de castro de contas
void Cadastro(Lista *lista, int posicao_na_lista);

// Escrever mensagem no campo destina a mensagens
void escrever_msg(char* mensagem[70]);

// Função para limpar a memória depois de finalizar o programa
void LimparMemoria(Lista *lista);

// Função que inicializa uma lista
Lista InicializarLista();

// Função Responsável por adicionar contas a lista
void Adicionar_Conta(Lista *lista, Conteudo_Conta conteudo);

// Criar o arquivo com os dados da lista
void SalvarLista(Lista *lista);

// Ler o arquivo com os dados da lista
Lista LerLista();

#endif