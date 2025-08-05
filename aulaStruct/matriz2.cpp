#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int i,j;
    int matriz[4][3];
    int pares = 0,impares = 0;

    srand(time(NULL));

    cout << "Leitura da matriz:\n"; 
    for ( i=0 ; i < 4 ; i++){
        for ( j = 0; j < 3; j++ ){
            matriz[i][j] = rand() % 100;
            
            if(matriz[i][j] % 2 == 0){
                pares++;
            } else {
                impares++;
            }
        }
    }

    cout << "Impressao da matriz:\n";
    for ( i=0 ; i < 4 ; i++){
        for ( j = 0; j < 3; j++ ){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nQuantidade de pares: " << pares;
    cout << "\nQuantidade de impares: " << impares;
    return 0;
}