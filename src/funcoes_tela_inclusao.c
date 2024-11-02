// Funções de inclusão de conta

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "global.h"

// Função de castro de contas
void Cadastro(Lista *lista, int posicao_na_lista)
{
    //Variaveis
    int opcao = 0;
    int resp = 0;
    int opcaoPosicao;
    int x;
    int numero_entradas_lista = 0;
    Conteudo_Conta temporario;
    Apontador P;
    Apontador R;

    do
    {
        tela();

        // Mostrar opção escolhida
        if(posicao_na_lista == 1)
        {
            gotoxy(32,3);
            printf("[Final da Lista]");
        }
        else if(posicao_na_lista == 2)
        {
            gotoxy(32,3);
            printf("[Inicio da Lista]");
        }
        else if(posicao_na_lista == 3)
        {
            gotoxy(32,3);
            printf("[Posicao da Lista]");
        }

        // Verificar se a lista esta vazia quando for adicionar em uma posição aleatória
        if (lista->primeiro == NULL && posicao_na_lista == 3)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Nao existem intens na lista! Voltando a tela inicial...");
            getch();
            return;
        }

        temporario = tela_cadastro_conta(lista);
        if(temporario.codigo_conta == 0)
        {
            return;
        }
       
        gotoxy(07, 23);
        printf("Quer gravar os dados? [1-S, 2-N]: ");
        scanf("%d", &resp);
        limpar_campo_opcao();
        if(resp == 1)
        {
            P = (Apontador)malloc(sizeof(Item));
            P->proximo =NULL;
            P->conteudo = temporario;

            if(posicao_na_lista == 1)
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
            else if(posicao_na_lista == 2)
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
            else if(posicao_na_lista == 3)
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
                        gotoxy(7, 23);
                        printf("Opcao Invalida!");
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
        limpar_campo_opcao();
        gotoxy(07, 23);
        printf("Quer cadastrar outro? 1-Sim, 2-Nao: ");
        scanf("%d", &opcao);
        limpar_campo_opcao();
    }while(opcao != 2);
}