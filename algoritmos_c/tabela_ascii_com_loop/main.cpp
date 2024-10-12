#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned char ch = ' ';
    int stop;
    
    
    cout << "\nImprimindo caracteres da tabela ASCII\n";
    for(stop= 32; stop <= 255; stop++ ){
        
        cout << setfill('.') << endl;
        cout << "Caractere:          " << setw(5) << ch;
        cout << "\nCódigo decimal:     " << setw(5) << dec << ch;
        cout << "\nCódigo hexadecimal: " << setw(5) << hex << ch;
        cout << setfill('.') << endl;
        ch++;
    }

    return 0;
}
