#include <iostream>

using namespace std;

int main()
{
    int a, b, c, soma=0;
    
    cout << "Digite um número maior que um: ";
    cin >> a;
    if(a <= 1){
        cout << '\n' << "Você digitou um número inválido!";
        cout << '\n' << "Digite um número maior que um: ";
        cin >> a;
    }
    
    cout << "Digite um segundo número: ";
    cin >> b;
    cout << "Digite um terceiro número: ";
    cin >> c;
    
    for(int i=b+1; i < c; i++){
        
        if(i%a == 0){
            soma += i;
        }
        
    }
    
    cout << "Soma de todos os números inteiros entre b e c que são divisíveis por a: " << soma;
    
    return 0;
}