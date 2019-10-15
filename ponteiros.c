#include <stdio.h>

int main(){

    int a = 5;
    int *ptr = &a; //Declarando um ponteiro para A, ele armazenará o endereço físico de A

    printf(" \n");
    printf("O endereço de 'a' é: %p (Acesso indireto)\n", ptr); //Exibindo o endereço de A através do ponteiro
    printf("O endereço de 'a' é: %p (Acesso pelo modificador '&') \n\n", &a);   //Exibinfo o endereço de A com o modificador &
    printf("O conteúdo de 'a' é: %d (Acesso Direto) \n", a); //Acessando o conteúdo de 'a' diretamente
    printf("O conteúdo de 'a' é: %d (Acesso indireto) \n\n", *ptr); //Acessando o conteúdo de 'a' através de um ponteiro
    printf("Modificarei o valor de 'a' indiretamente através de um ponteiro...\n");
    *ptr = 10;  //Modificando o conteúdo de 'a' indiretamente através de um ponteito
    printf("O conteúdo de 'a' agora é: %d", *ptr);

    printf(" \n\n\n\n");

    return 0;
}
