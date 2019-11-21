#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox; //Ponteiro para próxima posição do tipo nodo
}Nodo;

/*Retorna um ponteiro para o início da lista*/
Nodo *cria_nodo(){
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    return novo;
}

Nodo *inserir_no_inicio(Nodo *inicio, int n){
    Nodo *novo = cria_nodo();
    novo->info = n;
    Nodo *anterior;
    Nodo *atual;
    
    atual = inicio;

    if(inicio == NULL){
        Nodo *inicio = novo;
        novo->prox = NULL;
   }else
        if(atual->info < n){
            novo->prox = inicio;
            inicio = novo;
        }
            
        return inicio;
}

void exibe_lista(Nodo *inicio){
    Nodo *atual = inicio;

    while(atual != NULL){
        printf("%d, ", atual->info);
        atual = atual->prox;
    }
}


int main(){
    Nodo *inicio = NULL; //Cria uma lista vazia
    inicio = inserir_no_inicio(inicio, 5);
    inicio = inserir_no_inicio(inicio, 7);
    exibe_lista(inicio);
}
