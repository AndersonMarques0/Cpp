#include <iostream>

using namespace std;

int main()
{
    unsigned char m[3][3];
    
    const int TRUE=1;
    const char O='o', X='x';
    
    cout << "Digite coordenadas na forma lin col: " << endl;
    
    int lin, col, j=0;
    
    for(lin=0; lin < 3; lin++)
        for(col=0; col < 3; col++)
            m[lin][col] = '.';
    
    
    while(TRUE){
        
        for(lin=0; lin < 3; lin++){
            for(col=0; col < 3; col++)
                cout << m[lin][col] << ' ';
            cout << endl;
        }
        
        if((m[0][0]==O && m[0][1]==O && m[0][2]==O ) ||
           (m[1][0]==O && m[1][1]==O && m[1][2]==O ) ||                                        
           (m[2][0]==O && m[2][1]==O && m[2][2]==O ) ||                                         
           (m[0][0]==O && m[1][0]==O && m[2][0]==O ) ||                                         
           (m[0][1]==O && m[1][1]==O && m[2][1]==O ) ||
           (m[0][2]==O && m[1][2]==O && m[2][2]==O ) ||
           (m[0][0]==O && m[1][1]==O && m[2][2]==O ) ||
           (m[0][2]==O && m[1][1]==O && m[2][2]==O ))
       {
           cout << '\a' << "Você ganhou, primeiro jogador!!!" << endl;
           break;
       }
       
       if((m[0][0]==X && m[0][1]==X && m[0][2]==X ) ||
           (m[1][0]==X && m[1][1]==X && m[1][2]==X ) ||                                        
           (m[2][0]==X && m[2][1]==X && m[2][2]==X ) ||                                         
           (m[0][0]==X && m[1][0]==X && m[2][0]==X ) ||                                         
           (m[0][1]==X && m[1][1]==X && m[2][1]==X ) ||
           (m[0][2]==X && m[1][2]==X && m[2][2]==X ) ||
           (m[0][0]==X && m[1][1]==X && m[2][2]==X ) ||
           (m[0][2]==X && m[1][1]==X && m[2][2]==X ))
       {
           cout << '\a' << "Você ganhou, segundo jogador!!!" << endl;
           break;
       }
       
       if(j==9){
           cout << '\a' << "Empatou!!!" << endl;
           break;
       }
       
       
       cout << "Coordenadas: " << endl;
       cin >> lin >> col;
       
       if(m[lin][col] == '.')
       {
           if(j%2)     m[lin][col]=X;
           else m[lin][col]=O;
           j++;
       }
       
    }

    return 0;
}