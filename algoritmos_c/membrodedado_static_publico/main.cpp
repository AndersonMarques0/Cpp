#include <iostream>

using namespace std;

class Moeda
{
    private:
        float R$;
    public:
        static float US$;
        Moeda(float x) : R$(x) {}
        Moeda()
        {
            cout << "Digite R$: "; cin >> R$;
        }
        
        float dolarUS()
        {
            return R$/US$;
        }
};

float Moeda::US$;

int main()
{
    
    cout << "Digite o valor do Dolar: ";
    cin >> Moeda::US$;
    
    Moeda A(3.5), B;
    
    cout << "A é US$ " << A.dolarUS() << endl;
    cout << "B é US$ " << B.dolarUS() << endl;
    

    return 0;
}