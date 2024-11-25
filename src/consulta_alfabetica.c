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

    tela();
    //TelaOrdemAlfabetica();

    // Verifica se a lista esta vazia
    if (lista->primeiro == NULL)
    {
        gotoxy(7, 23);
        printf("A lista está vazia.");
        return;
    }

    // Criar uma copia da lista original
    Lista lista_temporaria;
    lista_temporaria.primeiro = NULL;
    lista_temporaria.ultimo = NULL;

    // Cria um apontador auxiliar 
    Apontador aux = lista->primeiro;
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

    Conteudo_Conta aux2; // Declarar aux fora do loop interno

    while (atual->proximo != NULL)
    {
        if (strcmp(atual->conteudo.banco, atual->proximo->conteudo.banco) > 0)
        {
            // Troca os conteúdos usando aux
            aux2 = atual->conteudo;  // Salvar conteúdo do nó atual
            atual->conteudo = atual->proximo->conteudo;
            atual->proximo->conteudo = aux2;
            trocou = 1;
        }
        atual = atual->proximo;  // Avançar para o próximo nó
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
        printf("%s", atual->conteudo.agencia);

        gotoxy(30, linha);
        printf("%s", atual->conteudo.numero_conta);

        gotoxy(39, linha);
        if (strcmp(atual->conteudo.tipo_conta, "Corrente") == 0)
        {
            printf("Corrente");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Poupanca") == 0)
        {
            printf("Poupanca");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Cartao de credito") == 0){
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
            TelaLinhasConsulta(); // Redesenha tela
            linha = 7;             // Reinicia a contagem de linhas
        }

        atual = atual->proximo;
    }

    limpar_campo_opcao();
    gotoxy(07, 23);
    printf("Pressione qualquer tecla para continuar...");
    getch();
    limpar_campo_opcao();
    return;
}