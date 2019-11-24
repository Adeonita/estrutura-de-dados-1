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

    if(inicio == NULL){
        inicio = novo;
        novo->prox = NULL;
   }else{
        novo->prox = inicio;
        inicio = novo;
   }
    return inicio;
}

Nodo *inserir_no_fim(Nodo *inicio, int n){
    
    Nodo *novo = cria_nodo();
    novo->info = n;
        
    if(inicio == NULL){
        novo->prox = NULL;
        inicio = novo;
    }else{
        Nodo *atual;
        atual = inicio;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        novo->prox = NULL;
        atual->prox = novo;
    }

}

void *exibe_lista(Nodo *inicio){

    Nodo *atual = inicio;

    while(atual != NULL){
        printf("%d, ", atual->info);
        atual = atual->prox;
    }
}



int main(){
    Nodo *inicio = NULL; //Cria uma lista vazia
    int opcao = ' ';
    int n;

    while (opcao != 0 ){
        printf("Insira 1:Inserir 0:sair ");
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("Digite o numero a ser inserido: ");
            scanf("%d", &n);
            inicio = inserir_no_inicio(inicio, n);
        }
    }
 
    exibe_lista(inicio);

}
