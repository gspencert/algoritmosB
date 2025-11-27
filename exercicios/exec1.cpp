#include <iostream>
#include <string>
#include <algorithm> 
#define TAM 10

using namespace std;

int main(){

    srand(time(NULL));
    int numeroSorteado;
    int pares = 0, impares = 0;

    cout << "Numeros sorteados: ";
    for (int i = 0; i < TAM; i++){
        
        numeroSorteado = rand() % 100;
        cout << "\t" << numeroSorteado;

        if (numeroSorteado % 2 == 0){
            pares++;
        } else {
            impares++;
        }
    }
    
    cout << endl;
    cout << "Quantidade de pares: " << pares << endl;
    cout << "Quantidade de impares: " << impares << endl;
    return 0;
}