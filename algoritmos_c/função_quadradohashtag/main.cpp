#include <iostream>

using namespace std;

void quadrado(int lado)
    {
        int i, cont=0;
        for(i=1;i<=lado;i++)
        {
            cout<<"#";
            if(i==lado)
            {
                cout<<endl;
                i=0;
                
            }
            cont++;
            if(cont==(lado*lado))
            {
                break;
            }
        }
    }

int main()
{
    int num;
    
    cout<<"Este programa imprime um quadrado com o valor do lado digitado.\n";
    cout<<"Digite o valor do lado: ";
    cin>>num;
    quadrado(num);
    
    return 0;
}