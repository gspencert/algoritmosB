#include <iostream> // <stdio.h>
#include <string> // <string.h>

#define TAM 5

using namespace std;

typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;

int main(){

    Carro garagem[TAM];
    Carro carro;
    int qtdCarros = 0;
    int opcao;

    while (true) {
        system("cls");
        cout << "=== MENU ===";
        cout << "1- ENTRAR CARRO";
        cout << "2- TIRAR CARRO";
        cout << "3- LISTAR CARRO";
        cout << "4- FIM";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Entrando carro na garagem...";
                if (qtdCarros == TAM) {
                    cout << "Nao tem vagas na garagem";
                } else {
                    cout << "Placa: ";
                    cin >> carro.placa;
                    cout << "Hora de entrada: ";
                    cin >> carro.horaEntrada;

                    garagem[qtdCarros] = carro;
                    qtdCarros++;
                }
                break;
            case 2:
                cout << "Saindo carro da garagem...";
                break;
            case 3:
                cout << "Listando carro na garagem...";
                if (qtdCarros == 0) {
                    cout << "Nao ha carros na garagem";
                } else {
                    for (int i = 0 ; i < qtdCarros ; i++) {
                        cout << "Placa que entrou: " << carro.placa;
                        cout << "Hora de entrada: " << carro.horaEntrada;
                        cout << "Imprimindo ticket de entrada.";
                    }
                }
                break;
            case 4:
                cout << "Saindo do programa...";
            default:
                cout << "Opcao Invalida.";
                break;
        }
    }

    cout << "\n";
    return 0;
}