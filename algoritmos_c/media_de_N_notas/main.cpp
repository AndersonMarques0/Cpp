#include <iostream>

using namespace std;

int main()
{
    int media, i, n, nota, anterior;
    cout<<"Informe a quantidade de notas: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Informe a nota: ";
        cin>>nota;
        nota = nota + anterior;
        anterior = nota;
    }
    media = nota/n;
    cout<<"Esta é a média das notas digitadas: "<<media<<".";
    

    return 0;
}
