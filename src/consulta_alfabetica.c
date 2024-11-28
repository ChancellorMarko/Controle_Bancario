/*
Autor: Milena
Data: 23/11/24.
Membros:
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Consulta_alfabetica(Lista *lista)
{
    int trocou;  
    int linha; 
    int x;
    Apontador atual;    // Apontador auxiliar para percorrer a lista
    Apontador novoItem; // Apontador usado para criar um novo nó

    tela();

    gotoxy(20, 3);
    printf("[Consulta por ordem alfabetica]");

    // Verifica se a lista está vazia
    if (lista->primeiro == NULL)
    {
        gotoxy(7, 23);
        printf("A lista está vazia.");
        return; // Sai da função.
    }

    // Desenha a linha horizontal
    for (x = 1; x < 79; x++)
    {
        gotoxy(x, 6);
        printf("-");
    }
    gotoxy(1, 6);
    printf("+");
    gotoxy(79, 6);
    printf("+");
    gotoxy(2, 5);
    printf("N |Banco          |N.Ag    |N.Con  |Tipo.C    |Saldo     |Limite   |Status");

    // Cria uma lista temporária sem alterar a lista original
    Lista lista_temporaria;
    // Inicializa a lista temporária como vazia
    lista_temporaria.primeiro = NULL;
    lista_temporaria.ultimo = NULL;

    // Copia os elementos da lista original para a lista temporária
    Apontador aux = lista->primeiro; // Apontador auxiliar inicia no primeiro elemento da lista original
    while (aux != NULL)
    {
        // Aloca memória para um novo nó.
        novoItem = (Apontador)malloc(sizeof(Item));
        novoItem->conteudo = aux->conteudo; // Copia o conteúdo do nó atual
        novoItem->proximo = NULL;

        // Adiciona o novo nó à lista temporária
        if (lista_temporaria.primeiro == NULL)
        {
            lista_temporaria.primeiro = novoItem; // Define o primeiro nó
            lista_temporaria.ultimo = novoItem;   // Atualiza o último nó
        }
        else
        {
            lista_temporaria.ultimo->proximo = novoItem; // Conecta o nó no final
            lista_temporaria.ultimo = novoItem;          // Atualiza o último nó
        }

        aux = aux->proximo; // Move para o próximo nó da lista original
    }

    do
    {
        // Inicializa o controle de troca como falso
        trocou = 0;
        atual = lista_temporaria.primeiro;

        // Variável para trocar de conteúdo
        Conteudo_Conta aux2;

        // Percorre os nós enquanto houver um próximo
        while (atual->proximo != NULL)
        {
            // Compara os nome dos bancoss
            if (strcmp(atual->conteudo.banco, atual->proximo->conteudo.banco) > 0)
            {
                aux2 = atual->conteudo;

                // Atualiza o nó atual com o próximo
                atual->conteudo = atual->proximo->conteudo;

                // Atualiza o próximo com o conteúdo salvo
                atual->proximo->conteudo = aux2;

                // Simboliza que a houve a troca
                trocou = 1;
            }
            atual = atual->proximo;
        }
    } while (trocou); // Continua enquanto tiver trocas para fazer

    // Começa na linha 7 da tela
    linha = 7;
    atual = lista_temporaria.primeiro;

    // Exibe os dados de cada nó
    while (atual != NULL)
    {
        gotoxy(2, linha);
        printf("%d", atual->conteudo.codigo_conta);

        gotoxy(5, linha);
        printf("%s", atual->conteudo.banco);

        gotoxy(21, linha);
        printf("%s", atual->conteudo.agencia);

        gotoxy(30, linha);
        printf("%s", atual->conteudo.numero_conta);

        // Faz uma comparação que se o tipo da conta for X vai printar o mesma escrita na tela
        gotoxy(38, linha);
        if (strcmp(atual->conteudo.tipo_conta, "Corrente") > 0)
        {
            printf("Corrente");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Poupanca") > 0)
        {
            printf("Poupanca");
        }
        else if (strcmp(atual->conteudo.tipo_conta, "Cartao de Credito") > 0)
        {
            printf("Cartao de Credito");
        }
        else
        {
            printf("Tipo Desconhecido");
        }

        // Continua exibindo os dados na tela
        gotoxy(49, linha);
        printf("R$%.2lf", atual->conteudo.vl_saldo);

        gotoxy(60, linha);
        printf("R$%.2lf", atual->conteudo.vl_limite);

        gotoxy(70, linha);
        printf("%s", atual->conteudo.status);

        linha++; // Avança para a próxima linha

        // Aqui verifica se a tela está cheia
        if (linha > 20)
        {
            gotoxy(07, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            // Reinicia a contagem de linhas
            linha = 7;
        }

        atual = atual->proximo; // Avança para o próximo nó
    }

    limpar_campo_opcao();
    gotoxy(07, 23);
    printf("Pressione qualquer tecla para continuar...");
    getch();
    limpar_campo_opcao();
    return;
}
