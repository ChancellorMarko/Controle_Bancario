/*
Autor: Milena
Data: 20/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Consulta_ordemCodigo(Lista *lista)
{

    int trocou;
    int linha;
    int x;
    Apontador atual;
    Apontador anterior = NULL;

    tela();
    TelaLinhasConsulta();

    if (lista->primeiro == NULL || lista->primeiro->proximo == NULL)
    {
        // Lista vazia ou com apenas um elemento
        gotoxy(07, 23);
        printf("A lista está vazia.");
        return;
    }

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

    // Criar uma cópia da lista original
    Lista lista_temporaria;
    lista_temporaria.primeiro = NULL;
    lista_temporaria.ultimo = NULL;

    // Cria um ponteiro auxiliar 
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

    do
    {
        trocou = 0;
        atual = lista_temporaria.primeiro;

        while (atual->proximo != anterior)
        {
            if (atual->conteudo.codigo_conta > atual->proximo->conteudo.codigo_conta)
            {
                // Troca os conteudos
                Conteudo_Conta aux2 = atual->conteudo;
                atual->conteudo = atual->proximo->conteudo;
                atual->proximo->conteudo = aux2;
                trocou = 1;
            }
            atual = atual->proximo;
        }

        // Atualiza o ultimo elemento
        anterior = atual;

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
        printf("%s", atual->conteudo.agencia);

        gotoxy(30, linha);
        printf("%s", atual->conteudo.numero_conta);

        gotoxy(39, linha);
        if (strcmp(atual->conteudo.tipo_conta, "Cartao de credito") == 0)
        {
            printf("Corrente");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Poupanca") == 0)
        {
            printf("Poupanca");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Cartao de Credito") == 0){
            printf("Cartao de Credito");
        }

        gotoxy(49, linha);
        printf("R$%.2lf", atual->conteudo.vl_saldo);

        gotoxy(62, linha);
        printf("R$%.2lf", atual->conteudo.vl_limite);

        gotoxy(78, linha);
        printf("%s", atual->conteudo.status);

        linha++; // Avança para a próxima linha

        if (linha > 20)
        { // Caso a tela encha
            gotoxy(07, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            TelaLinhasConsulta(); 
            linha = 7;             // Reinicia a contagem de linhas
        }

        atual = atual->proximo;
    }
    gotoxy(07, 23);
    printf("Pressione qualquer tecla para continuar...");
    getch();
    return;
}