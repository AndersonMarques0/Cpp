#include <iostream>

using namespace std;

int main()
{
    int pos, fib=1, aux=0, res=0;
    
    cout << "Digite um número para descobrir o número da sequência Fibonnaci que está nessa posição." << endl;
    cout << "Digite um número maior que 0: ";
    cin >> pos;
    if( pos < 1){
        cout << "Número inválido!" << endl;
        cout << "Digite novamente: ";
        cin >> pos;
    }
    
    if(pos < 3){
        res = 1;
    }else{
        for(int i=0; i < pos-1  ; i++){
            res = fib + aux;
            aux = fib;
            fib = res;
        }
    }
        
        
    
    
    cout << "O número que está na posição digitada é " << res;
    
    return 0;
}