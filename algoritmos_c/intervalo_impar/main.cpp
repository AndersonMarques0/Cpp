#include <iostream>

using namespace std;

int main()
{
    int inicio,fim;
    cout<<"Digite o início do intervalo: ";
    cin>>inicio;
    cout<<"Digite o fim do intervalo: ";
    cin>>fim;
    for(inicio;inicio<=fim;inicio++){
        if(inicio%2!=0){
            cout<<inicio<<" | ";
        }
    }

    return 0;
}
