/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

#include "global.h"

void Tela_Alteracao(Lista *lista)
{
    Apontador auxiliar_verificacao;
    int resposta = 0;
    int resposta_repetir = 0;
    int campo_editavel = 0;

    if(lista->primeiro == NULL)
    {
        limpar_campo_opcao();
        gotoxy(7, 23);
        printf("Nao existem cadastros na lista! Retornando...");
        getch();
        limpar_campo_opcao();
        return;
    }
    else
    {
        do 
        {
            // Zerar variaveis
            resposta = 0;
            resposta_repetir = 0;
            campo_editavel = 0;

            tela();

            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Digite o codigo da conta para edita-la: ");
            scanf("%d", &resposta);
            auxiliar_verificacao = Verificar_Existencia(lista, resposta);
            if(auxiliar_verificacao == NULL)
            {
                limpar_campo_opcao();
                escrever_msg("Erro ao tentar encontrar os dados");
                getch();
                limpar_campo_opcao();
            }
            else if (auxiliar_verificacao == 0) 
            {
                return;
            }
            else 
            {
                do 
                {
                    tela_conta(auxiliar_verificacao);

                    // Editar campos do funcionario
                    do
                    {
                        limpar_campo_opcao();
                        gotoxy(7, 23);
                        printf("Digite o numero de um dos campos editaveis (0 - Sair): ");
                        scanf("%d", &campo_editavel);
                        if(campo_editavel < 0 || campo_editavel > 8)
                        {
                            limpar_campo_opcao();
                            escrever_msg("Campo invalido!");
                            getch();
                            limpar_campo_opcao();
                        }
                    }while(campo_editavel < 0 || campo_editavel > 8);

                    switch(campo_editavel)
                    {
                        case 1:
                            gotoxy(6,8);
                            printf("1 - Nome do Banco...: ");
                            gotoxy(28, 8);
                            printf("                                              ");
                            gotoxy(28, 8);
                            fflush(stdin);
                            fgets(auxiliar_verificacao->conteudo.banco, 50, stdin);
                            break;
                        case 2:
                            gotoxy(6,10);
                            printf("2 - Agencia.........: ");
                            gotoxy(28, 10);
                            printf("                                              ");
                            gotoxy(28, 10);
                            fflush(stdin);
                            fgets(auxiliar_verificacao->conteudo.agencia, 50, stdin);
                            break;
                        case 3:
                            gotoxy(6,12);
                            printf("3 - Numero da Conta.: ");
                            gotoxy(28, 12);
                            printf("                                              ");
                            gotoxy(28, 12);
                            fflush(stdin);
                            fgets(auxiliar_verificacao->conteudo.numero_conta, 50, stdin);
                            break;
                        case 4:
                            gotoxy(6,14);
                            printf("4 - Tipo da Conta...: ");
                            gotoxy(28, 14);
                            printf("                                              ");
                            gotoxy(28, 14);
                            fflush(stdin);
                            fgets(auxiliar_verificacao->conteudo.tipo_conta, 50, stdin);
                            break;
                        case 5:
                            limpar_campo_opcao();
                            escrever_msg("Operacao nao permitida! Tente outro campo.");
                            getch();
                            limpar_campo_opcao();
                            break;
                        case 6:
                            do
                            {
                                gotoxy(10,18);
                                printf("6 - Limite da Conta.: R$");
                                gotoxy(34, 18);
                                printf("                                            ");
                                gotoxy(34, 18);
                                scanf("%lf", &auxiliar_verificacao->conteudo.vl_limite);
                                if(auxiliar_verificacao->conteudo.vl_limite < 0)
                                {
                                    limpar_campo_opcao();
                                    escrever_msg("Valor invalido! Digite novamente...");
                                    getch();
                                    limpar_campo_opcao();
                                    gotoxy(34, 18);
                                    printf("                                            ");
                                }
                            }while(auxiliar_verificacao->conteudo.vl_limite < 0);
                            break;
                        case 7:
                            gotoxy(6,20);
                            printf("4 - Status da Conta.: ");
                            gotoxy(28, 20);
                            printf("                                              ");
                            gotoxy(28, 20);
                            fflush(stdin);
                            fgets(auxiliar_verificacao->conteudo.status, 50, stdin);
                            break;
                    }
                }while (campo_editavel != 0);
            }

            // Repetir o processo
            limpar_campo_opcao();
            gotoxy(7, 23);
            printf("Editar outro cadastro? (1 - Sim/2 - Nao): ");
            scanf("%d", &resposta_repetir);
            limpar_campo_opcao();
        }while(resposta_repetir != 2);
    }
    return;
}