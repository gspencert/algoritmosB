#include <iostream>
#include <string>
#define TAM 5

using namespace std;

int main() {

    string placa;
    string vetor[TAM];

    for (int i = 0; i < TAM; i++) {
        cout << "digite uma placa: ";
        cin >> placa;

        vetor[i] = placa;
    }

    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << "\t";
    }

    cout << "\n";
    return 1;
}