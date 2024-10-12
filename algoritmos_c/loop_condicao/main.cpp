#include <iostream>

using namespace std;

int main()
{
    
    int n=1, x, y, z, teste;
    
    do{
        x = n/3;
        y = n/5;
        z = n/7;
        n++;
    }while((n%3 != 2) || (n%5 != 3) || (n%7 != 4));
    
    if((n%3 == 2) && (n%5 == 3) && (n%7 == 4)){
        cout << " O menor número inteiro que satisfaz a condição é " << n;
        cout << endl << " Valor de x: " << x;
        cout << endl << " Valor de y: " << y;
        cout << endl << " Valor de z: " << z;
    }
        
    

    return 0;
}