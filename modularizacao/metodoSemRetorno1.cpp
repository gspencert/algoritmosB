#include <iostream>
#include "metodos.h"
#define TAM 10000

using namespace std;

int main(){
    int vetor[TAM];
    int quantidade = 10;

    popular(vetor, quantidade, TAM);

    exibir("exibindo vetor: ", vetor, quantidade, TAM);

    menorElemento(vetor, quantidade, TAM);
    return 1;
}