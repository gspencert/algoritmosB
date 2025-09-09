#include <iostream>
#include "funcoes.h"
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
            case 1: {
                int valor;
                cout << "digite valor da glicemia (45 a 450): ";
                cin >> valor;
                cadastrarDadoGlicemico(glicemias, quantidadeInseridos, valor);
                break;
            }
            case 2:
                mostrarDadosGlicemicos(glicemias, quantidadeInseridos);
                break;
            case 3: {
                double media = calcularMedia(glicemias, quantidadeInseridos);
                if (quantidadeInseridos > 0)
                    cout << "media da glicemia: " << media << endl;
                break;
            }
            case 4: {
                double mediana = calcularMediana(glicemias, quantidadeInseridos);
                if (quantidadeInseridos > 0)
                    cout << "mediana da glicemia: " << mediana << endl;
                break;
            }
            case 5:
                cout << "saindo do programa" << endl;
                break;
            default:
                cout << "opcao invalida" << endl;
        }

    } while(opcao != 5);

    return 1;
}