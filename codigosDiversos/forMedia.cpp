#include <iostream>

using namespace std;

int main(){

    int i;
    float nota[3], media=0;
    
    for (i=0;i<3;i++){
        cout << "digite a nota " << i+1 << ": ";
        cin >> nota[i];
        media += nota[i];
    }

    media /= 3;

    cout << "a media eh " << media;
    
    return 0;
}