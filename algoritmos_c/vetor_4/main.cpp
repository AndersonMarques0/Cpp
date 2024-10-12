#include <iostream>

using namespace std;

int main()
{
    int notas[8], i, media;
    
    cout<<"Digite 8 notas: ";
    
    for(i=0;i<8;i++){
        
        cin>>notas[i];
        
        media = media + notas[i];
    }
    
    cout<<"\nAs notas digitadas foram: \n";
    for(i=0;i<8;i++){
        
        cout<<i+1<<" - "<<notas[i]<<endl;
        
    }
    
    media = media/8;
    cout<<"A média das notas é "<<media;
    
    return 0;
}
