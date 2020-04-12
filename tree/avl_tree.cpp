
#include <iostream>
using namespace std;

/*
      y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3

*/

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    int height;    
};

int max(int a, int b) {return a > b ? a : b; }

int height(Node *n) { return n == NULL ? 0 : n->height; }

Node *newNode(int val) {
    Node *node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->right), height(y->left))+1;
    x->height = max(height(x->right), height(x->left))+1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(height(y->right), height(y->left))+1;
    x->height = max(height(x->right), height(x->left))+1;

    return y;
}

int getBalance(Node *n) { return n == NULL ? 0 : height(n->left) - height(n->right); } 

Node *insert(Node *node, int val) {
    if (node == NULL)
        return newNode(val);

    if (val < node->data) {
        node->left = insert(node->left, val);
    }    
    else if (val > node->data) {
        node->right = insert(node->right, val);
    }
    else {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    // LL
    if (balance > 1 && val < node->left->data) {
        return rightRotate(node);
    }

    // RR
    if (balance < -1 && val > node->right->data) {
        return leftRotate(node);
    }

    // LR 
    if (balance > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RR 
    if (balance < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}


void preOrder(Node *root) {  
    if(root != NULL) {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

int main(int argc, char const *argv[])
{
    Node *root = NULL;  
      
    root = insert(root, 1);  
    root = insert(root, 2);  
    root = insert(root, 3);  
    root = insert(root, 4);  
    root = insert(root, 5);  
    root = insert(root, 6);   
    preOrder(root);  
    cout << endl;
    return 0;
}
