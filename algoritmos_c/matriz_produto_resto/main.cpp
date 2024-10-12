#include <iostream>

using namespace std;

int main()
{
    double vetorA[12], vetorB[12], matriz[2][12];
    int i, c, l;
    
    cout<<"Digite 12 valores: ";
    for(i=0;i<12;i++)
    {
        cin>>vetorA[i];
    }
    
    cout<<"Digite outros 12 valores: ";
    for(i=0;i<12;i++)
    {
        cin>>vetorB[i];
    }
    
    for(l=0;l<2;l++)
    {
        for(c=0;c<12;c++)
        {
            if(l==0)
            {
                matriz[l][c] = vetorA[c]*2;
            }else
            {
                matriz[l][c] = vetorB[c] - 5;
            }
        }
    }
    
    for(l=0;l<2;l++)
    {
        cout<<endl;
        for(c=0;c<12;c++)
        {
            cout<<matriz[l][c]<<" | ";
        }
    }

    return 0;
}