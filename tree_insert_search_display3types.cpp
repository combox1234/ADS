#include<iostream>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root,int key){
    if(root==NULL){
        return new node(key);
    }   
    if(root -> key == key){
        return root;
    }
    if(root -> key < key ){
        root -> right = insert(root -> right,key);
    }
    else{
        root -> left = insert(root -> left,key);
    }
    return root;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root -> key<<" ";
        inorder(root->right);
    }
}
void preorder(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
void post_order(node* root){
    if(root != NULL){
        post_order(root -> left);
        post_order(root -> right);
        cout<<root->key<<" ";
    }
}
void search(node* root,int key){
    if(root != NULL){
        if(root->key == key){
            cout<<"Element found\t"<<root -> key<<endl;
            }
            else if(root->key < key){
                search(root->right,key);
                search(root -> left,key);
            }
        }
}       
int main()
{
  node* root = NULL;
  int choice,key;
  do{
    cout<<"\n...........................\n1. insert\n2. display\n3. search\n0. exitnwhat's the option you are willing to pick: ";
    cin>>choice;
    cout<<"\n...........................\n";
  switch(choice){
    case 1:
    cout<<"what you want to insert :\n";
    cin>>key;
    root = insert(root,key);
    break;
    case 2:
        cout<<"1. inorder\n2. preorder\n3.postorder\n"<<"Enter the option u pick: ";
        cin>>choice;
        cout<<"\n";
        switch(choice){
                  case 1:
                        inorder(root);
                        break;
                    case 2:
                        preorder(root);
                        break;
                    case 3:
                        post_order(root);
                        break;
                    default:
                    cout<<"invalid";
        }
        break;
    case 3:
    cout<<"\nenter the data ypu wamt to enter: ";
    cin>>key;
    cout<<"\n";
    search(root,key);
    break;
  default:
  cout<<"invalid";
  }
}while(choice != 0);
  return 0;
}
