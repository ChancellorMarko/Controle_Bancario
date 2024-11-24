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
void Remover(Lista *lista, ListaFinanceira *lista_fi, int opcao_lista)
{
    //Declaração das Variáveis
    int opcao;
    int resp;
    int posicao;
    int x;
    Apontador aux;
    Apontador P;
    Apontador R;

    do
    {
        tela();

        opcao = 0;
        resp = 0;
        posicao = 0;

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
            printf("A lista esta vazia! Voltando...");
            getch();
            return;
        }

        // Remover no final da lista
        if(opcao_lista == 1){
            // Mostrar o que vai ser removido e perguntar se o usuário tem certeza
            tela_conta(lista->ultimo);
            if(Verificar_Existencia_Movimentacao(lista_fi, lista->ultimo->conteudo.codigo_conta))
            {
                limpar_campo_opcao();
                escrever_msg("Operacao impedida! Conta possui movimentacoes ela sera desativada");
                strcpy(lista->ultimo->conteudo.status, DESATIVADO);
                getch();
                return;
            }
            else 
            {
                do 
                {
                    limpar_campo_opcao();
                    gotoxy(7, 23);
                    printf("Deseja excluir esse cadastro? (1 -S/2 - N): ");
                    scanf("%d", &resp);
                    if(resp < 1 || resp > 2)
                    {
                        limpar_campo_opcao();
                        escrever_msg("Opcao invalida! Digite novamente...");
                        getch();
                        limpar_campo_opcao();
                    }
                    if (resp == 2) 
                    {
                        return;
                    }
                }while(resp < 1 || resp > 2);

                // Verificar se a lista está vazia
                if (lista->primeiro == NULL) {
                    limpar_campo_opcao();
                    escrever_msg("Lista ja esta vazia!");
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
                    escrever_msg("Elemento removido. Agora a lista esta vazia.");
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
                escrever_msg("Ultimo item da lista removido com sucesso!");
                getch();
                limpar_campo_opcao();
            }
        }

        //Remover no inicio da lista
        if(opcao_lista == 2){
            // Mostrar o que vai ser removido e perguntar se o usuário tem certeza
            tela_conta(lista->primeiro);
            if(Verificar_Existencia_Movimentacao(lista_fi, lista->primeiro->conteudo.codigo_conta))
            {
                limpar_campo_opcao();
                escrever_msg("Operacao impedida! Conta possui movimentacoes ela sera desativada");
                strcpy(lista->primeiro->conteudo.status, DESATIVADO);
                getch();
                return;
            }
            else 
            {
                
                do 
                {
                    limpar_campo_opcao();
                    gotoxy(7, 23);
                    printf("Deseja excluir esse cadastro? (1 -S/2 - N): ");
                    scanf("%d", &resp);
                    if(resp < 1 || resp > 2)
                    {
                        limpar_campo_opcao();
                        escrever_msg("Opcao invalida! Digite novamente...");
                        getch();
                        limpar_campo_opcao();
                    }
                    if (resp == 2) 
                    {
                        return;
                    }
                }while(resp < 1 || resp > 2);

                // Verifica se a lista está vazia
                if (lista->primeiro == NULL) {
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
                if (lista->primeiro == NULL) {
                    lista->ultimo = NULL;
                }

                //Remove o nó 
                free(aux);
                limpar_campo_opcao();
                escrever_msg("Primeiro item da lista removido com sucesso.");
                getch();
                limpar_campo_opcao();
            }
        }

        //Remover em uma posição da lista
        if(opcao_lista == 3){
            
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Digite qual a posicao que deseja remover: ");
            scanf("%d", &posicao);
            //Verificar se a lista está vazia
            if (lista->primeiro == NULL) {
                limpar_campo_opcao();
                escrever_msg("A lista ja esta vazia!");
                getch();
                limpar_campo_opcao();
                return;
            }
            // Percorre até o nó anterior da posição desejada
            P = lista->primeiro;
            for (int x = 0; x < posicao - 1 && P != NULL; x++) {
            P = P->proximo;
            }

            // Verificar se a posição é válida
            if (P == NULL || P->proximo == NULL) {
                printf("Posição invalida!");
                return;
            }

            // Mostrar o que vai ser removido e perguntar se o usuário tem certeza
            tela_conta(P);
            if(Verificar_Existencia_Movimentacao(lista_fi, P->conteudo.codigo_conta))
            {
                limpar_campo_opcao();
                escrever_msg("Operacao impedida! Conta possui movimentacoes ela sera desativada");
                strcpy(lista->primeiro->conteudo.status, DESATIVADO);
                getch();
                return;
            }
            else 
            {
                do 
                {
                    limpar_campo_opcao();
                    gotoxy(7, 23);
                    printf("Deseja excluir esse cadastro? (1 -S/2 - N): ");
                    scanf("%d", &resp);
                    if(resp < 1 || resp > 2)
                    {
                        limpar_campo_opcao();
                        escrever_msg("Opcao invalida! Digite novamente...");
                        getch();
                        limpar_campo_opcao();
                    }
                    if (resp == 2) 
                    {
                        return;
                    }
                }while(resp < 1 || resp > 2);

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
                printf("Elemento na posicao %d removido com sucesso.", posicao);
                getch();
                limpar_campo_opcao();
            }
        }
    } while(opcao != 0);  
    
    return;
}
