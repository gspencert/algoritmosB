#include <iostream>
#include <string>
using namespace std;

int contarLetraNaPalavra(string palavra, char letra) {
    int quantidade = 0;
    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] == letra) {
            quantidade++;
        }
    }
    return quantidade;
}

bool verificarDataValida(string diaStr, string mesStr, string anoStr) {
    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int ano = stoi(anoStr);

    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;

    int diasPorMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        diasPorMes[2] = 29;
    }

    if (dia > diasPorMes[mes]) return false;
    return true;
}

int contarVogaisNaFrase(string frase) {
    int quantidadeVogais = 0;
    for (int i = 0; i < frase.size(); i++) {
        char letra = tolower(frase[i]);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            quantidadeVogais++;
        }
    }
    return quantidadeVogais;
}

string converterFraseParaMaiuscula(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool verificarVetorOrdenado(int vetorNumeros[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetorNumeros[i] > vetorNumeros[i + 1]) {
            return false;
        }
    }
    return true;
}

string obterPrimeiroNome(string nomeCompleto) {
    string primeiroNome = "";
    for (int i = 0; i < nomeCompleto.size(); i++) {
        if (nomeCompleto[i] == ' ') break;
        primeiroNome += nomeCompleto[i];
    }
    return primeiroNome;
}

int main() {
    int opcao;

    while (true) {
        cout << "=== menu ===\n";
        cout << "1 - contar letra em palavra\n";
        cout << "2 - validar data\n";
        cout << "3 - contar vogais em frase\n";
        cout << "4 - converter frase para maiuscula\n";
        cout << "5 - verificar se vetor esta ordenado\n";
        cout << "6 - obter primeiro nome\n";
        cout << "7 - sair\n";
        cout << "opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string palavra;
                char letra;
                cout << "digite uma palavra: ";
                cin >> palavra;
                cout << "digite uma letra: ";
                cin >> letra;
                cout << "a letra '" << letra << "' aparece " 
                     << contarLetraNaPalavra(palavra, letra) << " vezes." << endl;
                break;
            }
            case 2: {
                string diaStr, mesStr, anoStr;
                cout << "digite dia: ";
                cin >> diaStr;
                cout << "digite mes: ";
                cin >> mesStr;
                cout << "digite ano: ";
                cin >> anoStr;
                if (verificarDataValida(diaStr, mesStr, anoStr)) {
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
                int tamanhoVetor;
                cout << "digite o tamanho do vetor: ";
                cin >> tamanhoVetor;
                int vetorNumeros[tamanhoVetor];
                for (int i = 0; i < tamanhoVetor; i++) {
                    cout << "digite vetor[" << i << "]: ";
                    cin >> vetorNumeros[i];
                }
                if (verificarVetorOrdenado(vetorNumeros, tamanhoVetor)) {
                    cout << "vetor esta ordenado" << endl;
                } else {
                    cout << "vetor nao esta ordenado" << endl;
                }
                break;
            }
            case 6: {
                cin.ignore();
                string nomeCompleto;
                cout << "digite o nome completo: ";
                getline(cin, nomeCompleto);
                cout << "primeiro nome: " << obterPrimeiroNome(nomeCompleto) << endl;
                break;
            }
            case 7:
                cout << "saindo do programa..." << endl;
                return 0;
            default:
                cout << "opcao invalida" << endl;
                break;
        }

        cout << "----------------------------------" << endl;
    }

    return 0;
}
