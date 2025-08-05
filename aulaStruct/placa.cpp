#include <iostream>
#include <string>

#define TAM 5

using namespace std;

int main(){
    cout << "exemplo de placa: ";
    string placa;
    string vetor[TAM];

    for(i=0;i<TAM;i++){
    cout << "insira uma placa";
    cin >> placa;

    vetor[i] = placa;
    }
    return 0;
}