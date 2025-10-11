#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "essa quantidade nao eh possivel" << endl;
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "essa quantidade nao eh possivel" << endl;
        return;
    }
    cout << frase << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void menorElemento(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel" << endl;
        return;
    }

    int menor = vetor[0];
    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    cout << "Menor elemento: " << menor << endl;
}