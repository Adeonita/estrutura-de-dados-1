#include <stdio.h>
#include <stdlib.h>


//Crio uma estrutura Nodo 
typedef struct Nodo{ 
    int info;
    struct Nodo *prox; 
}Nodo;

//Crio uma lista
typedef struct lista{  
    Nodo* primeiro_no;
}Lista;

//Retorna uma lista vazia 
Lista *cria_lista(void){

    Lista *inicio_da_lista = (Lista*) malloc(sizeof(Lista)); //Crio uma estrutura do tipo lista chamada inicio
    inicio_da_lista->primeiro_no = NULL; //E digo que o primeiro nó de inicio é NULL
    return inicio_da_lista;  //Retorno a lista vazia
} 
Nodo *cria_nodo(){
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    return novo;
}

//Como parâmetros são passados um ponteiro que representa a lista (inicio) e um valor (n)
void insere(Lista *inicio_da_lista, int n){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->info = n;
    novo->prox = inicio_da_lista->primeiro_no;
    inicio_da_lista->primeiro_no = novo;
    
}

void exibe_lista(Lista *inicio){
    Nodo* atual;
    for(Nodo * p=inicio->primeiro_no; p!= NULL; p=p->prox){
        printf("%d, ", p->info);
    }
    
}

int main(){
    Lista *lista = cria_lista();
    int opcao = ' ';

    if(cria_lista){
        while(opcao != 0){
            printf("Digite 1 para inserir 0 para sair, 2 para exibir: ");
            scanf("%d",&opcao);
            if(opcao == 1){
                int n;
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &n);
                insere(lista, n);
                printf("\nO numero %d foi inserido na lista\n", n);
            }if(opcao == 2){
                printf("Os elementos dessa lista são...");
                exibe_lista(lista);
                printf("\n");
            }
        }
    }else{
        printf("Não foi possivel alocar memória!");
    }
    
}