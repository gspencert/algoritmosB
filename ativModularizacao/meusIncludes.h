#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#define TAM 4
using namespace std;

void cadastrarCarro(string placas[], int &qtdInseridos){
    if (qtdInseridos == TAM){
        cout << "garagem lotada, tente novamente mais tarde!";
    } else{
        
        string placa;
        cout << "digite a placa: ";
        cin.ignore();
        getline(cin, placa);

        for (int i = 0; i < qtdInseridos; i++){
            if (placas[i] == placa){
                cout << "essa placa ja foi registrada" << endl;
                return;
            }
        }

        placas[qtdInseridos] = placa;
        qtdInseridos++;
        cout << "Placa " << placa << " foi registrada" << endl;
        }
    }

void listarCarros(string placas[], int qtdInseridos){
    if (qtdInseridos == 0){
        cout << "garagem vazia, deve cadastrar um carro antes." << endl;
    } else{
        cout << "placas na garagem: " << endl;
        for (int i = 0; i < qtdInseridos; i++){
            cout << "placa " << (i + 1) << ": " << placas[i] << endl;
        }
        cout << "total de placas registradas: " << qtdInseridos << endl;
        cout << "--------------" << endl;
    }
}

void removerCarro(string placas[], int qtdInseridos){
    if (qtdInseridos == 0 ){
        cout << "nenhum carro para remover" << endl;
        return;
    }
    
    listarCarros(placas, qtdInseridos);

    int escolha; 
    cout << "Digite o numero do carro que deseja remover (1 - " << qtdInseridos << "): ";
    cin >> escolha;

    if (escolha < 1 || escolha > qtdInseridos){
        cout << "opcao invalida!" << endl;
        return;
    }

    int indice = escolha - 1;

    cout << "removendo placa " << placas[indice] << endl;

    for (int i = indice; i < qtdInseridos; i++){
        placas[i] = placas[i + 1];
    }

    qtdInseridos--;
    cout << "carro removido com sucesso!" << endl;
    return;
}