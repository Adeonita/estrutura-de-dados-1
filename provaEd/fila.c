#include <stdio.h>
#include <stdlib.h>

typedef struct  nodo{
   int info;
   struct nodo *prox;  //Ponteiro para uma estrutura igual a ela (Estrutura autoreferenciada)
}Nodo;

typedef struct fila{
    Nodo *inicio;
    Nodo *fim;
}Fila;

Nodo *cria_nodo(){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    return novo;
}

Fila *cria_fila(){
    Fila *inicio_da_fila = (Fila*)malloc(sizeof(Fila));
    inicio_da_fila->inicio = NULL;
    inicio_da_fila->fim = NULL;
    return inicio_da_fila;
}


void insert(Fila *inicio_da_fila, int n){
    Nodo *novo = cria_nodo();
    novo->info = n;  //inicialização do novo nó
    novo->prox = NULL; //inicialização do novo nó
    if(inicio_da_fila->fim != NULL){
        inicio_da_fila->fim->prox = novo;
    }else{
        inicio_da_fila->inicio = novo;
    }inicio_da_fila->fim = novo;
}

int pop(Fila *inicio_da_fila){
    Nodo *pop = inicio_da_fila->inicio;
    int n = pop->info;
    inicio_da_fila->inicio = pop->prox;
    free(pop);
    printf("\n Removendo %d da fila ... \n",n);
    return n;
}

void exibeFila(Fila *incio_da_fila){
    printf("\n\nListando a fila...\n\n");
    for(Nodo *i = incio_da_fila->inicio; i != NULL; i = i->prox){
        printf("%d -> ", i->info);
    }
        printf("\n");
}



int main(){
    int opcao = ' ';
    Fila *fila = cria_fila();

    while(opcao =! 0){
        printf("Digite 1 para inserir, 2 para retirar, 3 para listar e 0 para sair\n");
        scanf("%d",&opcao);
        if(opcao == 1){
            int n;
            printf("Digite um numero para inserir: ");
            scanf("%d", &n);
            insert(fila, n);
        }if(opcao == 2){
            pop(fila);
            exibeFila(fila);

        }if(opcao == 3){
            exibeFila(fila);
        }
    }
    
}