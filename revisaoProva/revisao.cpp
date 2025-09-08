#include "funcoes.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    int opcao;

    while (true) {
        cout << "=== menu ===" << endl;
        cout << "1 - contar letra em palavra" << endl;
        cout << "2 - validar data" << endl;
        cout << "3 - contar vogais em frase" << endl;
        cout << "4 - converter frase para maiuscula" << endl;
        cout << "5 - verificar se vetor esta ordenado" << endl;
        cout << "6 - obter primeiro nome" << endl;
        cout << "7 - contar consoantes em frase" << endl;
        cout << "8 - inverter palavra" << endl;
        cout << "9 - somar elementos de vetor" << endl;
        cout << "10 - sair" << endl;
        cout << "opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cin.ignore();
                string palavra;
                char letra;
                cout << "digite uma palavra: "; 
                getline(cin, palavra);
                cout << "digite uma letra: "; 
                cin >> letra;
                cout << "a letra '" << letra << "' aparece " << contarLetraNaPalavra(palavra, letra) << " vezes." << endl;
                break;
            }
            case 2: {
                cin.ignore();
                string dia, mes, ano;
                cout << "digite dia: "; 
                getline(cin, dia);
                cout << "digite mes: "; 
                getline(cin, mes);
                cout << "digite ano: "; 
                getline(cin, ano);

                if (verificarDataValida(dia, mes, ano)) {
                    cout << "data valida" << endl;
                } else {
                    cout << "data invalida" << endl;
                }
                break;
            }
            case 3: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; 
                getline(cin, frase);
                cout << "quantidade de vogais: " << contarVogaisNaFrase(frase) << endl;
                break;
            }
            case 4: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; 
                getline(cin, frase);
                cout << "frase em maiusculas: " << converterFraseParaMaiuscula(frase) << endl;
                break;
            }
            case 5: {
                int tamanho;
                cout << "digite o tamanho do vetor: "; 
                cin >> tamanho;
                int vetor[tamanho];
                for (int i = 0; i < tamanho; i++) {
                    cout << "digite vetor[" << i << "]: ";
                    cin >> vetor[i];
                }

                if (verificarVetorOrdenado(vetor, tamanho)) {
                    cout << "vetor esta ordenado" << endl;
                } else {
                    cout << "vetor nao esta ordenado" << endl;
                }
                break;
            }
            case 6: {
                cin.ignore();
                string nome;
                cout << "digite o nome completo: "; 
                getline(cin, nome);
                cout << "primeiro nome: " << obterPrimeiroNome(nome) << endl;
                break;
            }
            case 7: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; 
                getline(cin, frase);
                cout << "quantidade de consoantes: " << contarConsoantesNaFrase(frase) << endl;
                break;
            }
            case 8: {
                cin.ignore();
                string palavra;
                cout << "digite uma palavra: "; 
                getline(cin, palavra);
                cout << "palavra invertida: " << inverterPalavra(palavra) << endl;
                break;
            }
            case 9: {
                int tamanho;
                cout << "digite o tamanho do vetor: "; 
                cin >> tamanho;
                int vetor[tamanho];
                for (int i = 0; i < tamanho; i++) {
                    cout << "digite vetor[" << i << "]: "; 
                    cin >> vetor[i];
                }
                cout << "soma dos elementos: " << somarVetor(vetor, tamanho) << endl;
                break;
            }
            case 10:
                cout << "saindo do programa..." << endl;
                return 0;
            default:
                cout << "opcao invalida" << endl;
        }

        cout << "----------------------------------" << endl;
    }
    return 1;
}