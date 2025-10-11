#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <limits> 

using namespace std;


struct Carro {
    string placa;
    string horarioEntrada;
};

void listarCarros(Carro vetor[], int qtdCarros);
void split(string vetor[], string str, string deli = ",");
int conectarBase(const string& nomeBase, Carro vetor[], int tamanho);

void adicionarCarro(Carro vetor[], int tamanho, int& qtdCarros);
void removerCarro(Carro vetor[], int& qtdCarros);
void menu(Carro vetor[], int tamanho, int& qtdCarros, const string& nomeBase);
void salvarBase(const string& nomeBase, Carro vetor[], int qtdCarros);

void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void listarCarros(Carro vetor[], int qtdCarros) {
    cout << "\nListar carros....\n";
    cout << "--------------------------------\n";
    if (qtdCarros == 0) {
        cout << "Nenhum carro registrado.\n";
    } else {
        for (int i = 0; i < qtdCarros; i++) {
            cout << "Placa: " << vetor[i].placa << ". Horario de Entrada: " << vetor[i].horarioEntrada << endl;
        }
    }
    cout << "--------------------------------\n";
    cout << "Total de registros: " << qtdCarros << endl;
}

void adicionarCarro(Carro vetor[], int tamanho, int& qtdCarros) {
    cout << "Cadastrar carro....\n";

    if (qtdCarros >= tamanho) {
        cout << "Garagem lotada. Nao e possivel adicionar mais carros.\n";
        return;
    }
    
    limparBuffer(); 

    Carro novoCarro;
    cout << "Digite a Placa: ";
    getline(cin, novoCarro.placa);

    cout << "Digite o Horario de Entrada (ex: HH:MM): ";
    getline(cin, novoCarro.horarioEntrada);

    vetor[qtdCarros] = novoCarro;
    qtdCarros++;

    cout << "Carro adicionado com sucesso. Total: " << qtdCarros << endl;
}

void removerCarro(Carro vetor[], int& qtdCarros) {
    cout << "Remover veiculo....\n";
    if (qtdCarros == 0) {
        cout << "Nenhum carro para remover.\n";
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
        cout << "Carro com placa " << placaRemover << " removido com sucesso.\n";
    } else {
        cout << "Carro com placa " << placaRemover << " nao encontrado.\n";
    }
}

void menu(Carro vetor[], int tamanho, int& qtdCarros, const string& nomeBase) {
    int opcao;
    do {
        
        system("cls"); 
        cout << "MENU - Gerenciamento de Garagem\n";
        cout << "1 - Listar carros\n";
        cout << "2 - Adicionar carro\n"; 
        cout << "3 - Remover veiculo\n"; 
        cout << "4 - Sair\n";          
        cout << "Opcao: ";
        
        if (!(cin >> opcao)) {
            cout << "Entrada invalida. Por favor, digite um numero.\n";
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
            cout << "Opcao invalida....\n";
            break;
        }
        
        if (opcao != 4) {
            system("pause");
        }
    } while (opcao != 4); 
}

void split(string vetor[], string str, string deli) {
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start);
}


int conectarBase(const string& nomeBase, Carro vetor[], int tamanho) {
    int qtdCarros = 0;
    ifstream procuradorArquivo; 
    procuradorArquivo.open(nomeBase);

    if (!procuradorArquivo) {
        cout << "Arquivo da base de dados nao localizado. Tentando criar um novo." << endl;
        return 0;
    }
    
	string linha;
    string vetorLinha[2];
	while (getline(procuradorArquivo, linha)){ 
        if (linha.empty()) continue; 

        if (qtdCarros == tamanho) {
            cout << "Vetor lotado. Carros restantes no arquivo foram ignorados." << endl;
            break; 
        }

        split(vetorLinha, linha, ","); 
        
        if (!vetorLinha[0].empty() && !vetorLinha[1].empty()) {
            vetor[qtdCarros].placa = vetorLinha[0];
            vetor[qtdCarros].horarioEntrada = vetorLinha[1];
            qtdCarros += 1;
        }
	}
	procuradorArquivo.close();
    cout << "Quantidade de carros carregados: " << qtdCarros << endl;
    return qtdCarros;

}

void salvarBase(const string& nomeBase, Carro vetor[], int qtdCarros) {
    ofstream escritorArquivo(nomeBase); 

    if (!escritorArquivo.is_open()) {
        cerr << "ERRO: Nao foi possivel abrir o arquivo para salvar os dados.\n";
        return;
    }

    for (int i = 0; i < qtdCarros; ++i) {
        escritorArquivo << vetor[i].placa << "," << vetor[i].horarioEntrada << "\n";
    }

    escritorArquivo.flush(); 
    escritorArquivo.close();
    cout << "Dados salvos em " << nomeBase << endl;
}