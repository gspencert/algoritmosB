#include <iostream>
#include <ctime>
#define TAM 5
using namespace std;

void popula(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20;
    }
}

void exibe(int *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

void substituiParesPorZero(int *v, int n, int &qtdTrocas) {
    qtdTrocas = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            v[i] = 0;
            qtdTrocas++;
        }
    }
}

int main() {
    int vetor[TAM];
    int qtdTrocas;

    popula(vetor, TAM);
    cout << "Vetor original:" << endl;
    exibe(vetor, TAM);

    substituiParesPorZero(vetor, TAM, qtdTrocas);

    cout << "Vetor após substituir pares por zero:" << endl;
    exibe(vetor, TAM);

    cout << "Quantidade de pares substituídos: " << qtdTrocas << endl;

    return 0;
}