#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    char ch;
    
    cout << "\nPressione uma tecla: ";
    
    cin >> ch;
    
    cout << "\n A tecla sucessora ASCII é " << char(ch+1);

    return 0;
}