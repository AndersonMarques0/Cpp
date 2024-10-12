#include <iostream>

using namespace std;

int main()
{
    int num, qtdd, total, viagem;
    string escolha;
    
    cout<<"Digite \'E\' para escolhar viagens no exterior.\nDigite \'B\' para viagens no Brasil.\n";
    cin>>escolha;
    
    if(escolha=="E"){
        cout<<"Destinos\tPreço por pessoa.\n";
        cout<<"Nova York\t2200\nFrança\t3550\nCancun\t3900\nMadri\t4000\n";
        cout<<"Digite a quantidade de passagens: ";
        cin>>qtdd;
        cout<<"Digite o número corresponde com o destino.\n";
        cout<<"1-Nova York  2-França  3-Cancun  4-Madri\n";
        cin>>viagem;
        switch(viagem){
            case 1:
                total = qtdd*2200;
            break;
            case 2:
                total = qtdd*3550;
            break;
            case 3:
                total = qtdd*3900;
            break;
            case 4:
                total = qtdd*4000;
            break;
        }
    }else if(escolha=="B"){
        cout<<"Destinos\tPreço por pessoa.\n";
        cout<<"Rio de Janeiro\t700\nSalvador\t900\nPorto Alegre\t880\n";
        cout<<"Digite a quantidade de passagens: ";
        cin>>qtdd;
        cout<<"Digite o número corresponde com o destino.\n";
        cout<<"1-Rio de Janeiro  2-Salvador  3-Porto Alegre\n";
        cin>>viagem;
        switch(viagem){
            case 1:
                total = qtdd*700;
            break;
            case 2:
                total = qtdd*900;
            break;
            case 3:
                total = qtdd*880;
            break;
        }
    }
    
    cout<<"O custo total da viagem é "<<total<<".";

    return 0;
}