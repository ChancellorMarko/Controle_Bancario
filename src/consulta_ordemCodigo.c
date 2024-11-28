/*
Autor: Milena
Data: 20/11/24
Membros:
    1 - 178292-2024 - Marcos
    2 - 177020-2024 - Milena
Descrição: Programa para gerenciamento de várias contas bancárias.
*/

#include "global.h"

void Consulta_ordemCodigo(Lista *lista)
{
    int trocou;
    int linha;
    int x;
    Apontador atual;           // Ponteiro auxiliar para percorrer a lista
    Apontador anterior = NULL; // Marca o último elemento colocado na lista

    // Desenha a interface da tela de consulta
    TelaLinhasConsulta();
    tela();

    gotoxy(25, 3);
    printf("[Consulta por ordem numerica]");

    // Verifica se a lista ta vazia ou se tem apenas um elemento
    if (lista->primeiro == NULL || lista->primeiro->proximo == NULL)
    {
        gotoxy(07, 23);
        printf("A lista está vazia.");
        return;
    }

    // Desenhando uma linha horizontal
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
    // Títulos do cabeçario
    printf("N |Banco           |N.Ag   |N.Con  |Tipo.C    |Saldo     |Limite   |Status");

    // Cria uma cópia da lista original
    Lista lista_temporaria;
    lista_temporaria.primeiro = NULL; // Esses dois inicizam a lista como vazia
    lista_temporaria.ultimo = NULL;

    // Percorre a lista original
    Apontador aux = lista->primeiro;
    while (aux != NULL)
    {
        // Cria um novo nó para a lista temporária
        Apontador novoItem = (Apontador)malloc(sizeof(Item));
        // Copia o conteúdo do nó atual
        novoItem->conteudo = aux->conteudo;
        novoItem->proximo = NULL;

        // Insere o novo nó na lista temporária caso ela esteja vazia
        if (lista_temporaria.primeiro == NULL)
        {
            // Faz vom que a lista (que ta vazia) receba o primeiro e ultimo nó
            lista_temporaria.primeiro = novoItem;
            lista_temporaria.ultimo = novoItem;
        }
        else
        {
            // Caso não seja vazia, o próximo do último da lista temporária recebe o novo item
            lista_temporaria.ultimo->proximo = novoItem;
            // Define que agora o nó inserido é o último da lista
            lista_temporaria.ultimo = novoItem;
        }

        // Avança para o próximo nó na lista original
        aux = aux->proximo;
    }

    // Ordenando a lista temporária em ordem crescente pelo código da conta bancária
    do
    {
        // Inicializa a troca
        trocou = 0;
        atual = lista_temporaria.primeiro; // Inicializando pelo primeiro nó

        // Percorre a lista até o último elemento
        while (atual->proximo != anterior)
        {
            // Compara os códigos do nó atual com o próximo do atual
            if (atual->conteudo.codigo_conta > atual->proximo->conteudo.codigo_conta)
            {
                // Troca os conteúdos se estiverem fora de ordem
                Conteudo_Conta aux2 = atual->conteudo;
                atual->conteudo = atual->proximo->conteudo;
                atual->proximo->conteudo = aux2;
                // Indica que houve uma troca
                trocou = 1;
            }
            // Avnaça para o próximo nó da lista
            atual = atual->proximo;
        }

        // Marca o último elemento
        anterior = atual;
    } while (trocou); // Continua ENQUANTO houver trocas para serem feitas

    // Inicializa a linha de exibição
    linha = 7;
    atual = lista_temporaria.primeiro;

    // Exibe os elementos da conta
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

        // Aqui ira comparar que se a conta for do tipo X irá exibir uma mensagem da mesma escrita X na tela
        gotoxy(37, linha);
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

        gotoxy(49, linha);
        printf("R$%.2lf", atual->conteudo.vl_saldo);

        gotoxy(60, linha);
        printf("R$%.2lf", atual->conteudo.vl_limite);

        gotoxy(70, linha);
        printf("%s", atual->conteudo.status);

        // Avança para a próxima linha de exibição
        linha++;

        if (linha > 20)
        {
            gotoxy(07, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            TelaLinhasConsulta();
            // Reinicia a contagem de linhas
            linha = 7;
        }

        // Avança para o próximo nó
        atual = atual->proximo;
    }

    gotoxy(07, 23);
    printf("Pressione qualquer tecla para continuar...");
    getch();
    return;
}
