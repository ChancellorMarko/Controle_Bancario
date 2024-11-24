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

// Difinições
#define DEBITO "Debito"
#define CREDITO "Credito"

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
// ----------------------------------------------------------------

// --------------- Estrutura de dados - Financeiro ----------------
// Definir conteudo financeiro
typedef struct 
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char destinatario[50]; // Acrescentado pois, como o professor mostrou, fica bem mais intuitivo
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
    ApontadorFinanceiro proximo;
    ApontadorFinanceiro anterior;
} ItemFinanceiro;

// Definir lista: inicio e fim
typedef struct
{
    ApontadorFinanceiro primeiro;
    ApontadorFinanceiro ultimo;
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


//Função para consultar todas as contas bancárias
void Consulta_geral(Lista *lista);

//Função para consultar a conta bancária pelo código que o usuário escolher
void Consulta_codigo(Lista *lista, int codigo_conta);

// Função para consultar as contas bancárias por ordem numérica
void Consulta_ordemCodigo(Lista *lista);

//Função para consultar as contas bancárias por ordem alfabética
void Consulta_alfabetica(Lista *lista);
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
void Tela_Financeiro(ListaFinanceira *lista_fi, Lista *lista_co);

// Método que pede o código de uma conta e escreve todas as informações das contas bancarias
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

// Função de consulta o código da conta para a função de remoção
void Consulta_codigo(Lista *lista, int codigo_conta);

// Tela de consulta de contas
void Consulta_geral(Lista *lista);

// Desenha a tela de cadastro de movimentações financeiras
void tela_cadastro_financeiro(ListaFinanceira *lista_fi, Item *conta);

// Contar sequencia de movimentações financeiras
int Contar_movimentacao_financerira(ListaFinanceira *lista);

// Cadastro de movimentações financeiras
void Cadastro_Financeiro(ListaFinanceira *lista_fi, Lista *lista_co);

// Realizar a movimentação de valores nas movimentações bancarias
void Realizar_Movimentacao(Conteudo_Financeiro *mov_fin, Item *conta, int tipo_operacao);

// Incrementa o sequencial de movimentações financeiras
void Incrementar_Sequencial(ListaFinanceira *lista_fi, Conteudo_Financeiro *temporario);

#endif