#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    struct nodo *prox;
    int info;
}Nodo;

typedef struct pilha{
    Nodo *topo; //Crio uma pilha com um ponteiro que aponta para o topo
}Pilha;

Pilha *cria_pilha(Pilha inicio_da_pilha){
    Pilha *inicio_da_pilha = (Pilha*)(malloc(sizeof(Pilha))); //O ponteiro *inicio_da_pilha que é do tipo pilha, aloca dinâmicamente espaço para uma estrutura do tipo pilha
}