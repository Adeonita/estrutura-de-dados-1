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
        inicio_da_fila->fim->prox = novo;  //Insere no final
    }else{
        inicio_da_fila->inicio = novo; //Insere no inicio
    }inicio_da_fila->fim = novo; //Enlaça o final com o novo
}

int pop(Fila *inicio_da_fila){
    Nodo *atual = inicio_da_fila->inicio;  //Inicializa pop e coloca para ele apontar para o início
    int n = atual->info;  //atribui a n pop->info
    inicio_da_fila->inicio = atual->prox; //Aponta para o novo inicio
    free(atual);  //Deleta o atual
    return n;  //Retorna o numero removido
}

int isEmpty(Fila *fila){  
    return fila->inicio == NULL;
}

void exibeFila(Fila *incio_da_fila){
    printf("\n\nListando a fila...\n\n");
    for(Nodo *i = incio_da_fila->inicio; i != NULL; i = i->prox){
        printf("%d -> ", i->info);
    }
        printf("\n");
}

//Terminar de implementar 
void exibeReverse(Fila *incio_da_fila){
    Nodo *pop = incio_da_fila->fim;
    int n = pop->info;
    incio_da_fila->fim = pop->prox; //O endereço do elemento anterior
    free(pop);
    printf("%d", n);
}




int main(){
    int opcao = ' ';
    Fila *fila = cria_fila();

    while(opcao =! 0){
        printf("Digite 1 para inserir, 2 para retirar, 3 para listar, 4 Exibir fila reversa e 0 para sair: ");
        scanf("%d",&opcao);
        if(opcao == 1){
            int n;
            printf("Digite um numero para inserir: ");
            scanf("%d", &n);
            insert(fila, n);
        }if(opcao == 2){
            if(isEmpty(fila) ){
                printf("\nA fila está vazia, impossível remover \n");
            }else{
                printf("\nRemovendo %d da fila ...", pop(fila));
                exibeFila(fila);
            }
        }if(opcao == 3){
            if(isEmpty(fila) ){
                printf("\nA fila está vazia\n");
            }else{
                exibeFila(fila);
            }
        }if(opcao == 4){
            exibeReverse(fila);
        }
    }
    
}