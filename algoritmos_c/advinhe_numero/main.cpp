#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int x, res;
    
    srand(static_cast<unsigned>(time(0)));
    
    x = rand() % 100;
    
    cout << "Advinhe o número que estou pensando." << endl;
    cout << "Digite um número: ";
    cin >> res;
    
    
    while(res != x){
        if(res < x){
            cout << "Você digitou um número menor!";
            cout << '\n' << "Tente novamente: ";
            cin >> res;
        }else{
            cout << "Você digitou um número maior!";
            cout << '\n' << "Tente novamente: ";
            cin >> res;
        }
        
    }
    
    if(res == x){
        cout << "Você acertou!";
    }

    return 0;
}