#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void listarPessoas(Pessoa vetor[], int qtdPessoas) {
    cout << "Listar pessoas...." << endl;
    for (int i = 0; i < qtdPessoas; i++) {
        cout << "Nome: " << vetor[i].nome << ". Email: " << vetor[i].email << endl;
    }
    cout << "_______________" << endl;
    cout << "Total de registros: " << qtdPessoas << endl;

}

void menu (Pessoa vetor[], int qtdPessoas) {
    int opcao;
    do {
        system("cls");
        cout << "MENU" << endl;
        cout << "1 - Listar pessoas " << endl;
        cout << "2 - Cadastrar pessoa " << endl;;
        cout << "3 - Sair" << endl;;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:            
            listarPessoas(vetor, qtdPessoas);
            break;
        case 2:
            cout << "Cadastrar pessoa" << endl;;
            //
            break;
        case 3:            
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }

        system("pause");
    } while (opcao != 3);    
}


void split(string vetor[], string str, string deli = " ") {        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}


int conectarBase(string baseDados, Pessoa vetor[], int tamanho) {
    int qtdPessoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados); 

    if (!procuradorArquivo) {
        cout << "Arquivo da base de dados não localizado. Programa encerrado." << endl;
        exit(0);
    } 
    if (qtdPessoas == tamanho) {
        cout << "Vetor lotado. Programa encerrado." << endl;
        exit(0);
    }

    //le o arquivo capturando as pessoas linha a linha
	string linha;
    string vetorLinha[2];
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo, linha); //lendo a linha inteira
        //linha = Alexandre Zamberlan,alexz@ufn.edu.br
        split(vetorLinha, linha, ",");
        //vetorLinha[0] = "Alexandre Zamberlan"
        //vetorLinha[1] = "alexz@ufn.edu.br"
        vetor[qtdPessoas].nome = vetorLinha[0];
        vetor[qtdPessoas].email = vetorLinha[1];
        qtdPessoas += 1;
	}
	procuradorArquivo.close();
    cout << "Quantidade " << qtdPessoas << endl;
    return qtdPessoas;
}