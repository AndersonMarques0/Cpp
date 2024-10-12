#include <iostream>

using namespace std;

int main()
{
    
    int vetor1[6], vetor2[6], produto[6], i;
    
    cout<<"Digite 6 números: ";
    
    for(i=0;i<6;i++){
        
        cin>>vetor1[i];
        
    }
    
    cout<<"Digite outros 6 números: ";
    
    for(i=0;i<6;i++){
        
        cin>>vetor2[i];
        
    }
    
    cout<<"O resultado da multiplicação dos números é : \n";
    
    for(i=0;i<6;i++){
        
        produto[i] = vetor1[i] * vetor2[i];
        
        cout<<produto[i]<<endl;
    }

    return 0;
}