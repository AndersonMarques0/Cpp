#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i=1, sexo, contmulher=0, qtdd=50;
    double altura, alturamulher, alturaturma, menor, maior, mediamulher, mediaturma;
    
    for(i;i<=qtdd;i++){
        cout<<"Informe sua altura: ";
        cin>>altura;
        cout<<"Informe seu sexo (masculino=1 e feminino=2): ";
        cin>>sexo;
        
        
        
        
        if(i==1){
            maior = altura;
            menor = altura;
        }else{
            if(altura>maior){
                maior = altura;
            }else if(altura<menor){
                menor = altura;
            }
        }
        
        if(sexo==2){
            alturamulher = alturamulher + altura;
            contmulher++;
        }
        
        alturaturma = alturaturma + altura;
        
    }
    mediamulher = alturamulher/contmulher;
    mediaturma = alturaturma/qtdd;
    cout<<"Maior altura: "<<maior<<endl;
    cout<<"Menor altura: "<<menor<<endl;
    cout<<"Média da altura das mulheres: "<<fixed<<setprecision(2)<<mediamulher<<endl;
    cout<<"Média geral: "<<fixed<<setprecision(2)<<mediaturma;

    return 0;
}
