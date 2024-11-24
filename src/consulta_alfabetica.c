/*
Autor: Milena
Data: 21/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Consulta_alfabetica(Lista *lista)
{
    int trocou;
    int linha;
    int x;
    Apontador atual;
    Apontador aux;
    Apontador novoItem;

    tela();

    // Verifica se a lista esta vazia
    if (lista->primeiro == NULL)
    {
        escrever_msg("A lista esta vazia.");
        getch();
        limpar_campo_opcao();
        return;
    }

    // Criar uma copia da lista original
    Lista lista_temporaria;
    lista_temporaria.primeiro = NULL;
    lista_temporaria.ultimo = NULL;

    // Desenhar cabeçalho
    for(x = 1; x < 79; x++)
    {
        gotoxy(x, 6);
        printf("-");
    }
    gotoxy(1, 6);
    printf("+");
    gotoxy(79, 6);
    printf("+");
    gotoxy(2, 5);
    printf("N |Banco               |N.Ag  |N.Con  |Tipo.C  |Saldo      |Limite   |Status");

    aux = lista->primeiro;
    while (aux != NULL)
    {
        novoItem = (Apontador)malloc(sizeof(Item));
        novoItem->conteudo = aux->conteudo;
        novoItem->proximo = NULL;
        if (lista_temporaria.primeiro == NULL)
        {
            lista_temporaria.primeiro = novoItem;
            lista_temporaria.ultimo = novoItem;
        }
        else
        {
            lista_temporaria.ultimo->proximo = novoItem;
            lista_temporaria.ultimo = novoItem;
        }
        aux = aux->proximo;
    }

    // Ordenação da copia da lista baseada no Banco
    do
    {
        trocou = 0;
        atual = lista_temporaria.primeiro;

        while (atual->proximo != NULL)
        {
            if (strcmp(atual->conteudo.banco, atual->proximo->conteudo.banco) > 0)
            {
                // Troca os conteudos
                Conteudo_Conta aux = atual->conteudo;
                atual->conteudo = atual->proximo->conteudo;
                atual->proximo->conteudo = aux;
                trocou = 1;
            }
            atual = atual->proximo;
        }
    } while (trocou);

    linha = 7; // Começa abaixo
    atual = lista_temporaria.primeiro;

    while (atual != NULL)
    {
        gotoxy(2, linha);
        printf("%d", atual->conteudo.codigo_conta);

        gotoxy(5, linha);
        printf("%s", atual->conteudo.banco);

        gotoxy(26, linha);
        printf("%s", atual->conteudo.agencia);

        gotoxy(33, linha);
        printf("%s", atual->conteudo.numero_conta);

        gotoxy(40, linha);
        printf("%s", atual->conteudo.tipo_conta);

        gotoxy(49, linha);
        printf("R$%.2lf", atual->conteudo.vl_saldo);

        gotoxy(62, linha);
        printf("R$%.2lf", atual->conteudo.vl_limite);

        gotoxy(72, linha);
        printf("%s", atual->conteudo.status);

        linha++; // Avança para a próxima linha

        if (linha > 20)
        { // Caso a tela encha
            gotoxy(07, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            tela(); // Redesenha tela
            // Desenhar cabeçalho
            for(x = 1; x < 79; x++)
            {
                gotoxy(x, 6);
                printf("-");
            }
            gotoxy(1, 6);
            printf("+");
            gotoxy(79, 6);
            printf("+");
            gotoxy(2, 5);
            printf("N |Banco               |N.Ag  |N.Con  |Tipo.C  |Saldo      |Limite   |Status");
            linha = 7; // Reinicia a contagem de linhas
        }

        atual = atual->proximo;
    }
    escrever_msg("Pressione qualquer tecla para continuar...");
    getch();
    limpar_campo_opcao();
    return;
}