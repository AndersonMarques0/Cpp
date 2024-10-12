#include <iostream>

using namespace std;

int main()
{
     int n, i, media, idade, anterior, soma;
    cout<<"Digite o número de pessoas: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Digite sua idade: ";
        cin>>idade;
        idade = idade + anterior;
        anterior = idade;
    }
    media = idade/n;
    if(media>60){
        cout<<"A turma é denominada de idosos.";
    }else if(media>=26 && media<=60){
        cout<<"A turma é denominada de adultos.";
    }else if(media<=25){
        cout<<"A turma é denominada de jovens.";
    }

    return 0;
}
