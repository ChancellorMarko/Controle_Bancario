// Funções globais

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

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

// Função que verifica se o código de funcionario já foi utilizado
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