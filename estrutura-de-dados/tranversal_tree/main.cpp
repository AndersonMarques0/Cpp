#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

void levelOrder(Node *root)
{
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

void preOrder(Node *root)
{
    if(root == NULL) return;
    
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
    
}

void inOrder(Node *root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if(root == NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

bool isSubtreeLesser(Node *root, int value)
{
    if(root == NULL) return true;
    if(root->data <= value 
        && isSubtreeLesser(root->left, value)
        && isSubtreeLesser(root->right,value))
        return true;
    else
        return false;
}

bool isSubtreeGreater(Node *root, int value)
{
    if(root == NULL) return true;
    if(root->data > value 
        && isSubtreeGreater(root->left, value)
        && isSubtreeGreater(root->right,value))
        return true;
    else
        return false;
}

bool isBinarySearchTree(Node *root)
{
    if(root == NULL) return true;
    if(isSubtreeLesser(root->left,root->data)
        && isSubtreeGreater(root->right,root->data)
        && isBinarySearchTree(root->left)
        && isBinarySearchTree(root->right))
        return true;
    else
        return false;
}

bool isBstUtil(Node* root, int minValue, int maxValue)
{
    if(root == NULL) return true;
    
    if(root->data < minValue && root->data > maxValue
        && isBstUtil(root->left, minValue, root->data)
        && isBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node* root)
{
    return isBstUtil(root, int_min, int_max);
}

Node* Delete(Node *root, int data)
{
    if(root == NULL)
    {
        return root;
    }else
    {
        if(data < root->data)
        {
            root->left = Delete(root->left, data);
        }else
        {
            if(data > root->data)
            {
                root->right = Delete(root->right, data);
            }else // node will be deleted
            {
                // node no child
                if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = NULL;
                    return root;
                }else // node one child
                {
                    if(root->left == NULL)
                    {
                        Node *temp = root;
                        root = root->right;
                        delete temp;
                        return root;
                    }
                    
                    if(root->right == NULL)
                    {
                        Node *temp = root;
                        root = root->left;
                        delete temp;
                        return root;
                    }
                    
                    if(root->left != NULL && root->right != NULL)
                    {
                        Node *temp = findMin(root->right);
                        root->data = temp->data;
                        root->right = Delete(root->right, temp->data);
                    }
                }
            }
        }
    }
    return root;
}

Node* find(Node* root, int data)
{
    while(root != NULL)
    {
        if(data > root->data)
            root = root->right;
        else if(data < root->data)
            root = root->left;
        else
            return root;
    }
    return NULL; // se o data não estiver na árvore
}

Node* findMin(Node* root)
{
    if(root == NULL) return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* getsucessor(Node* root, int data)
{
    Node* current = find(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL)
    {
        return findMin(current->right);
    }else
    {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}



int main()
{
    std::cout<<"Hello World";

    return 0;
}
