#include <iostream>

using namespace std;

class Ponto
{
    private:
        int x, y;
    public:
        Ponto(int x1=0, int y1=0) : x(x1), y(y1) {}
        
        Ponto operator ++();
        Ponto operator ++(int);
        
        void print() const;
};

Ponto Ponto::operator++()   // pre-fixado
{
    ++x;
    ++y;
    return Ponto(x, y);
}

Ponto Ponto::operator++(int) // pos-fixado
{
    ++x;
    ++y;
    return Ponto(x-1, y-1);
}

void Ponto::print() const
{
    cout << '(' << x << ',' << y << ')' << endl;
}

int main()
{
    Ponto A, B(5,6), C;
    
    /*
    cout << "A = "; A.print();
    cout << "B = "; B.print();
    
    ++A;
    ++B;
    
    cout << "++A = "; A.print();
    cout << "++B = "; B.print();

    C=++A;
    
    cout << "C = "; C.print();
    */
    
    cout << "++A =";
    (++A).print();
    
    cout << "B++ =";
    (B++).print();
    
    cout << "A = "; A.print();
    cout << "B = "; B.print();

    return 0;
}
