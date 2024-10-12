#include <iostream>

using namespace std;

#define MIN(x,y) (x < y) ? (x) : (y)

inline int min(int x, int y){
    return (x < y) ? x : y;
}

int main()
{
    int n1=1, n2=2, n;
    
    //n = MIN(n1++,n2++);
    n = min(n1++, n2++);
    
    cout << '\n' << "n1 = " << n1 << ", n2 = " << n2 << ", n = " << n;

    return 0;
}