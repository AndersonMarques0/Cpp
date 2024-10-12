#include <iostream>

using namespace std;

int main()
{
    
    double matriz[4][5];
    int l, c;
    
    cout<<"Digite os elementos da matriz: \n";
    
    for(l=0;l<4;l++)
    {
        for(c=0;c<5;c++)
        {
            cin>>matriz[l][c];
        }
    }
    
    for(l=0;l<4;l++)
    {
        cout<<endl;
        for(c=0;c<5;c++)
        {
            cout<<matriz[l][c]<<" | ";
        }
    }
    

    return 0;
}