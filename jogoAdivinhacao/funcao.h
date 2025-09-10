#include <iostream>
#define TAM 2

using namespace std;

void jogoAdivinhacao (int numeroSecreto[TAM], int numeroChute[TAM]){
    
    srand(time(0));
    for (int i = 0; i < TAM; i++){
        numeroSecreto[i] = rand() % 5 + 1;
    }

    for (int i = 0; i < TAM; i++){
        cout << "Digite o " << i + 1 << " numero (de 0 a 5): ";
        cin >> numeroChute[i];
    }

    for (int i = 0; i < TAM; i++){
        if (numeroChute[i] == numeroSecreto[i]){
            cout << numeroChute[i] << " igual a " << numeroSecreto[i] << endl;
        } else {
            cout << numeroChute[i] << " diferente de " << numeroSecreto[i] << endl;
        }
    }

    if (numeroChute[0] == numeroSecreto[0] || numeroChute[1] == numeroSecreto[1]){
        cout << "Acertou um ou mais, passa a vez!" << endl;
    } else {
        cout << "Nao acertou, passa a vez!" << endl;
    }
}