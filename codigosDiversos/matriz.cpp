#include <iostream>

using namespace std;

int main(){
    int i,j;
    int matriz[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

    for (i=0;i<4;i++){
        for ( j = 0; j < 3; j++ ){
            cout << matriz[i][j]<< "\t";
        }
    }

    cout << "\n";
    return 0;
}