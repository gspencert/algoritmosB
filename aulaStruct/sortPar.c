#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

int main() {

    int i, pares=0, vetor[TAM];

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        vetor[i] = rand() % TAM;
    }

    for (i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nquantidade de pares: %d", pares);
    printf("\n");

    return 0;
}
