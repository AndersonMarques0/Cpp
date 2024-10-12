#include <iostream>

using namespace std;

int main()
{
    string voto;
    int i, num, soma1, soma2, soma3;
    cout<<"Digite o números de total de votantes: ";
    cin>>num;
    cout<<"Digite o número 1 para votar no candidato x."<<endl;
    cout<<"Digite o número 2 para votar no candidato y."<<endl;
    cout<<"Digite o número 3 para votar no candidato z."<<endl;
    for(i=1;i<=num;i++){
        cout<<"Digite um número de 1 a 3: ";
        cin>>voto;
        
        if(voto=="x"){
            soma1 = soma1 + 1;
        }else if(voto=="y"){
            soma2 = soma2 + 1;
        }else if(voto=="z"){
            soma3 = soma3 + 1;
        }else{
            cout<<"Digite um número válido.\n";
            i--;
        }
    }
    cout<<"Número de votos para o candidato x é "<<soma1<<endl;
    cout<<"Número de votos para o candidato y é "<<soma2<<endl;
    cout<<"Número de votos para o candidato z é "<<soma3<<endl;
    
    

    return 0;
}