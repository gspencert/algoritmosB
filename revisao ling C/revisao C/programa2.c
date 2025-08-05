#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));
    int numeroSorteado;
    
    numeroSorteado = rand() % 100;
    printf("numero sorteado: %d\n", numeroSorteado);


    return 0;
}