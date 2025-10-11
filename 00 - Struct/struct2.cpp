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

int main(){

    Carro garagem[TAM];
    Carro carro;
    int qtdCarros = 0;
    int opcao;

    while (true) {
        cout << "=== MENU ===\n";
        cout << "1- adicionar carro\n";
        cout << "2- tirar carro\n";
        cout << "3- listar carro\n";
        cout << "4- fim\n";
        cout << "opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "entrando carro na garagem...\n";
                if (qtdCarros == TAM) {
                    cout << "nao tem vagas na garagem\n";
                } else {
                    cout << "placa: ";
                    cin >> carro.placa;

                    bool placaExiste = false;
                    for(int i = 0; i < qtdCarros; i++) {
                        if(garagem[i].placa == carro.placa) {
                            placaExiste = true;
                            break;
                        }
                    }
                    
                    if(placaExiste) {
                        cout << "carro ja esta na garagem!\n";
                    } else {
                        cout << "hora de entrada: ";
                        cin >> carro.horaEntrada;

                        garagem[qtdCarros] = carro;
                        qtdCarros++;
                        cout << "carro guardado com sucesso!\n";
                    }
                }
                break;

            case 2:
                cout << "saindo carro da garagem...\n";
                if (qtdCarros == 0) {
                    cout << "garagem vazia\n";
                } else {
                    cout << "placa do carro que vai tirar: ";
                    cin >> carro.placa;

                    bool achou = false;
                    for (int i = 0; i < qtdCarros; i++) {
                        if (garagem[i].placa == carro.placa) {
                            garagem[i] = garagem[qtdCarros - 1];
                            qtdCarros--;
                            achou = true;
                            cout << "carro retirado\n";
                            break;
                        }
                    }

                    if (!achou) {
                        cout << "carro nao encontrado\n";
                    }
                }
                break;

            case 3:
                cout << "listando carro na garagem...\n";
                if (qtdCarros == 0) {
                    cout << "nao ha carros na garagem\n";
                } else {
                    for (int i = 0 ; i < qtdCarros ; i++) {
                        cout << "placa que entrou: " << garagem[i].placa << "\n";
                        cout << "hora de entrada: " << garagem[i].horaEntrada << "\n";
                        cout << "imprimindo comprovante de entrada.\n";
                    }
                }
                break;

            case 4:
                cout << "saindo do programa...\n";
                return 0;

            default:
                cout << "opcao invalida.\n";
                break;
        }
    }
    cout << "\n";
    return 0;
}
