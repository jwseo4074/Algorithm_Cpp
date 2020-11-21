#include <iostream>
using namespace std;
int C;
bool check = false;
struct Node{
    string data;
    Node* left;
    Node* right;
};
Node* insert(Node* root ,string data){
    if(root == nullptr){
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if( data <= root->data)  root->left = insert(root->left, data);
    else  root->right=insert(root->right, data);
    return root;
}
struct Node* minValueNode(struct Node* node, bool choice) {
    struct Node* current = node;
    if (choice) {
      while (current && current->left != NULL)
        current = current->left;
    } else {
      while (current && current->right != NULL)
        current = current->right;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, string data2) {
    if (root == NULL)
        return root;
    if (data2 < root->data)
        root->left = deleteNode(root->left, data2);
    else if (data2 > root->data)
        root->right = deleteNode(root->right, data2);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp;
        if (root->left != NULL) {
          temp = minValueNode(root->left, 0);
          root->data = temp->data;
          root->left = deleteNode(root->left, temp->data);
        } else {
          temp = minValueNode(root->right, 1);
          root->data = temp->data;
          root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
void print_leaf(Node* root){
    if (root != nullptr){
        if(root->left == nullptr && root->right == nullptr)  cout << root->data << " ";
        print_leaf(root->left);
        print_leaf(root->right);
    }
    else return;
}
void print_depth(Node* root,int C, int b){
    C++;
    if (root != nullptr){
        if ( C==b ) {
            cout << root->data << " ";
            check = true;
        }
        print_depth(root->left,C,b);
        print_depth(root->right,C,b);
    }
    else {
        C--;
        return;
    }
}
int main() {
    Node* root = nullptr;
    int a,b;
    cin >> a;
    string sa;
    for ( int i=0 ; i<a ; i++){
        cin >> sa;
        if ( sa == "+"){
            cin >> sa;
            root = insert(root,sa);
        }
        else if ( sa == "-"){
            cin >> sa;
            root = deleteNode(root,sa);
        }
        else if ( sa == "depth"){
            cin >> b;
            C = 0;
            check = false;
            print_depth(root,C,b);
            if(!check) cout << "NO" << endl;
            cout << "\n";
        }
        else if (sa == "leaf"){
            print_leaf(root);
            cout << "\n";
        }
    }
    return 0;
}
