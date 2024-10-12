#include <iostream>

using namespace std;

int main()
{
    int i, k, fatorial, res, ans=1;
    cout<<"Este programa calcula a fatorial do número digitado.\n";
    cout<<"Digite um número: ";
    cin>>fatorial;
    if(fatorial==0 || fatorial==1){
        res = 1;
    }else if(fatorial>1){
        for(i=1;i<=fatorial;i++){
            ans = ans * i;
        }
        res = ans;
    }
    
    cout<<"Este é o fatorial de "<<fatorial<<" é "<<res<<".";
    
    
    
    return 0;
}

