#include <iostream>

using namespace std;

int main()
{
    int idades[8], x;
    
    cout<<"Digite 8 idades: ";
    
    for(x=0;x<8;x++){
        
        cin>>idades[x];
        
    }
    
    cout<<"\nRelatório das idades < 18\n";
    
    for(x=0;x<8;x++){
        if(idades[x]<18)
        {
            cout<<idades[x]<< " | ";    
        }
    }
    
    return 0;
}