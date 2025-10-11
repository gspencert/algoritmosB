#include <iostream>
#include <algorithm>
using namespace std;

#define TAM 100

bool cadastrarDadoGlicemico(int glicemias[], int &quantidadeInseridos, int valor) {
    if (quantidadeInseridos == TAM) {
        cout << "vetor lotado..." << endl;
        return false;
    }
    if (valor < 45 || valor > 450) {
        cout << "valor invalido! digite entre 45 e 450." << endl;
        return false;
    }
    glicemias[quantidadeInseridos] = valor;
    quantidadeInseridos++;
    cout << "valor cadastrado com sucesso" << endl;
    return true;
}

void mostrarDadosGlicemicos(int glicemias[], int quantidadeInseridos) {
    if (quantidadeInseridos == 0) {
        cout << "nenhum valor cadastrado." << endl;
        return;
    }
    cout << "valores cadastrados:" << endl;
    for (int i = 0; i < quantidadeInseridos; i++) {
        cout << "valor " << (i+1) << ": " << glicemias[i] << endl;
    }
    cout << "total: " << quantidadeInseridos << " registros" << endl;
}

double calcularMedia(int glicemias[], int quantidadeInseridos) {
    if (quantidadeInseridos == 0) {
        cout << "nenhum dado pra calcular a media" << endl;
        return 0.0;
    }
    double soma = 0;
    for (int i = 0; i < quantidadeInseridos; i++) {
        soma += glicemias[i];
    }
    return soma / quantidadeInseridos;
}

double calcularMediana(int glicemias[], int quantidadeInseridos) {
    if (quantidadeInseridos == 0) {
        cout << "nenhum dado pra calcular a mediana" << endl;
        return 0.0;
    }
    int temp[TAM];
    for (int i = 0; i < quantidadeInseridos; i++) {
        temp[i] = glicemias[i];
    }
    sort(temp, temp + quantidadeInseridos);

    if (quantidadeInseridos % 2 == 0) {
        int meio1 = quantidadeInseridos / 2 - 1;
        int meio2 = quantidadeInseridos / 2;
        return (temp[meio1] + temp[meio2]) / 2.0;
    } else {
        int meio = quantidadeInseridos / 2;
        return temp[meio];
    }
}
