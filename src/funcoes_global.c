/*
Autor: Marcos.
Data: 28/10/24.
Membros: 
    1 - 178292-2024
    2 - 177020-2024
Descrição: Programa para gerenciamento de varias contas bancarias.
*/

// Bibliotecas
#include "global.h"

// Função que conta quantos cadastros estão presentes na lista
int Contar_Elementos_Lista(Lista *lista)
{
    Apontador VariavelAuxiliar;
    int Quant_Intens = 0;

    VariavelAuxiliar = lista->primeiro;

    while (VariavelAuxiliar != NULL) 
    {
        VariavelAuxiliar = VariavelAuxiliar->proximo;
        Quant_Intens++;
    }

    return Quant_Intens;
}

// Função que verifica se o código de conta já foi utilizado
Apontador Verificar_Existencia(Lista *lista, int codigo_conta)
{
    //Utilizada para percorrer a lista
    Apontador VariavelAuxiliar;

    // Inicializa o inicio da lista com a variavel criada
    VariavelAuxiliar = lista->primeiro; // lista->primeiro aponta para o primeiro registro da lista de funcionários

    // Realiza um loop para percorrer a lista até chegar ao ultimo registro
    while (VariavelAuxiliar != NULL)
    {
        // Verifica se o codigo procurado é igual ao codigo registrado
        if (VariavelAuxiliar->conteudo.codigo_conta == codigo_conta)
        {
            // Se o código for igual ele retorna o ponteiro da VariavelAuxiliar que aponta para o registro que tem o mesmo código
            return VariavelAuxiliar;
        }

        // Mover o ponteiro para o proximo da lista
        VariavelAuxiliar = VariavelAuxiliar->proximo; // VariavelAuxiliar->proximo apronta para o proximo item da lista
    }

    // Retornar NULL caso nenhum nada for encontrado
    return NULL;
}

// Função para limpar a memória da lista de cadastro de contas
void Limpar_Mem_Contas(Lista *lista)
{
    Apontador lista_auxiliar;

    while(lista->primeiro != NULL)
    {
        lista_auxiliar = lista->primeiro;
        lista->primeiro = lista->primeiro->proximo;
        free(lista_auxiliar);
    }
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

// Função para limpar a memória da lista de movimentação financeira
void Limpar_Mem_Finan(ListaFinanceira *lista)
{
    ApontadorFinanceiro lista_auxiliar;

    while(lista->primeiro != NULL)
    {
        lista_auxiliar = lista->primeiro;
        lista->primeiro = lista->primeiro->proximo;
        free(lista_auxiliar);
    }
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

// ------------------- Funções de Arquivo - Conta --------------------
// Função que inicializa uma lista
Lista InicializarLista()
{
    //Inicializar o começo e fim da lista
    Lista lista;
    lista.primeiro = NULL; //Inicializar a variável com um valor null para não dar ruim ao atribuir algo a ela
    lista.ultimo = NULL; //Inicializar a variável com um valor null para não dar ruim ao atribuir algo a ela

    return lista;
}

// Função Responsável por adicionar contas a lista
void Adicionar_Conta(Lista *lista, Conteudo_Conta conteudo)
{
    Apontador lista_auxiliar;

    lista_auxiliar = (Apontador)malloc(sizeof(Item));

    lista_auxiliar->conteudo = conteudo; // Adicionar conteúdo a lista
    lista_auxiliar->proximo = NULL; // Aterrar o campo que aponta para o proximo

    if(lista->primeiro == NULL)
    {
        lista->primeiro = lista_auxiliar;
        lista->ultimo = lista_auxiliar;
    }
    else
    {
        lista->ultimo->proximo = lista_auxiliar; // Adicionar o item no final da lista
        lista->ultimo = lista_auxiliar; // Mover o apontado para o ultimo da lista
    } 
}

// Criar o arquivo com os dados da lista
void SalvarLista(Lista *lista)
{
    // Variaveis
    Apontador auxiliar;

    // Criar arquivo
    FILE *banco_de_dados;

    // Abrir o arquivo
    banco_de_dados = fopen("DADOS_CON.dat", "wb");

    if(banco_de_dados == NULL)
    {
        tela();
        limpar_campo_opcao();
        escrever_msg("Erro ao salvar no banco de dados!");
        getch();
        return;
    }
    else 
    {
        auxiliar = lista->primeiro;

        while(auxiliar != NULL)
        {
            // Escrever o conteúdo de cada cadastro um por um no arquivo
            fwrite(&auxiliar->conteudo, sizeof(Conteudo_Conta), 1, banco_de_dados);
            auxiliar = auxiliar->proximo; // ir para o proximo cadastro
        }

        tela();
        limpar_campo_opcao();
        escrever_msg("Salvamento no banco de dados concluido com sucesso!");
        getch();

        // Fechar arquivo
        fclose(banco_de_dados);
    }
}

// Ler o arquivo com os dados da lista
Lista LerLista()
{
    // Variáveis
    Conteudo_Conta conteudo_auxiliar;
    Lista lista;

    FILE *banco_de_dados; // Criar um novo arquivo

    // Criar uma nova lista
    lista = InicializarLista();
    
    // Abrir arquivo
    banco_de_dados = fopen("DADOS_CON.dat", "rb");

    if(banco_de_dados == NULL)
    {
        tela();
        limpar_campo_opcao();
        escrever_msg("Erro ao abrir e ler o banco de dados!");
        getch();
        return lista;
    }
    else 
    {
        // Ler cada conteudo de cadastro um por um
        while (fread(&conteudo_auxiliar, sizeof(Conteudo_Conta), 1, banco_de_dados)) 
        {
            // Adicionar conteudos lido em posições da lista (sempre no final mantendo a ordem anterior)
            Adicionar_Conta(&lista, conteudo_auxiliar);    
        }
    }

    // Fechar o arquivo
    fclose(banco_de_dados);

    return lista;
}
// -------------------------------------------------------------------

// Define um valor aleatório de crédito para uma conta corrente
double Serasa(Conteudo_Conta *conta)
{
    int Credito_Social;
    int Sorte;
    int Chance;

    srand(time(NULL));

    Credito_Social = rand() % 100 + 1;
    Sorte = rand() % 100 + 1;
    Chance = rand() % 100 + 1;

    if (Credito_Social == Sorte) 
    {
        if(Chance == Sorte)
        {
            conta->vl_limite = rand() % 15000 + 1000;        
        }
        else
        {
            conta->vl_limite = 0;
        }
    }
    else 
    {
        conta->vl_limite = rand() % 1200 + 100;
    }

    return conta->vl_limite;
}

// ---------------- Funções de Arquivo - Financeiro ------------------
// Inicaializar a lista de operações financeiras
ListaFinanceira InicializarListaFinanceira()
{
    //Inicializar o começo e fim da lista
    ListaFinanceira lista;
    lista.primeiro = NULL; //Inicializar a variável com um valor null para não dar ruim ao atribuir algo a ela
    lista.ultimo = NULL; //Inicializar a variável com um valor null para não dar ruim ao atribuir algo a ela

    return lista;
}

// Método para adicionar cada um dos item da lista financeira em uma nova lista
void Adicionar_Movimentacoes(ListaFinanceira *lista, Conteudo_Financeiro conteudo)
{
    ApontadorFinanceiro auxiliar;

    auxiliar = (ApontadorFinanceiro)malloc(sizeof(ItemFinanceiro));

    auxiliar->conteudo = conteudo; // Adicionar conteúdo a lista
    auxiliar->proximo = NULL; // Aterrar o campo que aponta para o proximo
    auxiliar->anterior = NULL; // Aterrar o campo que aponta para o anterior

    if(lista->primeiro == NULL)
    {
        lista->primeiro = auxiliar;
        lista->ultimo = auxiliar;
    }
    else
    {
        lista->ultimo->proximo = auxiliar; // Aponta o ponteiro proximo para o novo item
        auxiliar->anterior = lista->ultimo; // Aponta o ponteiro anterior para o item anterior (que era o ultimo)
        lista->ultimo = auxiliar; // Mover o apontador para o ultimo da lista (recém adicionado)
    } 
}

// Função que abre o arquivo e lê todos os dados criando uma lista financeira
ListaFinanceira LerListaFinanceira()
{
    // Variáveis
    Conteudo_Financeiro conteudo_auxiliar;
    ListaFinanceira lista;

    FILE *banco_de_dados; // Criar um novo arquivo

    // Criar uma nova lista
    lista = InicializarListaFinanceira();
    
    // Abrir arquivo
    banco_de_dados = fopen("DADOS_FIN.dat", "rb");

    if(banco_de_dados == NULL)
    {
        tela();
        limpar_campo_opcao();
        escrever_msg("Erro ao abrir e ler movimentacoes financeiras!");
        getch();
        return lista;
    }
    else 
    {
        // Ler cada conteudo de cadastro um por um
        while (fread(&conteudo_auxiliar, sizeof(Conteudo_Financeiro), 1, banco_de_dados)) 
        {
            // Adicionar conteudos lido em posições da lista (sempre no final mantendo a ordem anterior)
            Adicionar_Movimentacoes(&lista, conteudo_auxiliar);    
        }
    }

    // Fechar o arquivo
    fclose(banco_de_dados);

    return lista;
}

// Função responsável por salvar todos os dados de operações financeiras em um arquivo
void SalvarListaFinanceira(ListaFinanceira *lista)
{
    // Variaveis
    ApontadorFinanceiro auxiliar;

    // Criar arquivo
    FILE *banco_de_dados;

    // Abrir o arquivo
    banco_de_dados = fopen("DADOS_FIN.dat", "wb");

    if(banco_de_dados == NULL)
    {
        tela();
        limpar_campo_opcao();
        escrever_msg("Erro ao salvar movimentacoes financeiras!");
        getch();
        return;
    }
    else 
    {
        auxiliar = lista->primeiro;

        while(auxiliar != NULL)
        {
            // Escrever o conteúdo de cada cadastro um por um no arquivo
            fwrite(&auxiliar->conteudo, sizeof(Conteudo_Conta), 1, banco_de_dados);
            auxiliar = auxiliar->proximo; // ir para o proximo cadastro
        }

        tela();
        limpar_campo_opcao();
        escrever_msg("Salvamento no banco de dados concluido com sucesso!");
        getch();

        // Fechar arquivo
        fclose(banco_de_dados);
    }
}
// ------------------------------------------------------------------

// Contar sequencia de movimentações financeiras
int Contar_movimentacao_financerira(ListaFinanceira *lista)
{
    ApontadorFinanceiro VariavelAuxiliar;
    int Quant_Intens = 0;

    VariavelAuxiliar = lista->primeiro;

    while (VariavelAuxiliar != NULL) 
    {
        VariavelAuxiliar = VariavelAuxiliar->proximo;
        Quant_Intens++;
    }

    return Quant_Intens;
}

// Realizar a movimentação de valores nas movimentações bancarias
void Realizar_Movimentacao(Conteudo_Financeiro *mov_fin, Item *conta, int tipo_operacao)
{
    // Variáveis

    if (tipo_operacao == 1)
    {
        if(mov_fin->vl_movimento > (conta->conteudo.vl_saldo + conta->conteudo.vl_limite))
        {
            limpar_campo_opcao();
            escrever_msg("Valor desejado ultrapassa limite da conta! Operacao impedida.");
            getch();
            limpar_campo_opcao();
        }
        else {
            conta->conteudo.vl_saldo = conta->conteudo.vl_saldo - mov_fin->vl_movimento;
            mov_fin->vl_saldo = conta->conteudo.vl_saldo;
        }
    }
    else if(tipo_operacao == 2)
    {
        conta->conteudo.vl_saldo = conta->conteudo.vl_saldo + mov_fin->vl_movimento;
        mov_fin->vl_saldo = conta->conteudo.vl_saldo;
    }
    else 
    {
        limpar_campo_opcao();
        escrever_msg("Operacao desconhecida!");
        getch();
        limpar_campo_opcao();
    }
}

// Incrementa o sequencial de movimentações financeiras
void Incrementar_Sequencial(ListaFinanceira *lista_fi, Conteudo_Financeiro *temporario)
{
    // Variáveis
    int quantidade;

    // Contar quantas movimentações foram feitas
    quantidade = Contar_movimentacao_financerira(lista_fi);
    
    temporario->sequencial = quantidade + 1;
}

// Função que recebe e compara uma data no formato xx/yy/zzzz e diz se ela é maior ou menor do que a digitada
int Comparar_Data(char* data[11], ItemFinanceiro *conteudo_fi)
{
    // Variáveis
    char dia[3], mes[3], ano[5];
    int intDia, intMes, intAno;
    char diaUsr[3], mesUsr[3], anoUsr[5];
    int intDiaUsr, intMesUsr, intAnoUsr;
    
    // Dia
    strcpy(dia, data);
    dia[2] = '\0'; // Adiciona o caractere de finalização de string

    // Mes
    strcpy(mes, data + 3);
    mes[2] = '\0'; // Adiciona o caractere de finalização de string

    // Ano
    strcpy(ano, data + 6);
    ano[4] = '\0'; // Adiciona o caractere de finalização de string

    // Função atoi() converte um tipo de caractere ASCII em int (por isso: a -> to -> i) 
    intDia = atoi(dia);
    intMes = atoi(mes);
    intAno = atoi(ano);

    // Dia usuário
    strcpy(diaUsr, conteudo_fi->conteudo.dt_movimento);
    diaUsr[2] = '\0'; // Adiciona o caractere de finalização de string

    // Mes usuário
    strcpy(mesUsr, conteudo_fi->conteudo.dt_movimento + 3);
    mesUsr[2] = '\0'; // Adiciona o caractere de finalização de string

    // Ano usuário
    strcpy(anoUsr, conteudo_fi->conteudo.dt_movimento + 6);
    anoUsr[4] = '\0'; // Adiciona o caractere de finalização de string

    // Função atoi() converte um tipo de caractere ASCII em int (por isso: a -> to -> i) 
    intDiaUsr = atoi(diaUsr);
    intMesUsr = atoi(mesUsr);
    intAnoUsr = atoi(anoUsr);

    // Coisa feia que que compara um por um se o ano, mes e dia
    if (intAno < intAnoUsr) 
    {
        return -1;
    } 
    else if (intAno > intAnoUsr) 
    {
        return 1;
    } 
    else 
    {
        if (intMes < intMesUsr) 
        {
            return -1;
        } 
        else if (intMes > intMesUsr) 
        {
            return 1;
        }
        else 
        {
            if (intDia < intDiaUsr) 
            {
                return -1;
            } 
            else if (intDia > intDiaUsr) 
            {
                return 1;
            } 
            else 
            {
                return 0;
            }
        }
    }
}

// Verifica se existe alguma movimentação com o mesmo código da conta
ApontadorFinanceiro Verificar_Existencia_Movimentacao(ListaFinanceira *lista, int codigo_conta)
{
    //Utilizada para percorrer a lista
    ApontadorFinanceiro VariavelAuxiliar;

    // Inicializa o inicio da lista com a variável criada
    VariavelAuxiliar = lista->primeiro; // lista->primeiro aponta para o primeiro registro da lista de funcionários

    // Realiza um loop para percorrer a lista até chegar ao ultimo registro
    while (VariavelAuxiliar != NULL)
    {
        // Verifica se o codigo procurado é igual ao codigo registrado
        if (VariavelAuxiliar->conteudo.codigo_conta == codigo_conta)
        {
            // Se o código for igual ele retorna o ponteiro da VariavelAuxiliar que aponta para o registro que tem o mesmo código
            return VariavelAuxiliar;
        }

        // Mover o ponteiro para o proximo da lista
        VariavelAuxiliar = VariavelAuxiliar->proximo; // VariavelAuxiliar->proximo aponta para o proximo item da lista
    }

    // Retornar NULL caso nenhum nada for encontrado
    return NULL;
}