#include <iostream>
#define max_size 101
int a[max_size];
int top = -1;

using namespace std;

void push(int x)
{
    if(top == max_size - 1)
    {
        cout << "Error: stack overflow!\n";
        return;
    }
    a[++top] = x;
}

void pop()
{
    if(top == -1)
    {
        cout << "No elemento to pop!\n";
        return;
    }
    top--;
}

void print()
{
    int i;
    cout << "Stack: ";
    for(i = 0; i <= top; i++)
        cout << a[i] << ", ";
    cout << endl;
}

int main()
{
    push(2); print();
    push(5); print();
    push(10); print();
    pop(); print();
    push(12); print();

    return 0;
}