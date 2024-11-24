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

// Cadastro de movimentações financeiras
void Cadastro_Financeiro(ListaFinanceira *lista_fi, Lista *lista_co)
{
    // Varáveis
    int opcao;
    int cod_conta;
    int tipo_operacao;
    int confirmacao;
    Conteudo_Financeiro temporario;
    Apontador aux_conta;
    ApontadorFinanceiro P;
    
    do 
    {
        tela();

        gotoxy(32, 3);
        printf("[Codastro Financeiro]");

        do {
            // Verificação do código da conta
            do 
            {
                limpar_campo_opcao();
                escrever_msg("Digite o codigo da conta (0 - Sair): ");
                scanf("%d", &cod_conta);
                aux_conta = Verificar_Existencia(lista_co, cod_conta);
                if(cod_conta == 0)
                {
                    return;
                }
                else if(cod_conta < 0)
                {
                    limpar_campo_opcao();
                    escrever_msg("Valor invalido! Digite novemnete...");
                    getch();
                    limpar_campo_opcao();
                    gotoxy(33, 7);
                    printf("              ");
                }
                limpar_campo_opcao();
            }while (cod_conta < 0);

            // Desenhar a tela de cadastro
            tela_cadastro_financeiro(lista_fi, aux_conta);

            // Sequencial
            Incrementar_Sequencial(lista_fi, &temporario);

            // Data
            gotoxy(33, 16);
            fflush(stdin);
            fgets(temporario.dt_movimento, 11, stdin);

            // Tipo de transação
            do
            {
                limpar_campo_opcao();
                escrever_msg("1 - Debito / 2 - Credito");
                gotoxy(33, 17);
                scanf("%d", &tipo_operacao);
                if (tipo_operacao < 1 || tipo_operacao > 2) 
                {
                    limpar_campo_opcao();
                    escrever_msg("Valor invalido! Digite novamente...");
                    getch();
                    gotoxy(33, 17);
                    printf("               ");
                    limpar_campo_opcao();
                }
                switch (tipo_operacao) 
                {
                    case 1:
                        strcpy(temporario.tp_movimentacao, DEBITO);
                        gotoxy(33, 17);
                        printf("1 - Debito");
                        break;
                    case 2:
                        gotoxy(33, 17);
                        printf("2 - Credito");
                        strcpy(temporario.tp_movimentacao, CREDITO);
                        break;
                }
            }while(tipo_operacao < 1 || tipo_operacao > 2);

            // Destinatário
            gotoxy(33, 18);
            fflush(stdin);
            fgets(temporario.destinatario, 50, stdin);

            // Valor da movimentação    
            gotoxy(35, 19);
            scanf("%lf", &temporario.vl_movimento);

            Realizar_Movimentacao(&temporario, aux_conta, tipo_operacao);
            
            // Mostrar Saldo apos movimentação
            gotoxy(35, 20);
            printf("%.2lf", temporario.vl_saldo);

            do 
            {
                limpar_campo_opcao();
                escrever_msg("Confirmar movimentacao? (1 - S/2 - N): ");
                scanf("%d", &confirmacao);
                if(confirmacao < 1 || confirmacao > 2)
                {
                    limpar_campo_opcao();
                    escrever_msg("Opcao invalida! Digite novamente...");
                    getch();
                    limpar_campo_opcao();
                }
            }while(confirmacao < 1 || confirmacao > 2);

            if(confirmacao == 1)
            {
                P = (ApontadorFinanceiro)malloc(sizeof(ItemFinanceiro));
                P->anterior = NULL;
                P->proximo = NULL;
                P->conteudo = temporario;

                if(lista_fi->primeiro == NULL)
                {
                    lista_fi->primeiro = P;
                    lista_fi->ultimo = P;
                }
                else 
                {
                    lista_fi->ultimo->proximo = P;
                    P->anterior = lista_fi->ultimo;
                    lista_fi->ultimo = P;
                }
            }
        }while (confirmacao < 1 || confirmacao > 2);

        // Verificar se o usuário quer repetir o cadastro novamente
        do 
        {
            limpar_campo_opcao();
            escrever_msg("Cadastrar outra movimentacao? (1 - S/2 - N): ");
            scanf("%d", &opcao);
            if(opcao < 1 || opcao > 2)
            {
                limpar_campo_opcao();
                escrever_msg("Opcao invalida! Digite novamente...");
                getch();
                limpar_campo_opcao();
            }
        }while(opcao < 1 || opcao > 2);
    }while(opcao != 2);

    return;
}