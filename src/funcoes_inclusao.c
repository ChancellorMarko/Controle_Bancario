/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Função de castro de contas
void Cadastro(Lista *lista, int opcao_lista)
{
    //Variaveis
    int opcao = 0;
    int resp = 0;
    int opcaoPosicao;
    int x;
    int numero_entradas_lista = 0;
    Conteudo_Conta temporario;
    Apontador Auxilar_Verificacao; // Variável para auxiliar na verificação do código do funcionário
    Apontador P;
    Apontador R;

    do
    {
        tela();

        // Mostrar opção escolhida
        if(opcao_lista == 1)
        {
            gotoxy(32,3);
            printf("[Final da Lista]");
        }
        else if(opcao_lista == 2)
        {
            gotoxy(32,3);
            printf("[Inicio da Lista]");
        }
        else if(opcao_lista == 3)
        {
            gotoxy(32,3);
            printf("[Posicao da Lista]");
        }

        // Verificar se a lista esta vazia quando for adicionar em uma posição aleatória
        if (lista->primeiro == NULL && opcao_lista == 3)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Nao existem intens na lista! Voltando a tela inicial...");
            getch();
            return;
        }

        do
        {
            gotoxy(6,6);
            printf("Codigo da Conta.....: ");
            scanf("%d", &temporario.codigo_conta);
            Auxilar_Verificacao = Verificar_Existencia(lista, temporario.codigo_conta);
            if(Auxilar_Verificacao != NULL)
            {
                limpar_campo_opcao();
                escrever_msg("Codigo de conta ja cadastrado. Digite novamente");
                getch();
                limpar_campo_opcao();
                gotoxy(28, 6);
                printf("                              ");
            }
        }while(Auxilar_Verificacao != NULL);

        if(temporario.codigo_conta == 0)
        {
            return;
        }

        gotoxy(6,8);
        printf("1 - Nome do Banco...: ");
        fflush(stdin);
        fgets(temporario.banco, 50, stdin);

        gotoxy(6,10);
        printf("2 - Agencia.........: ");
        fflush(stdin);
        fgets(temporario.agencia, 10, stdin);

        gotoxy(6,12);
        printf("3 - Numero da Conta.: ");
        fflush(stdin);
        fgets(temporario.numero_conta, 20, stdin);

        gotoxy(6,14);
        printf("4 - Tipo da Conta...: ");
        fflush(stdin);
        fgets(temporario.tipo_conta, 20, stdin);

        do
        {
            gotoxy(6,16);
            printf("5 - Saldo da Conta..: R$");
            scanf("%lf", &temporario.vl_saldo);
            if(temporario.vl_saldo < 0)
            {
                limpar_campo_opcao();
                gotoxy(07, 23);
                printf("Saldo invalido. Digite novamente.");
                getch();
                limpar_campo_opcao();
                gotoxy(24, 16);
                printf("                          ");
            }
        }while(temporario.vl_saldo < 0);

        do
        {
        gotoxy(6,18);
        printf("6 - Limite da Conta.: R$");
        scanf("%lf", &temporario.vl_limite);
        if(temporario.vl_limite < 0)
        {
            limpar_campo_opcao();
            gotoxy(07, 23);
            printf("Limite invalido. Digite novamente.");
            getch();
            limpar_campo_opcao();
            gotoxy(24, 18);
            printf("                          ");
        }
        }while(temporario.vl_limite < 0);

        gotoxy(6,20);
        printf("6 - Status da Conta.: ");
        fflush(stdin);
        fgets(temporario.status, 10, stdin);

        // Verificar resposta
        do 
        {
            gotoxy(07, 23);
            printf("Quer gravar os dados? [1-S, 2-N]: ");
            scanf("%d", &resp);
            if(resp < 0 || resp > 3)
            {
                limpar_campo_opcao();
                escrever_msg("Entrada invalida! Digite novamente...");
                getch();
                limpar_campo_opcao();
            }
        }while (resp < 0 || resp > 3);
        
        if(resp == 1)
        {
            P = (Apontador)malloc(sizeof(Item));
            P->proximo =NULL;
            P->conteudo = temporario;

            if(opcao_lista == 1)
            {
                if(lista->primeiro == NULL)
                {
                    lista->primeiro = P;
                    lista->ultimo = P;
                }
                else
                {
                    lista->ultimo->proximo = P;
                    lista->ultimo = P;
                }  
            }
            else if(opcao_lista == 2)
            {
                if(lista->primeiro == NULL)
                {
                    lista->primeiro = P;
                    lista->ultimo = P;
                }
                else
                {
                    P->proximo = lista->primeiro;
                    lista->primeiro = P;
                }
            }
            else if(opcao_lista == 3)
            {
                R = (Apontador)malloc(sizeof(Item));

                numero_entradas_lista = Contar_Elementos_Lista(lista);

                do
                {
                    limpar_campo_opcao();
                    gotoxy(7, 23);
                    printf("Em qual posicao da lista? (Quant.Itens: %d):", numero_entradas_lista);
                    scanf("%d", &opcaoPosicao);
                    limpar_campo_opcao();
                    if(opcaoPosicao < 0 || opcaoPosicao > numero_entradas_lista)
                    {
                        limpar_campo_opcao();
                        escrever_msg("Opcao invalida! Digite novamente...");
                        getch();
                        limpar_campo_opcao();
                    }
                }while(opcaoPosicao < 0 || opcaoPosicao > numero_entradas_lista);

                P = lista->primeiro; // Identificar o começo da lista
                // Percorrer a lista até a posição solicitada
                for(x = 0;x <= opcaoPosicao - 2;x++)
                {
                    P = P->proximo;
                }

                R->conteudo = temporario; // Ponteiro auxiliar recebe o conteudo digitado
                R->proximo = P->proximo; // Ponteiro auxiliar recebe a posição de proximo item
                P->proximo = R; // Ponteiro escolhido recebe o valor digitado
            }
        }

        // Verificar se quer cadastrar outro
        do
        {
            gotoxy(07, 23);
            printf("Quer cadastrar outro? 1-Sim, 2-Nao: ");
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > 3)
            {
                limpar_campo_opcao();
                escrever_msg("Entrada invalida! Digite novamente...");
                getch();
                limpar_campo_opcao();
            }
        }while(opcao < 0 || opcao > 3);
    }while(opcao != 2);
}