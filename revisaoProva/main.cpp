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
    return dia <= diasPorMes[mes];
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
    for (int i = 0; i < frase.size(); i++) frase[i] = toupper(frase[i]);
    return frase;
}

bool verificarVetorOrdenado(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho-1; i++) if (vetor[i] > vetor[i+1]) return false;
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
                cout << "digite uma palavra: "; getline(cin, palavra);
                cout << "digite uma letra: "; cin >> letra;
                cout << "a letra '" << letra << "' aparece " << contarLetraNaPalavra(palavra, letra) << " vezes." << endl;
                break;
            }
            case 2: {
                cin.ignore();
                string dia, mes, ano;
                cout << "digite dia: "; getline(cin, dia);
                cout << "digite mes: "; getline(cin, mes);
                cout << "digite ano: "; getline(cin, ano);
                cout << (verificarDataValida(dia, mes, ano) ? "data valida" : "data invalida") << endl;
                break;
            }
            case 3: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; getline(cin, frase);
                cout << "quantidade de vogais: " << contarVogaisNaFrase(frase) << endl;
                break;
            }
            case 4: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; getline(cin, frase);
                cout << "frase em maiusculas: " << converterFraseParaMaiuscula(frase) << endl;
                break;
            }
            case 5: {
                int tamanho;
                cout << "digite o tamanho do vetor: "; cin >> tamanho;
                int vetor[tamanho];
                for (int i = 0; i < tamanho; i++) {
                    cout << "digite vetor[" << i << "]: ";
                    cin >> vetor[i];
                }
                cout << (verificarVetorOrdenado(vetor, tamanho) ? "vetor esta ordenado" : "vetor nao esta ordenado") << endl;
                break;
            }
            case 6: {
                cin.ignore();
                string nome;
                cout << "digite o nome completo: "; getline(cin, nome);
                cout << "primeiro nome: " << obterPrimeiroNome(nome) << endl;
                break;
            }
            case 7: {
                cin.ignore();
                string frase;
                cout << "digite uma frase: "; getline(cin, frase);
                cout << "quantidade de consoantes: " << contarConsoantesNaFrase(frase) << endl;
                break;
            }
            case 8: {
                cin.ignore();
                string palavra;
                cout << "digite uma palavra: "; getline(cin, palavra);
                cout << "palavra invertida: " << inverterPalavra(palavra) << endl;
                break;
            }
            case 9: {
                int tamanho;
                cout << "digite o tamanho do vetor: "; cin >> tamanho;
                int vetor[tamanho];
                for (int i = 0; i < tamanho; i++) {
                    cout << "digite vetor[" << i << "]: "; cin >> vetor[i];
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