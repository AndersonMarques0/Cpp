#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class String
{
    private:
        static const int max=80;
        char str[max];
    public:
        String()
        {
            str[0] = '\0';
        }
        
        String (char s[])
        {
            strcpy(str,s);
        }
        
        String(int i)
        {
            strcpy(str, std::to_string(i).c_str());
        }
        
        operator int() const
        {
            return atoi(str);
        }
        
        void print() const
        {
            cout << str << endl;
        }
};

int main()
{
    String s;
    int x = 1234;
    s = x;
    
    cout << "S = "; s.print();
    
    String A="5678";
    int y;
    y = A;
    
    cout << endl << "y = " << y << endl;

    return 0;
}