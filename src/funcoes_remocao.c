/*
Autor: Milena.
Data: 12/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

// Função que realiza a remoção de itens na lista de cadastros de contas
void Remover(Lista *lista, int opcao_lista)
{
    // Declaração das Variáveis
    int opcao = 0;
    int posicao = 0;
    int resp;
    // int x;
    Apontador aux;
    Apontador P;
    Apontador R;
    

    do
    {
        tela();

        // Mostrar opção escolhida
        if (opcao_lista == 1)
        {
            gotoxy(32, 3);
            printf("[Final da Lista]");
        }
        else if (opcao_lista == 2)
        {
            gotoxy(32, 3);
            printf("[Inicio da Lista]");
        }
        else if (opcao_lista == 3)
        {
            gotoxy(32, 3);
            printf("[Posicao da Lista]");
        }

        // Verificar se a lista esta vazia quando for adicionar em uma posição aleatória
        if (lista->primeiro == NULL && opcao_lista == 3)
        {
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("A lista esta vazia! Voltando...");
            getch();
            return;
        }

        // Remover no FINAL da lista
        if (opcao_lista == 1)
        {
            // Verificar se a lista está vazia
            if (lista->primeiro == NULL)
            {
                limpar_campo_opcao();
                escrever_msg("Lista ja esta vazia!");
                getch();
                limpar_campo_opcao();
                return;
            }

            // Caso haja apenas um elemento na lista
            if (lista->primeiro == lista->ultimo)
            {
                free(lista->primeiro);
                lista->primeiro = NULL;
                lista->ultimo = NULL;
                limpar_campo_opcao();
                escrever_msg("Elemento removido. Agora a lista esta vazia.");
                getch();
                limpar_campo_opcao();
                return;
            }

            // Percorrer até o penúltimo
            aux = lista->primeiro;
            while (aux->proximo != lista->ultimo)
            {
                aux = aux->proximo;
            }

            // Cria um ponteiro auxiliar
            aux = lista->primeiro;

            while (aux->proximo != NULL)
            {
                aux = aux->proximo;

                if (aux == NULL)
                {
                    limpar_campo_opcao();
                    gotoxy(7, 23);
                    printf("Codigo nao encontrado.");
                    getch();
                    limpar_campo_opcao();
                    return;
                }
            }
            // Coloca na tela as informações da conta escolhida
            TelaExibirConta(aux);

            // Pergunta para o usuário se deseja remover o item escolhido
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Deseja remover esse item? [1-S, 2-N]: ");
            gotoxy(44, 23);
            scanf("%d", &resp);

            // Remover o último nó
            if (resp == 1)
            {
                free(lista->ultimo);
                lista->ultimo = aux;
                lista->ultimo->proximo = NULL;
                limpar_campo_opcao();
                escrever_msg("Ultimo item da lista removido com sucesso!");
                getch();
                limpar_campo_opcao();
            }

            // Remover no INÍCIO da lista
            if (opcao_lista == 2)
            {
                // Verifica se a lista está vazia
                if (lista->primeiro == NULL)
                {
                    limpar_campo_opcao();
                    escrever_msg("A Lista ja esta vazia!");
                    getch();
                    limpar_campo_opcao();
                    return;
                }

                aux = lista->primeiro;

                // Atualiza o ponteiro 'primeiro' para o próximo nó
                aux->proximo = lista->primeiro;

                // Se o nó removido for o único elemento, atualiza o ponteiro 'ultimo'
                if (lista->primeiro == NULL)
                {
                    lista->ultimo = NULL;
                }

                if (aux == NULL)
                {
                    limpar_campo_opcao();
                    escrever_msg("Codigo nao encontrado.");
                    getch();
                    limpar_campo_opcao();
                    return;
                }
            }

            // Coloca na tela as informações da conta escolhida
            TelaExibirConta(aux);

            // Pergunta para o usuário de ele deseja remover o item escolhido
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Deseja remover esse item? [1-S, 2-N]: ");
            gotoxy(44, 23);
            scanf("%d", &resp);

            if (resp == 1)
            {
                // Remove o nó
                free(aux);
                limpar_campo_opcao();
                escrever_msg("Primeiro item da lista removido com sucesso.");
                getch();
                limpar_campo_opcao();

                if (resp == 2)
                {
                    return;
                }
            }
        }

        // Remover em uma posição da lista
        if (opcao_lista == 3)
        {

            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Digite qual a posicao que deseja remover: ");
            scanf("%d", &posicao);

            // Verificar se a lista está vazia
            if (lista->primeiro == NULL)
            {
                limpar_campo_opcao();
                escrever_msg("A lista ja esta vazia!");
                getch();
                limpar_campo_opcao();
                return;
            }
            // Percorre até o nó anterior da posição desejada
            P = lista->primeiro;
            for (int x = 0; x < posicao - 1 && P != NULL; x++)
            {
                P = P->proximo;
            }

            // Verificar se a posição é válida
            if (P == NULL || P->proximo == NULL)
            {
                printf("Posição invalida!");
                return;
            }

            // Remove o nó da posição desejada
            R = P->proximo;
            P->proximo = R->proximo;

            // Se o nó removido for o último, fazer dele o ultimo da lista
            if (R == lista->ultimo)
            {
                lista->ultimo = P;
            }

            // Coloca na tela as informações da conta escolhida
            TelaExibirConta(aux);

            // Pergunta para o usuário de ele deseja remover o item escolhido
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Deseja remover esse item? [1-S, 2-N]: ");
            gotoxy(44, 23);
            scanf("%d", &resp);

            if (resp == 1)
            {
                // Remove o nó
                free(R);
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Elemento na posicao %d removido com sucesso.", posicao);
                getch();
                limpar_campo_opcao();

                if (resp == 2)
                {
                    return;
                }
            }
        }
    } while (opcao != 0);

    return;
}
