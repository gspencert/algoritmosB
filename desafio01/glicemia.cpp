#include <iostream>
#include <string>
#include <algorithm> 
#define TAM 100 

using namespace std;

int main() {
    int glicemias[TAM];
    int quantidadeInseridos = 0;
    int opcao;

    do {
        cout << "=== MENU ===" << endl;
        cout << "1 - cadastrar dados glicemicos (45 a 450)" << endl;
        cout << "2 - mostrar dados glicemicos" << endl;
        cout << "3 - calcular e exibir media" << endl;
        cout << "4 - calcular e exibir mediana" << endl;
        cout << "5 - sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                if (quantidadeInseridos == TAM) {
                    cout << "vetor lotado..." << endl;
                } else {
                    int valor;
                    cout << "digite valor da glicemia (45 a 450): ";
                    cin >> valor;
                    if (valor >= 45 && valor <= 450) {
                        glicemias[quantidadeInseridos] = valor;
                        quantidadeInseridos++;
                        cout << "valor cadastrado com sucesso" << endl;
                    } else {
                        cout << "valor invalido! digite entre 45 e 450." << endl;
                    }
                }
                break;

            case 2:
                if (quantidadeInseridos == 0) {
                    cout << "nenhum valor cadastrado." << endl;
                } else {
                    cout << "valores cadastrados:" << endl;
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        cout << "valor " << (i+1) << ": " << glicemias[i] << endl;
                    }
                    cout << "total: " << quantidadeInseridos << " registros" << endl;
                }
                break;

            case 3:
                if (quantidadeInseridos == 0) {
                    cout << "nenhum dado pra calcular a media" << endl;
                } else {
                    double soma = 0;
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        soma += glicemias[i];
                    }
                    double media = soma / quantidadeInseridos;
                    cout << "media da glicemia: " << media << endl;
                }
                break;

            case 4:
                if (quantidadeInseridos == 0) {
                    cout << "nenhum dado pra calcular a media" << endl;
                } else {
                    int temp[TAM];
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        temp[i] = glicemias[i];
                    }
                    sort(temp, temp + quantidadeInseridos);

                    double mediana;
                    if (quantidadeInseridos % 2 == 0) {
                        int meio1 = quantidadeInseridos/2 - 1;
                        int meio2 = quantidadeInseridos/2;
                        mediana = (temp[meio1] + temp[meio2]) / 2.0;
                    } else {
                        int meio = quantidadeInseridos/2;
                        mediana = temp[meio];
                    }
                    cout << "mediana da glicemia " << mediana << endl;
                }
                break;

            case 5:
                cout << "saindo do programa" << endl;
                break;

            default:
                cout << "opcao invalida" << endl;
        }

    } while(opcao != 5);

    return 0;
}
