#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
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
    Nodo *novo = create_nodo();
    novo->info = n;
    novo->prox = inicio_da_pilha->topo;
    inicio_da_pilha->topo = novo;    
}

int pop(Pilha *inicio_da_pilha){
    Nodo *pop = inicio_da_pilha->topo;
    int n = pop->info;
    inicio_da_pilha->topo = pop->prox; //O endereço do elemento anterior
    free(pop);
    return n;
}

int isEmpty(Pilha *inicio_da_pilha){
    return (inicio_da_pilha->topo == NULL);
}

void showStack(Pilha *inicio_da_pilha){
    Nodo *atual;
    atual = inicio_da_pilha->topo;
    while(atual != NULL){
        printf("%d \n", atual->info);
        atual = atual->prox;
    }
}


int main(){
    Pilha *pilha = cria_pilha();
    int option = ' ';
    
    printf("***********BEM VINDO A PILHA!***********\n\n");
    while(option =! 0){
        printf("Digite 1 para inserir, 2 para remover, 3 para exibir: ");
        scanf("%d", &option);
        if(option == 1){
            int n;
            printf("Digite o numero a ser inserido: ");
            scanf("%d", &n);
            push(pilha, n);
            printf("\nO numero %d foi inserido na pilha\n\n", n);
        }
        if(option == 2){
            printf("O numero %d foi removido da pilha \n\n",  pop(pilha));
            showStack(pilha);

        }
        if(option == 3){
            showStack(pilha);
        }
    }
}