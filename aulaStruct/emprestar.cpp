#include <iostream>
#include <string>
#include <ctime>
#define TAM 4
#include <meusIncludes.h>
using namespace std;

struct Emprestimo {
    string nome;
    string celular;
    string descricao;
    string dataEmprestimo;
    string dataDevolucao;
};

int main()
{
    int opcao;
    Emprestimo meusItens[TAM]; 
    Emprestimo item;
    int qtdEmprestimos = 0;

    do
    {
        cout << "\nM E N U" << endl;
        cout << "1 - EMPRESTAR" << endl;
        cout << "2 - DEVOLVER" << endl;
        cout << "3 - LISTAR EMPRESTIMOS" << endl;
        cout << "4 - SAIR" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "\nAREA DE EMPRESTIMO" << endl;
            if (qtdEmprestimos == TAM) {
                cout << "Voce nao tem itens para emprestar" << endl;
            } else {
                cout << "Pessoa: ";
                getline(cin, item.nome);

                cout << "Numero de telefone: ";
                getline(cin, item.celular);

                cout << "Item: ";
                getline(cin, item.descricao);
                {
                    time_t agora = time(0);
                    tm *tempoLocal = localtime(&agora);
                    char buffer[20];
                    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d",
                        tempoLocal->tm_mday,
                        tempoLocal->tm_mon + 1,
                        tempoLocal->tm_year + 1900,
                        tempoLocal->tm_hour,
                        tempoLocal->tm_min,
                        tempoLocal->tm_sec
                    );
                    item.dataEmprestimo = buffer;
                }
                item.dataDevolucao = "";

                meusItens[qtdEmprestimos] = item;
                qtdEmprestimos++;
                cout << "Item registrado com sucesso em " << item.dataEmprestimo << endl;
            }
            break;

        case 2:
            cout << "\nAREA DE DEVOLUCAO" << endl;
            if (qtdEmprestimos == 0) {
                cout << "Nenhum item esta emprestado" << endl;
            } else {
                for (int i = 0; i < qtdEmprestimos; i++) {
                    cout << i + 1 << " - " << meusItens[i].descricao
                         << " (para " << meusItens[i].nome << ")" << endl;
                }
                cout << "Digite o numero do emprestimo para devolver: ";
                int num;
                cin >> num;
                cin.ignore();

                if (num >= 1 && num <= qtdEmprestimos) {
                    time_t agora = time(0);
                    tm *tempoLocal = localtime(&agora);
                    char buffer[20];
                    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d",
                        tempoLocal->tm_mday,
                        tempoLocal->tm_mon + 1,
                        tempoLocal->tm_year + 1900,
                        tempoLocal->tm_hour,
                        tempoLocal->tm_min,
                        tempoLocal->tm_sec
                    );
                    meusItens[num - 1].dataDevolucao = buffer;

                    cout << "Item devolvido com sucesso em "
                         << meusItens[num - 1].dataDevolucao << endl;
                } else {
                    cout << "Numero invalido." << endl;
                }
            }
            break;

        case 3:
            cout << "\nLISTAGEM DE EMPRESTIMOS" << endl;
            if (qtdEmprestimos == 0) {
                cout << "Nenhum item esta emprestado" << endl;
            } else {
                for (int i = 0; i < qtdEmprestimos; i++) {
                    cout << "Emprestimo " << i + 1 << endl;
                    cout << "Item: " << meusItens[i].descricao << endl;
                    cout << "Pessoa: " << meusItens[i].nome
                         << ". Celular: " << meusItens[i].celular << endl;
                    cout << "Data do emprestimo: " << meusItens[i].dataEmprestimo << endl;
                    if (!meusItens[i].dataDevolucao.empty()) {
                        cout << "Data da devolucao: " << meusItens[i].dataDevolucao << endl;
                    } else {
                        cout << "Ainda nao devolvido" << endl;
                    }
                    cout << "----------------------------" << endl;
                }
            }
            break;

        case 4:
            cout << "Encerrando programa..." << endl;
            break;

        default:
            cout << "Opcao invalida." << endl;
            break;
        }        
    } while (opcao != 4);

    cout << "Programa encerrado." << endl;
    return 0;
}