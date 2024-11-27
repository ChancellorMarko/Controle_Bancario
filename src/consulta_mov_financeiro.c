/*
Autor: Milena
Data: 26/11/24
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de várias contas bancárias.
*/

#include "global.h"

Apontador Retornar_codigo(Lista *lista, int codigo_conta)
{

    // Criando o ponteiro auxiliar
    Apontador aux = lista->primeiro;

    // Percorre a lista até encontrar o código da conta ou até chegar ao final da lista
    while (aux != NULL)
    {
        // Verifica se o código da conta nó atual é o mesmo que estamos buscando
        if (aux->conteudo.codigo_conta == codigo_conta)
        {
            // Retorna o ponteiro do item encontrado
            return aux;
        }
        // Continua percorrendo ate encontrar o codigo
        aux = aux->proximo;
    }
    return NULL;
}

void ConsultaMovimentacaoFinanceira(ListaFinanceira *lista_fi, Lista *lista_co)
{
    if (lista_co == NULL || lista_fi == NULL) {
        printf("Erro: Lista nula.\n");
        return;
    }

    int resp;
    int linha;
    Conteudo_Conta Conta;
    ApontadorFinanceiro resultado;
    Apontador aux;

    do {
        tela();
        tela_consulta_Financeira();

        gotoxy(20, 03);
        printf("[Consulta de movimentacoes da conta]");

        gotoxy(10, 05);
        scanf("%d", &Conta.codigo_conta);

        aux = Retornar_codigo(lista_co, Conta.codigo_conta);

        if (aux == NULL) {
            gotoxy(07, 23);
            printf("Conta nao encontrada.");
            getch();
            continue;
        }

        gotoxy(12, 05);
        printf(" - %s", aux->conteudo.banco);
        gotoxy(29, 05);
        printf("Agencia: %s", aux->conteudo.agencia);
        gotoxy(44, 05);
        printf("Cta: %s", aux->conteudo.numero_conta);
        gotoxy(57, 05);
        printf("Tp: %s", aux->conteudo.tipo_conta);

        if (strcmp(aux->conteudo.tipo_conta, "Corrente") == 0) {
            gotoxy(61, 05);
            printf("Corrente");
        } else if (strcmp(aux->conteudo.tipo_conta, "Poupanca") == 0) {
            gotoxy(61, 05);
            printf("Poupanca");
        } else if (strcmp(aux->conteudo.tipo_conta, "Cartao de Credito") == 0) {
            gotoxy(61, 05);
            printf("Cartao de Credito");
        }

        resultado = lista_fi->primeiro;
        linha = 9;

        while (resultado != NULL) {
            if (resultado->conteudo.codigo_conta == Conta.codigo_conta) {
                gotoxy(2, linha);
                printf("%s", resultado->conteudo.dt_movimento);
                gotoxy(13, linha);
                printf("%s", resultado->conteudo.destinatario);
                gotoxy(43, linha);
                printf("%s", resultado->conteudo.tp_movimentacao);
                gotoxy(57, linha);
                printf("R$%.2lf", resultado->conteudo.vl_movimento);
                gotoxy(69, linha);
                printf("R$%.2lf", resultado->conteudo.vl_saldo);
                linha++;

                if (linha > 20) {
                    gotoxy(7, 23);
                    printf("Pressione qualquer tecla para continuar...");
                    getch();
                    tela_consulta_Financeira();
                    linha = 9;
                }
            }

            resultado = resultado->proximo;
        }

        if (linha == 9) {
            gotoxy(7, 23);
            printf("Nenhuma movimentacao encontrada para esta conta.");
            getch();
        }

        gotoxy(07, 23);
        printf("Deseja consultar outro codigo? [1-S, 2-N]: ");
        gotoxy(50, 23);
        scanf("%d", &resp);
    } while (resp != 2);

    return;
}

