#include <stdio.h>
#include "TADs_lineares_aloc_enc.h"

//TAD lista com alocação encadeada
//cria uma lista vazia
void CriaListaVazia(TipoLista *lista)
{
    lista->primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
}

//testa se a lista é vazia
int TestaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

//insere um elemento na lista
void InsereLista(TipoLista *lista, TipoItem item)
{
    lista->ultimo->proximo = (TipoCelula *)malloc(sizeof(TipoCelula));
    lista->ultimo = lista->ultimo->proximo;
    lista->ultimo->item = item;
    lista->ultimo->proximo = NULL;
}

//remove um elemento da lista
void RemoveLista(TipoLista *lista, TipoItem *item, TipoCelula *pt)
{
    if (TestaListaVazia(lista) || pt == NULL || pt->proximo == NULL)
    {
        printf("Erro: lista vazia ou posição inexistente\n");
        return;
    }
    TipoCelula *q = pt->proximo;
    *item = q->item;
    pt->proximo = q->proximo;
    if (pt->proximo == NULL)
        lista->ultimo = pt;
    free(q);
}

//imprime os elementos da lista
void ImprimeLista(TipoLista *lista)
{
    TipoCelula *aux = lista->primeiro->proximo;
    while (aux != NULL)
    {
        printf("%i ", aux->item.chave);
        aux = aux->proximo;
    }
}
