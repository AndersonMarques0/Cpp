#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node* temp = (Node*)malloc(sizeof(Node*));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    Node* temp = front;
    if(front == NULL) return;
    if(front == rear)
    {
        front = rear = NULL;
    }else
    {
        front = front->next;
    }
    delete(temp);
}

void print()
{
    Node *temp;
    for(temp = front; temp != NULL; temp = temp->next)
    {
        cout << temp->data << ", ";
    }
    cout << endl;
}

int main()
{
    enqueue(3); enqueue(5); enqueue(7);
    dequeue();
    print();
    

    return 0;
}