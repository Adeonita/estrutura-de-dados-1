#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
	int info;
	struct nodo *anterior, *prox;
}Nodo;

void inserirDuplamenteEncadeado(Nodo **inicio, int n);
int retirarDuplamenteEncadeado(Nodo**inicio, int n);
void mostrarListaEncadeado(Nodo**inicio);// fazer c�digo da fun��o

Nodo *atual;
int main(){
		int num, opc;
		Nodo *inicio = NULL;
		Nodo *atual;
		
	do{
		system("cls");
		printf("Bem Vindo a Lista!\n");
		printf("1 inserir na Lista: \n");
		printf("2 Mostrar Lista: \n");
		printf("3 sair: \n");
		printf("\n");
		scanf("%d", &opc);

		switch(opc){
			case 1:
				system("cls");
				printf("Digite o Valor:\n");
				scanf("%d" , &num);
				inserirDuplamenteEncadeado(&inicio, num);
				mostrarListaEncadeado(&inicio);
				break;

            case 2:
				system("cls");
				mostrarListaEncadeado(&inicio);
				break;
            case 3:
				system("cls");
				printf("Digite o Valor:\n");
				scanf("%d" , &num);
                retirarDuplamenteEncadeado(&inicio, num);
				break;
			case 4:
				system("cls");
				break;
			default:
				printf("Numero Invalido!\n\n");
		}getch();
	}while(opc!=4);
		printf("Saindo da Fila");
	getch();
}

void inserirDuplamenteEncadeado(Nodo**inicio, int n){
	Nodo *novo, *atual;
	novo = (Nodo*)malloc(sizeof(Nodo));
	if(novo == NULL){
		exit(1);
	}else{
		novo->anterior = novo->prox = NULL;
		novo->info = n;
	}
	if(*inicio == NULL){
		*inicio = novo;
		atual = *inicio;	
	}
	
	while((atual->prox != NULL)&&(n > atual->info))
		 atual = atual->prox ;
		 
		 if( (atual == *inicio) && (atual -> prox = NULL)){
			if(n > atual->info){
			atual->prox = novo;
			novo->anterior = atual;
		 }else{
			novo -> prox = atual;
			atual -> anterior = novo;
			*inicio = novo;
		}
		}if (atual == *inicio){
			novo -> prox = atual;
			atual -> anterior = novo;
			*inicio = novo;
		}	
		if (n < atual -> info){
		atual -> anterior -> prox = novo;
		novo -> anterior = atual -> anterior;
		novo -> prox = atual;
		atual -> anterior = novo;
	        }else{
	            novo -> anterior = atual;
	            atual -> prox = novo;
		} 
}

int retirarDuplamenteEncadeado(Nodo**inicio, int n){
	Nodo * atual;
	if(*inicio == NULL) 
	{
	 return 0;
	}else{
		atual = *inicio;
	}
	while((atual != NULL)&&(n != atual->info)){
		atual = atual ->prox;
		
		if(atual == NULL){
			return 0;
		}
		if(atual == *inicio){
			*inicio = (*inicio)->prox;
			(*inicio)->anterior = NULL;
		}else if( atual -> prox == NULL){
			atual->anterior -> prox = NULL;
		}else {
			atual -> anterior -> prox = atual -> prox;
			atual -> prox -> anterior = atual -> anterior;
		}
		free(atual);
	return 1;
	}
}

void mostrarListaEncadeado(Nodo**inicio){
  ...
}



