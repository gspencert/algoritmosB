#include <iostream>
#include <ctime>
#include <string>
#define TAM 5

using namespace std;

void preenche_nomes(string *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << "digite o nome para a posicao [" << i << "]: ";
        getline(cin, v[i]);
    }
}

void exibe_nomes(string *v, int n) {
    cout << "--- Nomes no Vetor ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "posicao [" << i << "]: " << v[i] << endl;
    }
    cout << "----------------------" << endl;
}

void busca_nome(string *v, int n, const string& nome_buscado, int& posicao_encontrada) {
    posicao_encontrada = -1;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == nome_buscado) {
            posicao_encontrada = i;
            break;
        }
    }
}

int main() {
    string vetor[TAM];
    string nome_para_buscar;
    int resultado_busca;
    
    preenche_nomes(vetor, TAM);
    
    exibe_nomes(vetor, TAM);
    
    cout << "digite o nome que deseja buscar: ";
    getline(cin, nome_para_buscar);

    busca_nome(vetor, TAM, nome_para_buscar, resultado_busca);

    if (resultado_busca != -1) {
        cout << "o nome '" << nome_para_buscar << "' foi encontrado na posicao: " << resultado_busca << endl;
    } else {
        cout << "o nome '" << nome_para_buscar << "' nao foi encontrado (retorno: -1)." << endl;
    }
    
    return 0;
}