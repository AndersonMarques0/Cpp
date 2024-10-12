#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int lap=45,bor=2345,can=420,cad=8;
    
    
    cout << "\n\n\n";
    cout << setfill('.');
    cout << '\n' << "Lápis:    " << setw(12) << lap;
    cout << '\n' << "Borracha: " << setw(12) << bor;
    cout << '\n' << "Caneta:   " << setw(12) << can;
    cout << '\n' << "Caderno:  " << setw(12) << cad;

    return 0;
}