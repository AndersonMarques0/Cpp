#include <iostream>
#include <iomanip>
using namespace std;

const double pi = 3.14;

class Radianos
{
    private:
        double rad;
    public:
        Radianos() : rad(0.0) {}
        Radianos(double r) : rad(r) {} 
        
        operator double()
        {
            return rad;
        }
        
        void print()
        {
            cout << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << setprecision(2) << rad << " rad" << endl;
        }
        
};

class Graus
{
    private:
        double g;
    public:
        Graus() : g(0.0) {} // construtor
        Graus(double x) : g(x) {} // construtor
        
        Graus(Radianos r);
        operator Radianos() const;
        
        void print()
        {
            cout << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << setprecision(2) << g << "º" << endl;
        }
    
};



Graus::Graus(Radianos r)
{
    g= (static_cast<double>(r) * 180.0)/pi;
}

Graus::operator Radianos() const
{
    return Radianos(g*pi/180.0);
}

int main()
{
    Graus gr, ga(180.0);
    Radianos rad(pi), ra;
    
    gr = rad;
    ra = ga;
    
    gr.print();
    ra.print();

    return 0;
}