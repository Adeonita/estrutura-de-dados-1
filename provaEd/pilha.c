#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    Nodo *prox;
}Nodo;

typedef struct pilha{
    Nodo *topo; //Crio uma pilha com um ponteiro do tipo Nodo que aponta para o topo
}Pilha;

Pilha *cria_pilha(){
    Pilha *inicio_da_pilha = (Pilha*)malloc(sizeof(Pilha)); //O ponteiro *inicio_da_pilha que é do tipo pilha, aloca dinâmicamente espaço para uma estrutura do tipo pilha
    inicio_da_pilha->topo = NULL;
    return inicio_da_pilha;
}

Nodo *create_nodo(){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo)); //Aloco espaco para um novo valor
    return novo; //Retnorno esse valor
}

void push(Pilha *inicio_da_pilha, int n){
    Nodo *novo = cria_nodo();
    novo->info = n;
    novo->prox = inicio_da_pilha->topo;
    inicio_da_pilha->topo = novo;    
}

int pop(Pilha *inicio_da_pilha){
    Nodo *pop = inicio_da_pilha->topo;
    int n = pop->info;
    free(pop);
    return n;
}

int isEmpty(Pilha *inicio_da_pilha){
    return (inicio_da_pilha->topo == NULL);
}

void showStack(Pilha *inicio_da_pilha){
    
}
