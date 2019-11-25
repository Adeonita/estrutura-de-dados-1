#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct nodo Nodo;

struct lista{
    Nodo *primeiro_no;
    Nodo *ultimo_no;
};

struct nodo{
    int info;
    Nodo *anterior;
    Nodo *prox;
};

/*Crio uma estrutura do tipo lista onde seus ponteiros auxiliares primeiro e último nodo são null's*/
Lista *cria_lista(void){
    Lista *inicio_da_lista = (Lista*) malloc(sizeof(Lista));  //Retorna o inicio da lista.
    inicio_da_lista->primeiro_no = NULL;
    inicio_da_lista->ultimo_no = NULL;
    return inicio_da_lista;
}

Nodo *cria_nodo(){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    return novo;
}
void insere_no_inicio(Lista *inicio_da_lista, int n){
    Nodo *novo = cria_nodo();
    novo->info = n;
    novo->prox = inicio_da_lista->primeiro_no;
    novo->anterior = NULL;

    if(inicio_da_lista->primeiro_no != NULL){
        inicio_da_lista->primeiro_no->anterior = novo;
    }
     
}