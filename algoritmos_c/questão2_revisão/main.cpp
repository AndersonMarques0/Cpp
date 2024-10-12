#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int idade, cont=1, tamanho, maior, menor, qtddmulher, qtdd=0;
    double salario, mediasalario=0, somasalario;
    string sexo;
    
    cout<<"Digite a quantidade de pessoas que participarão da pesquisa: ";
    cin>>tamanho;
    
    while(cont<=tamanho){
        cout<<"Informe seu sexo(m = masculino e f = feminino): ";
        cin>>sexo;
        cout<<"Informe sua idade: ";
        cin>>idade;
        if(idade<0){
            break;
        }
        cout<<"Informe seu salário: ";
        cin>>salario;
        
        somasalario = somasalario + salario;
        
        if(cont==1){
            maior = idade;
            menor = idade;
        }else{
            if(idade>maior){
                maior = idade;
            }else if(idade<menor){
                menor = idade;
            }
        }
        if(sexo=="f" && salario>1500){
            qtddmulher++;
        }
        if(idade>-1){
            cont++;
        }else if(cont==tamanho){
            break;
        }
        qtdd++;
    }
    
    mediasalario = somasalario/tamanho;
    
    
    if(qtdd>0){
        cout<<"Média dos salários do município: "<<mediasalario<<".\n";
        cout<<"Maior idade: "<<maior<<".\n";
        cout<<"Menor idade: "<<menor<<".\n";
        cout<<"Quantidade de mulheres com salário maior que R$ 1.500,00 é "<<fixed<<setprecision(2)<<qtddmulher<<".";
    }else{
        cout<<"Ninguém foi cadastrado.";
    }
    
    return 0;
}
