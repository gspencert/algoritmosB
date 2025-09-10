#include "funcao.h"
#include <iostream>
using namespace std;
#define TAM 2

int main () {
    
    int numeroSecreto[TAM], numeroChute[TAM];
    bool naoAcertou = true;


    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;

    while (naoAcertou){
        jogoAdivinhacao (numeroSecreto, numeroChute);
    }
    
    return 1;
}