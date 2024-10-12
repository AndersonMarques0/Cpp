#include <iostream>

using namespace std;

class retangulo
{
    private:
        int base, altura;
    public:
        void init(int b, int a)
        {
            base = b;
            altura = a;
        }
        
        void printdata()
        {
            cout << "Base: " << base << "\t" << "Altura: " 
            << altura << '\t' << "Área: " << (base*altura) << endl;
        }
};

int main()
{
    retangulo x, y;
    
    x.init(6, 3);
    y.init(18, 7);
    
    x.printdata();
    y.printdata();

    return 0;
}