#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 80;

class String
{
    private:
        char str[MAX];
    public:
        String()  // construtor default
        {
            str[0] = '\0';
        }
        
        String( char ch, int n); // copia n vezes ch
        
        String( char s[])  // converte matriz em string
        {
            strcpy(str, s);
        }
        
        int Len() const
        {
            return strlen(str);
        }
        
        void print() const
        {
            cout << str << endl;
        }
};

String::String( char ch, int n)
{
    int i;
    for(i=0; i<n;i++)
        str[i]=ch;
    str[i] = '\0';
}

int main()
{
    String S1('=',21), S2("Feliz aniversário! ");
    String S3 = "Estamos na primavera. ";
    String S4, S5;
    
    cout << "S1 = "; S1.print();
    cout << "S2 = "; S2.print();
    cout << "S3 = "; S3.print();
    
    S4 = "O mundo gira!";
    
    cout << "S4 ="; S4.print();
    
    S5 = S1;
    
    cout << "S5 = "; S5.print();
    
    cout << endl;
    
    cout << "Tamanho de S1 = " << S1.Len() << endl;
    cout << "Tamanho de S2 = " << S2.Len() << endl;
    cout << "Tamanho de S3 = " << S3.Len() << endl;
    cout << "Tamanho de S4 = " << S4.Len() << endl;
    cout << "Tamanho de S5 = " << S5.Len() << endl;

    return 0;
}
