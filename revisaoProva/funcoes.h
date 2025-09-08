#include <iostream>
#include <string>
using namespace std;

int contarLetraNaPalavra(string palavra, char letra) {
    int quantidade = 0;
    for (int i = 0; i < palavra.size(); i++) if (palavra[i] == letra) quantidade++;
    return quantidade;
}

bool verificarDataValida(string diaStr, string mesStr, string anoStr) {
    int dia = stoi(diaStr), mes = stoi(mesStr), ano = stoi(anoStr);
    if (mes < 1 || mes > 12 || dia < 1) return false;
    int diasPorMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) diasPorMes[2] = 29;

    if (dia <= diasPorMes[mes]) {
        return true;
    } else {
        return false;
    }
}

int contarVogaisNaFrase(string frase) {
    int quantidade = 0;
    for (int i = 0; i < frase.size(); i++) {
        char letra = tolower(frase[i]);
        if (letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u') quantidade++;
    }
    return quantidade;
}

string converterFraseParaMaiuscula(string frase) {
    for (int i = 0; i < frase.size(); i++){
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool verificarVetorOrdenado(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho-1; i++){
        if (vetor[i] > vetor[i+1]){
            return false;
        }
    }
    return true;
}

string obterPrimeiroNome(string nomeCompleto) {
    string primeiroNome = "";
    for (int i = 0; i < nomeCompleto.size(); i++) {
        if (nomeCompleto[i]==' ') break;
        primeiroNome += nomeCompleto[i];
    }
    return primeiroNome;
}

int contarConsoantesNaFrase(string frase) {
    int quantidade = 0;
    for (int i = 0; i < frase.size(); i++) {
        char letra = tolower(frase[i]);
        if ((letra >= 'a' && letra <= 'z') && !(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'))
            quantidade++;
    }
    return quantidade;
}

string inverterPalavra(string palavra) {
    string invertida = "";
    for (int i = palavra.size()-1; i >= 0; i--) invertida += palavra[i];
    return invertida;
}

int somarVetor(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) soma += vetor[i];
    return soma;
}