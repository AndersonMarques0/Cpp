#include <iostream>

using namespace std;

int main()
{
    
    int n, r, res;
    
    cout << "Escolha um número de objetos: ";
    cin >> n;
    
    cout << "\n Quantos objetos serão escolhidos: ";
    cin >> r;
    if( n < r){
        cout << "\nNúmero inválido!\n";
    }else{
        
        
        int fat_n = 1, fat_r = 1, fat=1;
        for(int i=n; i > 0; i--){
            fat_n = fat_n * i;
        }
        
        for(int i=r; i > 0; i--){
            fat_r = fat_r * i;
        }
        
        for(int i=n-r; i > 0; i--){
            fat = fat * i;
        }
        
        res = fat_n / (fat_r * fat);
        
        cout << "Número de combinações feitas: " << res;
    
    }   
    
    

    return 0;
}