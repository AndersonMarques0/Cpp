#include <iostream>

using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* getNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* insert(BstNode* root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
        return root;
    }else{
        
        if(data <= root->data)
        {
            root->left = insert(root->left, data);
        }else
        {
            root->right = insert(root->right, data);
        }
        
    }
    return root;
}

void print(BstNode* root)
{
    if(root == NULL) return;
    
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

bool search(BstNode* root, int data)
{
    if(root == NULL) return false;
    else
    {
        if(root->data == data)
        {
            return true;
        }else
        {
            if(data <= root->data)
            {
                return search(root->left, data);
            }else
            {
                return search(root->right, data);
            }
        }
        
    }
}

int findMin(BstNode *root)
{
    if(root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }else
    {
        if(root->left == NULL) return root->data;
    }
    return findMin(root->left);
}

int findHeight(BstNode* root)
{
    if(root == NULL)
        return -1;
    return max(findHeight(root->left), findHeight(root->right)) +1;
}

int main()
{
    BstNode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 25);
    
    int number,res, h;
    
    cout << " Enter number be searched \n";
    cin >> number;
    
    if(search(root,number) == true) cout << "Found\n";
    else cout << "Not found\n";
    
    res = findMin(root);
    cout << endl << res;
    
    h = findHeight(root);
    
    cout << h;
    
    return 0;
}