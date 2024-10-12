#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

union Numero{
    char str[30];
    int i;
    float f;
}x;

enum DataType { StrType, IntType, FloatType } tipo;

void VariosTipos (char n[]){
    tipo = StrType;
    strcpy(x.str, n);
}

void VariosTipos( float n){
    tipo = FloatType;
    x.f = n;
}

void VariosTipos( int n){
    tipo = IntType;
    x.i = n;
}

void print(void);

int main()
{
    float a = 14.95;
    int b = 390;
    
    VariosTipos("VVB-Treinamento de Pessoal");
    print();
    
    VariosTipos(a);
    print();
    
    VariosTipos(b);
    print();
    
    
    return 0;
}

void print()
{
    switch (tipo)
    {
        case StrType:
            cout << "Str = " << x.str << endl;
            break;
        case IntType:
            cout << "Int = " << x.i << endl;
            break;
        case FloatType:
            cout << setprecision(2);
            cout << "Float = " << x.f << endl;
            break;
    }
}
