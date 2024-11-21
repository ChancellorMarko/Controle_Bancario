/*
Autor: Milena.
Data: 12/11/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"


void Remover(Lista *lista, int opcao_lista)
{
    //Declaração das Variáveis
    int opcao = 0;
    int resp = 0;
    int Posicao;
    int x;
    Apontador aux;
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
            printf("A lista está vazia! Voltando a tela inicial...");
            getch();
            return;
        }

        // Remover no final da lista
        if(resp == 1){

            // Verificar se a lista está vazia
            if (lista->primeiro == NULL) {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("Lista já está vazia!");
                getch();
                limpar_campo_opcao();
                return;
            }

            // Caso haja apenas um elemento na lista
            if (lista->primeiro == lista->ultimo) {
                free(lista->primeiro);
                lista->primeiro = NULL;
                lista->ultimo = NULL;
                limpar_campo_opcao();
                gotoxy(7,23);
                printf("Elemento removido. Agora a lista está vazia.");
                getch();
                limpar_campo_opcao();
                return;
            }
            // Percorrer até o penúltimo
            aux = lista->primeiro;
            while(aux->proximo != lista->ultimo){
                aux = aux->proximo;
            }
            // Remover o último nó
            free(lista->ultimo);
            lista->ultimo = aux;
            lista->ultimo->proximo = NULL;
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Ultimo da lista removido com sucesso!");
        }

        //Remover no inicio da lista
        if(resp == 2){

            // Verifica se a lista está vazia
            if (lista->primeiro == NULL) {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("A Lista ja esta vazia!");
                getch();
                limpar_campo_opcao();
                return;
            }

             aux = lista->primeiro;

            // Atualiza o ponteiro 'primeiro' para o próximo nó
            aux->proximo = lista->primeiro;

            // Se o nó removido for o único elemento, atualiza o ponteiro 'ultimo'
            if (lista->primeiro == NULL) {
            lista->ultimo = NULL;
            }

            //Remove o nó 
            free(aux);
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Primeiro da lista removido com sucesso.");
            getch();
            limpar_campo_opcao();
        }

        //Remover em uma posição da lista
        if(resp == 3){
            
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Digite qual a posicao que deseja remover: ");
            gotoxy(49, 23);
            scanf("%d", &Posicao);
            limpar_campo_opcao();

            //Verificar se a lista está vazia
            if (lista->primeiro == NULL) {
                limpar_campo_opcao();
                gotoxy(7, 23);
                printf("A lista já está vazia!");
                getch();
                limpar_campo_opcao();
                return;

            }
             // Percorre até o nó anterior da posicao desejada
             P = lista->primeiro;
            for ( x = 0; x < Posicao - 1 && P != NULL; x++) {
            P = P->proximo;
            }

            // Verificar se a posição é válida
            if (P == NULL || P->proximo == NULL) {
                printf("Posição inválida!");
                return;
            }

            // Remove o nó da posição desejada
            R = P->proximo;
            P->proximo = R->proximo;

            // Se o nó removido for o último, fazer dele o ultimo da lista
            if (R == lista->ultimo) {
            lista->ultimo = P;
            }

            free(R);
            limpar_campo_opcao();
            gotoxy(7,23);
            printf("Elemento na posicao %d removido com sucesso.", Posicao);
            getch();
            limpar_campo_opcao();
        }
    } while(opcao != 0);  
}
