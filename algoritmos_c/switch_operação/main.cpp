#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    double num1, num2, resultado;
    int num;
    
    cout<<"Digite dois números: \n";
    cin>>num1;
    cin>>num2;
    
    cout<<"Digite o número correspondente com a operação que deseja fazer.\n";
    cout<<"1-Soma\n2-Subtração\n3-Multiplicação\n4-Divisão\n";
    cin>>num;
    
    switch(num){
        case 1:
            resultado = num1+num2;
        break;
        case 2:
            resultado = num1-num2;
        break;
        case 3:
            resultado = num1*num2;
        break;
        case 4:
            resultado = num1/num2;
        break;
    }
    
    cout<<"O resultado da operação é "<<fixed<<setprecision(2)<<resultado<<".";

    return 0;
}
