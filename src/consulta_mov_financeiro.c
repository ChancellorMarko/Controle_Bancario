/*
Autor: Milena
Data: 26/11/24
Membros:
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de várias contas bancárias.
*/

#include "global.h" 


// Função que retorna um ponteiro para um nó específico da lista de acordo com o código da conta 
Apontador Retornar_codigo(Lista *lista, int codigo_conta)
{
    Apontador aux = lista->primeiro;

    // Loop que percorre os nós da lista até encontrar o nó que o usuário deseja
    while (aux != NULL)
    {
        // Verifica se o código do nó atual é igual ao código procurado
        if (aux->conteudo.codigo_conta == codigo_conta)
        {
            // Retorna o ponteiro do nó encontrado
            return aux;
        }
        // Percorre ate o proximo no da listta
        aux = aux->proximo;
    }
    return NULL;
}

void ConsultaMovimentacaoFinanceira(ListaFinanceira *lista_fi, Lista *lista_co)
{
    // Validacão se as listas de contas e financeiras não são nulas
    if (lista_co == NULL || lista_fi == NULL) {
        printf("Erro: Lista nula.\n");
        return; 
    }

    int resp; // Resposta do usuário 
    int linha; // Variável para controlar a linha de exibição 
    Conteudo_Conta Conta;
    ApontadorFinanceiro resultado; // Ponteiro para percorrer a lista de movimentações financeiras
    Apontador aux; // Ponteiro para buscar a conta desejada na lista de contas

    do {
        
        tela();
        tela_consulta_Financeira();

        gotoxy(20, 03);
        printf("[Consulta de movimentacoes da conta]");

        gotoxy(10, 05);
        scanf("%d", &Conta.codigo_conta);

        // Chama a função para buscar o ponteiro do item da conta com o código X
        aux = Retornar_codigo(lista_co, Conta.codigo_conta);

        // Verificando se a conta foi encontrada
        if (aux == NULL) {
            gotoxy(07, 23);
            printf("Conta nao encontrada."); 
            getch(); 
            continue; 
        }

        // Exibe os dados 
        gotoxy(12, 05);
        printf(" - %s", aux->conteudo.banco); 
        gotoxy(29, 05);
        printf("Agencia: %s", aux->conteudo.agencia); 
        gotoxy(44, 05);
        printf("Cta: %s", aux->conteudo.numero_conta); 
        gotoxy(57, 05);
        printf("Tp: %s", aux->conteudo.tipo_conta); 

        // Faz uma comparação e identifica qual o tipo da conta fazendo assim exibir o tipo na tela
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

        // Inicializa o ponteiro para percorrer a lista de movimentações financeiras
        resultado = lista_fi->primeiro;
        // Linha inicial para exibição das movimentações
        linha = 9;

        // Loop
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
                // Avança para a próxima linha
                linha++; 

                // Se a tela estiver cheia, o usuário visualiza dai reinicia a interface
                if (linha > 20) {
                    gotoxy(7, 23);
                    printf("Pressione qualquer tecla para continuar...");
                    getch(); 
                    tela_consulta_Financeira();
                    // Redefine a linha inicial
                    linha = 9; 
                }
            }

            // Avança para a próxima movimentação na lista
            resultado = resultado->proximo;
        }

        // Caso nenhuma movimentação tenha sido encontrada
        if (linha == 9) {
            escrever_msg("Nenhuma movimentacao encontrada para esta conta.");
            getch(); 
        }

        escrever_msg("Deseja consultar outro codigo? [1-S, 2-N]: ");
        gotoxy(50, 23);
        scanf("%d", &resp);

    } while (resp != 2); 

    return; 
}
