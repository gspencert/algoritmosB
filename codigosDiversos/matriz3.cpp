#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    int i,j;
    int matriz[5][5];
    int somaPrincipal = 0, somaSecundaria = 0;
    int diagonalPrincipal[5];
    int diagonalSecundaria[5];

    srand(time(nullptr));

    for ( i = 0 ; i < 5 ; i++ ){
        for ( j = 0 ; j < 5 ; j++ ){
            matriz[i][j] = rand() % 100 + 1;
            cout << matriz[i][j] << "\t";;
        }
        cout << endl;
    }

    cout << "\n";

    for ( i = 0 ; i < 5 ; i++ ){
        somaPrincipal += matriz[i][i];
        somaSecundaria += matriz[i][4 - i];

        diagonalPrincipal[i] = matriz[i][i];
        diagonalSecundaria[i] = matriz[i][4 - i];

    }

    cout << "elementos da diagonal principal: ";
    for ( i = 0 ; i < 5 ; i++ ){
        cout << diagonalPrincipal[i] << "\t";
    }

    cout << "\n";

    cout << "elementos da diagonal segundaria: ";
    for ( i = 0 ; i < 5 ; i++ ){
        cout << diagonalSecundaria[i] << "\t";
    }

    cout << "\n";

    cout << "soma dos elementos da diagonal principal: " << somaPrincipal << "\n";
    cout << "soma dos elementos da diagonal secundaria: " << somaSecundaria << "\n";

    cout << "\n";
    return 0;
}