#include <iostream>
#include <string>

#define TAM 5

using namespace std;

typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;

int main() {
    Carro garagem[TAM];
    Carro carro;

    for (int i = 0 ; i < TAM ; i++) {
        do {
            cout << "digite uma placa: ";
            cin >> carro.placa;
            if (carro.placa.size() == 7) {
                break;
            } else {
                cout << "placa invalida. redigite....\n";
            }
        } while (true);
        cout << "Hora de entrada: ";
        cin >> carro.horaEntrada;

        garagem[i] = carro;
    }

    for ( int i=0 ; i < TAM ; i++){
        cout << "Placa: " << garagem[i].placa << "\n";
        cout << "hora de entrada: " << garagem[i].horaEntrada << "\n";
        cout << "hora de saida: " << garagem[i].horaSaida << "\n";
    }
    return 0;
}