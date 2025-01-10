#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void display(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    display(root);
    return 0;
}
