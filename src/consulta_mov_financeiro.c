/*
Autor: Milena
Data: 26/11/24.
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void ConsultaMovimentacaoFinanceira(Lista *lista, ListaFinanceira *lista_fi)
{
    int resp;
    int Cdg_ContaDesejada;
    int linha;
    Conteudo_Conta Conta;
    ApontadorFinanceiro resultado;
    Apontador aux;
    int codigo_conta;

    Apontador Retornar_codigo(Lista * lista, int codigo_conta);
    {

        // Criando um apontador auxiliar para inicializar apontando para o primeiro da lista
        Apontador aux = lista->primeiro;

        // Percorre a lista até encontrar o código da conta ou até chegar ao final da lista
        while (aux != NULL)
        {
            if (aux->conteudo.codigo_conta == codigo_conta)
            {
                return aux; // Retorna o ponteiro do item encontrado
            }
            aux = aux->proximo; // Avança para o próximo item na lista
        }

        // Retorna NULL caso não encontre a conta com o código fornecido
        return NULL;
    }
    do
    {
        tela();
        tela_consulta_Financeira();

        gotoxy(23, 03);
        printf("CONSULTA MOVIMENTACOES DA CONTA");

        gotoxy(19, 05);
        scanf("%d", &Conta.codigo_conta);
        aux = Retornar_codigo(lista, &Conta.codigo_conta);

        if (aux == NULL)
        {
            gotoxy(07, 23);
            printf("Conta nao encontrada.");
            getch();
            continue;
        }

        gotoxy(12, 05);
        printf("%s", aux->conteudo.banco);

        gotoxy(29, 05);
        printf("Agencia: %s", aux->conteudo.agencia);

        gotoxy(44, 05);
        printf("Cta: %s", aux->conteudo.numero_conta);

        gotoxy(57, 05);
        printf("Tp: %s", aux->conteudo.tipo_conta);

        if (strcmp(aux->conteudo.tipo_conta, "Corrente") == 0)
        {
            gotoxy(61, 05);
            printf("Corrente");
            break;
        }
        else if (strcmp(aux->conteudo.tipo_conta, "Poupanca") == 0)
        {
            gotoxy(61, 05);
            printf("Poupanca");
            break;
        }
        else if (strcmp(aux->conteudo.tipo_conta, "Cartao de Credito") == 0)
        {
            gotoxy(61, 05);
            printf("Cartao de Credito");
            break;
        }

        Cdg_ContaDesejada = Conta.codigo_conta;
        resultado = lista_fi->primeiro; // Inicia a busca desde o primeiro

        linha = 9;

        while (resultado != NULL)
        {

            if (resultado->conteudo.codigo_conta == Cdg_ContaDesejada)
            {
                gotoxy(2, linha);
                printf("%s", resultado->conteudo.dt_movimento);
                gotoxy(13, linha);
                printf("%s", resultado->conteudo.destinatario);

                if (strcmp(resultado->conteudo.tp_movimentacao, "Debito") == 0)
                {
                    gotoxy(43, linha);
                    printf("Debito");
                    break;
                }
                else if (strcmp(resultado->conteudo.tp_movimentacao, "Credito") == 0)
                {
                    gotoxy(43, linha);
                    printf("Credito");
                    break;
                }

                gotoxy(57, linha);
                printf("R$%.2lf", resultado->conteudo.vl_movimento);

                gotoxy(69, linha);
                printf("R$%.2lf", resultado->conteudo.vl_saldo);

                linha++;

                // Se a tela encheu, pede para continuar
                if (linha > 20)
                {
                    gotoxy(7, 23);
                    printf("Pressione qualquer tecla para continuar...");
                    getch();
                    tela_consulta_Financeira();
                    linha = 9; // Reinicia a contagem de linhas
                }
            }

            resultado = resultado->proximo;
        }

        gotoxy(07, 23);
        printf("Deseja consultar outro codigo? 1-SIM, 2-NAO: ");
        scanf("%d", &resp);
    } while (resp != 2);
    return;
}