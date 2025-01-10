#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* subleft;
    node* subright;

    node(int d) {
        this->data = d;
        this->subleft = NULL;
        this->subright = NULL;
    }
};
void display(node* root) {
    if (root != NULL) {
        cout << "root: " << root->data << endl;
        if (root->subleft != NULL) {
            cout << "left: " << root->subleft->data << endl;
        } else {
            cout << "left: NULL" << endl;
        }
        if (root->subright != NULL) {
            cout << "right: " << root->subright->data << endl;
        } else {
            cout << "right: NULL" << endl;
        }
    }
}
int main() {
    node* root = NULL;
    int choice, datA;
    do {
        cout << ".............................\n";
        cout << "1. Enter the data to be added in a tree at root(keep it on priority)\n";
        cout << "2. Enter the data to the left\n";
        cout << "3. Enter the data to the right\n";
        cout << "4. Display the data entered\n";
        cout << "0. Exit\n";
        cout << ".............................\n";
        cout << "Enter the option you choosed: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            if (root == NULL) {
                cout << "enter the data to be added at root: ";
                cin >> datA;
                root = new node(datA);
                cout << "data accepted...\n";
                cout << "added\n";
            } else {
                cout << "root already exists!\n";
            }
            break;
        case 2:
            if (root != NULL) {
                cout << "enter the data to be added at left: ";
                cin >> datA;
                root->subleft = new node(datA);
                cout << "data accepted...\n";
                cout << "added\n";
            } else {
                cout << "create the root node first!\n";
            }
            break;
        case 3:
            if (root != NULL) {
                cout << "enter the data to be added at right: ";
                cin >> datA;
                root->subright = new node(datA);
                cout << "data accepted...\n";
                cout << "added\n";
            } else {
                cout << "create the root node first!\n";
            }
            break;
        case 4:
            display(root);
            break;
        case 0:
            cout << "exiting...\n";
            break;
        default:
            cout << "wrong choice\n";
        }
    } while (choice != 0);

    return 0;
}