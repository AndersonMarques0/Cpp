/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char sexo;
    double altura, pesoideal;
    
    cout<<"Digite \"m\" para masculino ou \"f\" feminino: ";
    cin>>sexo;
    cout<<"Digite sua altura em metros: ";
    cin>>altura;
    
    switch(sexo){
        case 'm':
            pesoideal = (72.7 * altura) - 58;
        break;
        case 'f':
            pesoideal = (62.1 * altura) - 44.7;
        break;
        
    }
    
    cout<<"Este é o peso ideal "<<fixed<<setprecision(2)<<pesoideal<<".";

    return 0;
}