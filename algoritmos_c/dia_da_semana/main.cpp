#include <iostream>

using namespace std;

int main()
{
    int dia;
    
    cout<<"Digite o dia da semana: ";
    cin>>dia;
    
    switch(dia){
        case 1:
            cout<<"Domingo.";
        break;
        case 2:
            cout<<"Segunda-feira";
        break;
        case 3:
            cout<<"Terça-feira";
        break;
        case 4:
            cout<<"Quarta-feira";
        break;
        case 5:
            cout<<"Quinta-feira";
        break;
        case 6:
            cout<<"Sexta-feira";
        break;
        case 7:
            cout<<"Sábado";
        break;
        default:
            cout<<"Digite um número válido.";
        break;
    }


    return 0;
}