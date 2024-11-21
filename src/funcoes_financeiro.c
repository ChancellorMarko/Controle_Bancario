/*
Autor: Marcos.
Data: 15/11/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// Bibliotecas
#include "global.h"

// Metodo que pede o código de uma conta e escreve todas as movimentações bancarias feitas por ela
void Consulta_Contas_Bancarias(Lista *conta)
{
    // Variáveis
    int x;
    int codigo_pesq;
    Apontador Aux;

    // Escrever cabeçalho
    gotoxy(32, 2);
    printf("[Consulta Bancaria]");

    // Desenhar tela
    tela_consulta_Financeira();

    do
    {
        gotoxy(2, 22);
        scanf("%d", &codigo_pesq);
        if (codigo_pesq < 0) {
            limpar_campo_opcao();
            escrever_msg("Opcao invalida! Digite novamente...");
            getch();
            limpar_campo_opcao();
            gotoxy(2, 22);
            printf("                  ");
        }
    }while(codigo_pesq < 0);
    Aux = Verificar_Existencia(conta, codigo_pesq);

    // Para continuar
}

void Cadastro_Financeiro(ListaFinanceira *financeiro, Lista *conta)
{
    // Varáveis
    int cod_conta;
    Conteudo_Conta aux;

    //tela_movimentacao_financeira(, conta);

    // Verificação do código da conta
    do 
    {
        gotoxy(33, 7);
        scanf("%d", &cod_conta);
        //aux = Verificar_Existencia(conta, cod_conta);
        if(cod_conta > 0)
        {
            limpar_campo_opcao();
            escrever_msg("Valor invalido! Digite novemnete...");
            getch();
            limpar_campo_opcao();
            gotoxy(33, 7);
            printf("              ");
        }
    }while (cod_conta > 0);


}