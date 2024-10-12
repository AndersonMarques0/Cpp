#include <iostream>
#include <iomanip>
using namespace std;

// imprime um histograma horizontal
// mostra matriz de duas dimensões como argumentos de funções

const int MES = 3;

void histograma(int pecas[][MES], int nfunc);

int main()
{
    const int FUNC = 5;
    int pecas[FUNC][MES];
    
    for(int i=0; i < FUNC; i++){
        for(int j=0; j < MES; j++){
            cout << "Funcionário " << i+1 << " mês " << j+1 << ": ";
            cin >> pecas[i][j];
        }
    }
    
    histograma(pecas,FUNC);

    return 0;
}

void histograma (int pecas[][MES], int nfunc){
    
    const float MAXBARRA = 50.0;
    int max=0;
    
    for(int i=0; i<nfunc; i++){
        int temp=0;
        
        for(int j=0; j < MES; j++){
            temp += pecas[i][j];
        }
        
        if(max < temp) max = temp;
    }
    
    
    for(int i=0; i < nfunc; i++){
        int temp = 0;
        
        for(int j=0; j < MES; j++) temp += pecas[i][j];
        
        cout << setw(2) << i+1 << " - " << setw(5) << temp << ":";
        
        int tam = int(float(temp)/float(max)*MAXBARRA);
        
        for(int j=0; j < tam; j++) cout << "*";
        
        cout << "\n\n";
        
        
    }
    
}
