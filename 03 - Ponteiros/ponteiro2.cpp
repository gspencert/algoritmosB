#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;
    
    cout << "valor de x: " << x << endl;
    cout << "endereco de x (&x): " << &x << endl;
    cout << "valor armazenado em p (endereco): " << p << endl;
    cout << "valor apontado por p (*p): " << *p << endl;

    return 0;
}
