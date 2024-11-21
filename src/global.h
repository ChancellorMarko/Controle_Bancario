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

// --------------- Estrutura de dados - Conta ----------------

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

// --------------- Estrutura de dados - Financeiro ----------------

// Definir conteudo financeiro
typedef struct 
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimentacao[15];
    double vl_movimento;
    double vl_saldo;
} Conteudo_Financeiro;

// Definir o apontador que aponta para o item financeiro
typedef struct ItemFinanceiro *ApontadorFinanceiro;

// Definir o tipo de item da lista financeira
typedef struct ItemFinanceiro
{
    Conteudo_Financeiro conteudo;
    Apontador proximo;
    Apontador anterior;
} ItemFinanceiro;

// Definir lista: inicio e fim
typedef struct
{
    Apontador primeiro;
    Apontador ultimo;
} ListaFinanceira;

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

// Função para limpar a memória da lista de cadastro de contas
void Limpar_Mem_Contas(Lista *lista);

// Função que inicializa uma lista
Lista InicializarLista();

// Função Responsável por adicionar contas a lista
void Adicionar_Conta(Lista *lista, Conteudo_Conta conteudo);

// Criar o arquivo com os dados da lista
void SalvarLista(Lista *lista);

// Ler o arquivo com os dados da lista
Lista LerLista();

// Desenha a tela de movimentação financeira
void Tela_Financeiro(Lista *lista);

// Metodo que pede o código de uma conta e escreve todas as movimentações bancarias feitas por ela
void Consulta_Contas_Bancarias(Lista *lista);

// Desenha tela de remoção de cadastros de conta
void Tela_Remocao(Lista *lista);

// Função que realiza a remoção de itens na lista de cadastros de contas
void Remover(Lista *lista, int opcao_lista);

// Inicaializar a lista de operações financeiras
ListaFinanceira InicializarListaFinanceira();

// Método para adicionar cada um dos item da lista financeira em uma nova lista
void Adicionar_Movimentacoes(ListaFinanceira *lista, Conteudo_Financeiro conteudo);

// Função que abre o arquivo e lê todos os dados criando uma lista financeira
ListaFinanceira LerListaFinanceira();

// Função responsável por salvar todos os dados de operações financeiras em um arquivo
void SalvarListaFinanceira(ListaFinanceira *lista);

// Função para limpar a memória da lista de movimentacao financeira
void Limpar_Mem_Finan(ListaFinanceira *lista);

// Define um valor aleatório de crédito para uma conta corrente
double Serasa(Conteudo_Conta *conta);

// Desenha a tela de consulta de movimentação financeira
void tela_consulta_Financeira();

// Desenha a tela de movimentação de credito e debito
void tela_movimentacao_financeira(ListaFinanceira *finaceiro, Conteudo_Conta *conta);

#endif