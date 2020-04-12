/*
    Red Black Tree implementation

    http://pages.cs.wisc.edu/~skrentny/cs367-common/readings/Red-Black-Trees/
    https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

    @author Akshay Anand
    12-Apr-2020
*/

#include <iostream>

using namespace std;

typedef enum { BLACK, RED } color_t;

class Node {
public:
    Node *parent;
    Node *left;
    Node *right;
    color_t color;
    int val;
    Node(int val) {this->val = val;}
    Node() {}
};

Node* getParent(Node* n);
Node* getGrandparent(Node* n);
Node* getSibling(Node* n);
Node* getUncle(Node* n);
void rotateLeft(Node* x);
void rotateRight(Node* y);
Node* insert(Node* root, Node* n);
void insertRecurse(Node* root, Node* n);
void insertRepair(Node* n);
void insertCase1(Node* n);
void insertCase2(Node* n);
void insertCase3(Node* n);
void insertCase4(Node* n);
void insertCase4Step2(Node* n);
void inorder(Node* n);

Node* getParent(Node* n) {
    return n == nullptr ? nullptr : n->parent;
}

Node* getGrandparent(Node* n) {
    // parent of parent
    return getParent(getParent(n));
}

Node* getSibling(Node* n) {
    Node *parent = getParent(n);

    // no parent means no sibling :(
    if (parent == nullptr) 
        return nullptr;

    if (n == parent->left) 
        return parent->right;
    else   
        return parent->left;    
}

Node* getUncle(Node* n) {
    // sibling of parent
    return getSibling(getParent(n));
}

void rotateLeft(Node* x) {
    /*
                 p                 p
                / \               / \
               x   T4            y   T4
              / \               / \
            T1    y     =>     x   T3
                 / \          / \
                T2  T3       T1  T2
    */

    // 1. get names 
    Node* y = x->right;
    Node* p = getParent(x);
    assert(y != nullptr);

    // 2. rotate
    x->right = y->left;
    y->left = x;
    x->parent = y;

    // 3. fix daddy issues
    if (x->right != nullptr) {
        x->right->parent = x;
    }

    if (p != nullptr) {
        if (x == p->left) {
            p->left = y;
        } else {
            p->right = y;
        }
    }        
    y->parent = p;
}
void rotateRight(Node* y) {
    /*            
                 p                 p
                / \               / \
               y   T4            x   T4
              / \               / \
             x   T3     =>     T1  y
            / \                   / \
           T1  T2                T2  T3 
    */

    // 1. get names 
    Node* x = y->left;
    Node* p = getParent(y);
    assert(x != nullptr);

    // 2. rotate
    y->left = x->right;
    x->right = y;
    y->parent = x;

    // 3. fix daddy issues
    if (y->left != nullptr) {
        y->left->parent = x;
    } 

    if (p != nullptr) {
        if (y == p->left) {
            p->left = x;
        } else {
            p->right = x;
        }
    }

    x->parent = p;
}

Node* insert(Node* root, Node* n) {
    // 1. insert in the RB tree
    insertRecurse(root, n);

    // 2. repair the tree if any property is violated
    insertRepair(n);

    // 3. find root to return
    root = n;
    while (getParent(root) != nullptr) {
        root = getParent(root);
    }
    return root;
}

void insertRecurse(Node* root, Node* n) {
    // recurse down till leaf is found
    if (root != nullptr) {
        if (n->val < root->val) {
            if (root->left != nullptr) {
                insertRecurse(root->left, n);
                return;
            } else {
                root->left = n;
            }
        } else {
            if (root->right != nullptr) {
                insertRecurse(root->right, n);
                return;
            } else {
                root->right = n;
            }
        }
    }

    // set new node attribs
    n->parent = root;
    n->left = n->right = nullptr;
    n->color = RED;
}

void insertRepair(Node* n) {
    if (getParent(n) == nullptr) { 
        // if tree is empty
        // insert node as root with BLACK color
        insertCase1(n);
    } else if (getParent(n)->color == BLACK) {
        // if parent is black
        // nothing to worry, go take a walk
        insertCase2(n);
    } else if (getUncle(n) != nullptr && getUncle(n)->color == RED) {
        // if parent's sibling is RED
        // just need recoloring, not much to worry
        insertCase3(n);
    } else {
        // if parent's sibling is either missing or BLACK
        // need restructuring, good luck
        insertCase4(n);
    }
}

void insertCase1(Node* n) {
    n->color = BLACK;
    return;
}

void insertCase2(Node* n) {
    return;
}

void insertCase3(Node* n) {
    getParent(n)->color = BLACK;
    getUncle(n)->color = BLACK;
    getGrandparent(n)->color = RED;
    insertRepair(getGrandparent(n));
}

void insertCase4(Node* n) {
    // if parent's sibling is either missing or BLACK
    // need restructuring
    
    Node* p = getParent(n);
    Node* g = getGrandparent(n);

    if (n == p->right && p == g->left) {
        rotateLeft(p);
        n = n->left;
    } else if (n == p->left && p == g->right) {
        rotateRight(p);
        n = n->right;
    }

    insertCase4Step2(n);
}

void insertCase4Step2(Node* n) {
    Node* p = getParent(n);
    Node* g = getGrandparent(n);

    if (n == p->left) {
        rotateRight(g);
    } else {
        rotateLeft(g);
    }

    p->color = BLACK;
    g->color = RED;
}

void inorder(Node* n) {
    if (n != nullptr) {
        inorder(n->left);
        cout << n->val << " ";
        inorder(n->right);
    }
}

int main(int argc, char const *argv[])
{
    Node* n = new Node(5);
    n = insert(n, new Node(2));
    n = insert(n, new Node(1));
    n = insert(n, new Node(4));
    n = insert(n, new Node(3));

    inorder(n);
    cout << endl;

    return 0;
}
