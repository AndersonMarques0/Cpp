#include <iostream>
#include <iomanip>
using namespace std;

const double pi = 3.14;

class Graus
{
    private:
        double g;
    public:
        Graus() : g(0.0) {} // construtor
        Graus(double x) : g(x) {} // construtor
        
        void print()
        {
            cout << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << setprecision(2) << g << "º" << endl;
        }
    
};

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
        
        operator Graus() const;
        
        
        void print()
        {
            cout << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << setprecision(2) << rad << " rad" << endl;
        }
        
};

Radianos::operator Graus() const
{
    return Graus(180.0*rad/pi);
}

int main()
{
    Graus gr;
    Radianos rad(pi);
    
    gr = rad;
    
    gr.print();
    rad.print();

    return 0;
}