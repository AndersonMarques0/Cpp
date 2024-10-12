#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct Node *head;

Node* getNewNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int x)
{
    Node* newNode = getNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void print()
{
    Node* temp = head;
    cout << "Forward: ";
    while(temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void reversePrint()
{
    Node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    cout << "Reverse: ";
    while(temp != NULL)
    {
        cout << temp->data;
        temp = temp->prev;
    }
    cout << endl;
    
}

int main()
{
    head = NULL;
    
    insertAtHead(2); print(); reversePrint();
    insertAtHead(4); print(); reversePrint();
    insertAtHead(6); print(); reversePrint();

    return 0;
}
