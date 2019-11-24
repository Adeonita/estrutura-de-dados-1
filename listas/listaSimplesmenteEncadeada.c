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

/*Insere no inicio da lista
//Pode ser utilizado para implementar a pilha, pois a pilha só trabalha com o topo
//Como parâmetros são passados um ponteiro que representa a lista (inicio) e um valor (n)

void insere(Lista *inicio_da_lista, int n){
    Nodo *novo = cria_nodo();  //Aloca um novo espaco
    novo->info = n;  //Atribui ao campo info o valor n
    novo->prox = inicio_da_lista->primeiro_no; //Novo->prox recebe o inicio da lista pois o enlaçe é feito pelo ponteiro
    inicio_da_lista->primeiro_no = novo;  //E o inicio da lista recebe o novo
}
*/

void insere_ordenado(Lista *inicio_da_lista, int n){
    Nodo *anterior = NULL;  //Ponteiro para o elemento anterior
    Nodo *atual = inicio_da_lista->primeiro_no;  //Ponteiro auxiliar (*atual) recebe o primeiro nó do inicio da lista

    while(atual != NULL && atual->info < n){  //Varre a lista procurando onde inserir o elemento
        anterior =  atual;
        atual = atual -> prox;
    }

    Nodo *novo = cria_nodo();  //Cria o novo elemento
    novo->info = n;

    if(anterior == NULL){ //Estou andando com atual, e se anterior que é a lista vazia for igual a nulll, insiro no inicio
        novo->prox = inicio_da_lista->primeiro_no;
        inicio_da_lista->primeiro_no = novo;
    }else{
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

} 

void exibe_lista(Lista *inicio){

    Nodo *atual;
    //Exibição da lista com While
    /*
    while(atual != NULL){
        printf("%d, ",atual->info);
        atual = atual->prox;
    }
    printf("\n");
    */
   //Exibição da lista como for
    for(atual = inicio->primeiro_no; atual != NULL; atual = atual->prox){
        printf("%d, ", atual->info);
    }    
}

int main(){
    Lista *lista = cria_lista();
    int opcao = ' ';

    if(lista){
        while(opcao != 0){
            printf("Digite 1 para inserir 0 para sair, 2 para exibir: ");
            scanf("%d",&opcao);
            if(opcao == 1){
                int n;
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &n);
                insere_ordenado(lista, n);
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