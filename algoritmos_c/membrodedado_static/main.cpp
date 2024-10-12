#include <iostream>

using namespace std;

class Rec
{
    private:
        static int n;
    public:
        Rec() { n++; }
        int getRec() const { return n;}
        ~Rec() { n--; }
};

int Rec::n = 0;

int main()
{
    Rec n1, n2, n3;
    
    cout << n1.getRec() << endl;
    cout << n2.getRec() << endl;
    cout << n3.getRec() << endl;
    
    {
        Rec n4, n5, n6;
        cout << n1.getRec() << endl;
    }
    
    cout << n1.getRec() << endl;

    return 0;
}