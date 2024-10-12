#include <iostream>

using namespace std;

int main()
{
    string num;
    int i=0, j;
    
    cout << "Digite um número de ao menos dois algarismos: ";
    cin >> num;
    
    j = num.size();
    while( j >= i ){
        
        cout << num[j];
        j--;
    }

    return 0;
}