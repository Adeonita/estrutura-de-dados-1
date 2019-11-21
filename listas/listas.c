#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox; //Ponteiro para próxima posição do tipo nodo
}Nodo;

Nodo *atual; //ponteiro auxiliar que percorre a lista

Nodo *insere(int n, Nodo *inicio);
int retira(int n, Nodo **inicio);

Nodo *insere(int n, Nodo *inicio){

    Nodo *novo; //Novo valor inserido do tipo nodo, contendo o campo info e o campo prox
    Nodo *atual;

    novo = (Nodo*) malloc(sizeof(Nodo)); //Se novo foi alocado retorna o endereço, senao, retorna NULL

    if(novo == NULL){
        printf("Não foi possível alocar memória");
        exit(1);
    }
    novo->info = n;
    novo->prox = NULL;
    

    if(novo->info > atual->info){ //Inserção no fim
        atual->prox = novo;
        novo->prox = NULL;
    }else{   //Inserção no inicio
        inicio = novo;
        novo->prox = atual;
        atual->prox = NULL;
        novo->info = n;
    }
    return novo;
}

int main(){
    int opcao = ' ';
    int n;
    Nodo *atual;
    Nodo *inicio = NULL;

    while(opcao != 0){
        printf("Digite 1 para inserir");
        scanf("%i", &opcao);
    }
}