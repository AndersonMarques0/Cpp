#include <iostream>

using namespace std;

int main()
{
    int base, expoente, i, ans, anterior=1;
    cout<<"Este programa calcula a potência do número digitado.\n";
    cout<<"Digite o valor da base: ";
    cin>>base;
    cout<<"Digite o valor do expoente: ";
    cin>>expoente;
    for(i=0;i<=expoente;i++){
        
        if(expoente==0){
            ans = 1;
        }else if(expoente==1){
            ans = base;
        }else{
            
            ans = base * anterior;
            anterior = ans;
            if(i==expoente){
                ans = ans/base;
            }
        }
    
    }
    cout<<"O resultado é "<<ans<<".";
    
    return 0;
}
