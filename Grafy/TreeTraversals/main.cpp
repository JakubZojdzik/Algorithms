#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
 
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void postorder(struct Node* node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void inorder(struct Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "\nPreorder\n";
    preorder(root);
 
    cout << "\n\nInorder\n";
    inorder(root);
 
    cout << "\n\nPostorder\n";
    postorder(root);
    cout << '\n';
}