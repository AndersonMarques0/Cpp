#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

void insert(Node **head, int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertPosition(Node **head ,int data, int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    Node* temp2 = *head;
    for(int i=0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print(Node *head)
{
    Node *temp;
    cout << "List is: ";
    for(temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << ", ";
    }
    
    cout << endl;
}

void Delete(Node** head, int n)
{
    Node* temp1 = *head;
    
    if(n == 1)
    {
        *head = temp1->next;
        delete(temp1);
        return;
    }
    
    for(int i = 0; i < n-2; i++)
    {
        if(temp1->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        temp1 = temp1->next;
    }    
    
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete(temp2);
}

Node* reverse(Node* head)
{
    Node* current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void recursionPrint(Node* head)
{
    if(head != NULL)
    {
        cout << head->data << ", ";
        recursionPrint(head->next);
    }
}

void reversePrint(Node *p)
{
    if(p != NULL)
    {
        reversePrint(p->next);
        cout << p->data;
    }
}

int main()
{
    Node *head = NULL;
    
    /*cout << "How many numbers? \n";
    
    int n, i, x;
    cin >> n;
    
    for(i = 0; i < n; i++)
    {
        cout << "\nEnter the number \n";
        cin >> x;
        insert(&head, x);
        print(head);
    }*/
    
    insertPosition(&head,2,1);
    insertPosition(&head,3,2);
    insertPosition(&head,4,1);
    insertPosition(&head,5,2);
    print(head);
    
    //Delete(&head,5);
    //head = reverse(head);
    
    reversePrint(head);

    return 0;
}
