#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {
    int vetor[TAM];
    int i = 0, j = 0;
    int numero, repetido;

    srand(time(NULL));

    while (i < TAM) {
        numero = rand() % 10;
        repetido = 0;

        for (j = 0; j < i; j++) {
            if (vetor[j] == numero) {
                repetido = 1;
                break;
            }
        }

        if (repetido == 0) {
            vetor[i] = numero;
            i++;
        }
    }

    for (i = 0; i < TAM; i++) {
        printf("%d\t", vetor[i]);
    }

    return 0;
}
