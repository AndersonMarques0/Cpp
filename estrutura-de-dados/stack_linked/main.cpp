#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *top = NULL;

void push(int x)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop()
{
    Node *temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    delete(temp);
}

void print()
{
    Node *temp;
    cout << "Stack: ";
    for(temp = top; temp != NULL; temp = temp->link)
        cout << temp->data << " ";
}

int main()
{
    push(5); push(6); push(7); print(); pop();
    cout << endl; print();
    

    return 0;
}