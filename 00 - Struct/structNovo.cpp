#include <iostream>
using namespace std;

#define TAM 5

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

void lerMostrarAlunos() {

    Aluno alunos[TAM];

    cout << "Digite os dados dos 5 alunos:\n";
    for (int i = 0; i < TAM; i++) {
        cout << "\nAluno " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> alunos[i].nome;
        cout << "Matricula: ";
        cin >> alunos[i].matricula;
        cout << "Nota: ";
        cin >> alunos[i].nota;
    }

    cout << "\n=== Dados dos Alunos ===\n";
    for (int i = 0; i < TAM; i++) {
        cout << "Nome: " << alunos[i].nome
             << " | Matricula: " << alunos[i].matricula
             << " | Nota: " << alunos[i].nota << endl;
    }
}

int main() {
    lerMostrarAlunos();
    return 0;
}
