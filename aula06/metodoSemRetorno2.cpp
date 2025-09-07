#include <iostream>
#include <string>
using namespace std;

int main(){
    int numero;
    do{
        cout << "Digite um numero de 1 a 10" << endl;
        cin >> numero;

        if (numero < 1 || numero > 10){
            cout << "numero fora da faixa adequada" << endl;
        }
    } while (numero < 1 || numero > 10);
    
    return 1;
}
