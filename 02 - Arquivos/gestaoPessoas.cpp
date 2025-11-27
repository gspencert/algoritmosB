#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

#include "meusMetodos.h"

int main() {
    Pessoa vetor[TAM];
    int qtdPessoas;
    string baseDados = "base.csv";

    qtdPessoas = conectarBase(baseDados, vetor, TAM);
    menu(vetor, qtdPessoas); 
    
    return 1;
}