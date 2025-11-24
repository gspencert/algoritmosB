#include <iostream>
#include <string>
#include <fstream>
#include <limits> 
#include <sstream>

using namespace std;

struct Carro {
    string placa;
    string horarioEntrada;
    string comentario;
    string nota;
    string modelo;
};

inline void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void split(string vetor[], string str) {
    const string deli = ","; 
    int start = 0;
    int end = str.find(deli);
    int i = 0;

    vetor[0] = vetor[1] = vetor[2] = vetor[3] = vetor[4] = "";

    while (end != -1 && i < 4) { 
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }

    if (i < 5) { 
        vetor[i] = str.substr(start);
    }
}

void listarCarros(Carro vetor[], int qtdCarros) {
    cout << "Listar carros...." << endl;
    cout << "--------------------------------" << endl;
    if (qtdCarros == 0) {
        cout << "Nenhum carro registrado." << endl;
    } else {
        for (int i = 0; i < qtdCarros; i++) {
            cout << "Placa: " << vetor[i].placa
                 << " | Horario: " << vetor[i].horarioEntrada
                 << " | Comentario: " << vetor[i].comentario
                 << " | Nota: " << vetor[i].nota
                 << " | Modelo: " << vetor[i].modelo
                 << endl;
        }
    }
    cout << "--------------------------------" << endl;
    cout << "Total de registros: " << qtdCarros << endl;
}

void adicionarCarro(Carro vetor[], int tamanho, int& qtdCarros) {
    cout << "Cadastrar carro...." << endl;

    if (qtdCarros >= tamanho) {
        cout << "Garagem lotada. Nao e possivel adicionar mais carros." << endl;
        return;
    }
    
    limparBuffer(); 

    Carro novoCarro;
    cout << "Digite a Placa: ";
    getline(cin, novoCarro.placa);

    cout << "Digite o Horario de Entrada (ex: HH:MM): ";
    getline(cin, novoCarro.horarioEntrada);

    cout << "Digite um comentario: ";
    getline(cin, novoCarro.comentario);

    cout << "Digite a nota (0 a 10): ";
    getline(cin, novoCarro.nota);

    cout << "Digite o modelo: ";
    getline(cin, novoCarro.modelo);

    vetor[qtdCarros] = novoCarro;
    qtdCarros++;

    cout << "Carro adicionado com sucesso. Total: " << qtdCarros << endl;
}

void removerCarro(Carro vetor[], int& qtdCarros) {
    cout << "Remover veiculo...." << endl;
    if (qtdCarros == 0) {
        cout << "Nenhum carro para remover." << endl;
        return;
    }

    string placaRemover;
    limparBuffer(); 
    cout << "Digite a Placa do carro para remover: ";
    getline(cin, placaRemover);

    int indiceRemover = -1;
    for (int i = 0; i < qtdCarros; ++i) {
        if (vetor[i].placa == placaRemover) {
            indiceRemover = i;
            break;
        }
    }

    if (indiceRemover != -1) {
        if (indiceRemover < qtdCarros - 1) {
            vetor[indiceRemover] = vetor[qtdCarros - 1];
        }
        qtdCarros--;
        cout << "Carro removido com sucesso." << endl;
    } else {
        cout << "Carro nao encontrado." << endl;
    }
}

void salvarBase(const string& nomeBase, Carro vetor[], int qtdCarros) {
    ofstream escritorArquivo(nomeBase); 
    if (!escritorArquivo.is_open()) {
        cerr << "ERRO ao salvar arquivo." << endl;
        return;
    }

    for (int i = 0; i < qtdCarros; ++i) {
        escritorArquivo << vetor[i].placa << "," 
        << vetor[i].horarioEntrada << "," 
        << vetor[i].comentario << "," 
        << vetor[i].nota << "," 
        << vetor[i].modelo << endl;
    }
}


void menu(Carro vetor[], int tamanho, int& qtdCarros, const string& nomeBase) {
    int opcao;
    do {
        system("cls"); 
        cout << "MENU - Gerenciamento de Garagem" << endl;
        cout << "1 - Listar carros" << endl;
        cout << "2 - Adicionar carro" << endl; 
        cout << "3 - Remover veiculo" << endl; 
        cout << "4 - Sair " << endl;          
        cout << "Opcao: ";
        
        if (!(cin >> opcao)) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            limparBuffer();
            opcao = 0; 
        }

        switch (opcao)
        {
        case 1:
            listarCarros(vetor, qtdCarros);
            break;
        case 2:
            adicionarCarro(vetor, tamanho, qtdCarros); 
            break;
        case 3:
            removerCarro(vetor, qtdCarros); 
            break;
        case 4:
            salvarBase(nomeBase, vetor, qtdCarros); 
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }
        
        if (opcao != 4) {
            system("pause");
        }
    } while (opcao != 4); 
}

int conectarBase(const string& nomeBase, Carro vetor[], int tamanho) {
    int qtdCarros = 0;
    ifstream procuradorArquivo; 
    procuradorArquivo.open(nomeBase);

    if (!procuradorArquivo) {
        cout << "Arquivo nao localizado." << endl;
        return 0;
    }
    
    string linha;
    string vetorLinha[5];
    while (getline(procuradorArquivo, linha)) { 
        if (linha.empty()) continue;
        if (qtdCarros == tamanho) break;

        split(vetorLinha, linha); 
        vetor[qtdCarros].placa = vetorLinha[0];
        vetor[qtdCarros].horarioEntrada = vetorLinha[1];
        vetor[qtdCarros].comentario = vetorLinha[2];
        vetor[qtdCarros].nota = vetorLinha[3];
        vetor[qtdCarros].modelo = vetorLinha[4];

        qtdCarros++;
    }
    procuradorArquivo.close();
    return qtdCarros;
}