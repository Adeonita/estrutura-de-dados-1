#include <stdio.h>
#define MAX 4

int pilha[MAX];
int topo = 0;


void insere(int i){
    if(topo >= MAX){
        printf("A pilha está cheia!\n");
        return;
    }
    else{
        pilha[topo] = i;
        topo ++;
    }
    printf("Inserindo o número : %d ",i); 
    printf("\n");   
}

int retira(void){
    if(topo <= 0){
        printf("Impossível Retirar,  pilha está vazia \n"); 
        return 0; 
    }else{
        topo --;
        printf("\nRemovendo o número: %d\n",pilha[topo]);
    }    
    return pilha[topo];
}

int main(){
    int opcao = ' ';
    while(opcao != 0){
        printf("\nDigite 1 para inserir, 2 para retirar, 0 sair: ");
        scanf("%i", &opcao);
        if(opcao == 1){
            int i;
            printf("Digite um número: ");
            scanf("%d",&i);
            printf("\n");
            insere(i);
        }if(opcao == 2){
            retira();
        }

     
    }
    
}