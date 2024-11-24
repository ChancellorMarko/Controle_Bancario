/*
Autor: Milena
Data: 21/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Consulta_alfabetica(Lista *lista){

    int trocou;
    int linha;
    Apontador atual;

    // Verifica se a lista esta vazia

    tela();
    //TelaOrdemAlfabetica();

    if (lista->primeiro == NULL)
    {
        gotoxy(07, 23);
        printf("A lista está vazia.");
        return;
    }

    // Criar uma copia da lista original
    Lista lista_temporaria;
    lista_temporaria.primeiro = NULL;
    lista_temporaria.ultimo = NULL;

    Apontador aux = lista->primeiro;
    while (aux != NULL)
    {
        Apontador novoItem = (Apontador)malloc(sizeof(Item));
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

        gotoxy(24, linha);
        printf("%d", atual->conteudo.agencia);

        gotoxy(30, linha);
        printf("%d", atual->conteudo.numero_conta);

        gotoxy(39, linha);
        if (atual->conteudo.tipo_conta == 'Corrente')
        {
            printf("Corrente");
        }
        else if (atual->conteudo.tipo_conta == 'Poupanca')
        {
            printf("Poupanca");
        }
        else if (atual->conteudo.tipo_conta == 'Cartao de credito'){
            printf("Cartao de Credito");
        }

        gotoxy(54, linha);
        printf("R$");
        gotoxy(56, linha);
        printf("%.2lf", atual->conteudo.vl_saldo);

        gotoxy(66, linha);
        printf("R$");
        gotoxy(68, linha);
        printf("%.2lf", atual->conteudo.vl_limite);

        gotoxy(78, linha);
        printf("%d", atual->conteudo.status);

        linha++; // Avança para a próxima linha

        if (linha > 20)
        { // Caso a tela encha
            gotoxy(07, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            TelaConsultaEmLinha(); // Redesenha tela
            linha = 7;             // Reinicia a contagem de linhas
        }

        atual = atual->proximo;
    }
    gotoxy(07, 23);
    printf("Pressione qualquer tecla para continuar...");
    getch();
    return;
}
