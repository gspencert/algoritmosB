#include <iostream>
#include <string>
#include "meusIncludes.h"

#define TAM 4

using namespace std;

int main()
{
    string placas[TAM];
    int qtdInseridos = 0;
    int opcao;

    do {
        cout << "=== MENU ===" << endl; 
        cout << "1- cadastrar carros" << endl;
        cout << "2- listar carros" << endl; 
        cout << "3- remover carro" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cout << "--------------" << endl;

        switch (opcao)
        {
            case 1:
                cadastrarCarro(placas, qtdInseridos);
                break;
            case 2:
                listarCarros(placas, qtdInseridos);
                break;
            case 3:
                removerCarro(placas, qtdInseridos);
                break;
            default:
                cout << "opcao invalida..." << endl;
                break;
        }

    } while (opcao != 3);
}