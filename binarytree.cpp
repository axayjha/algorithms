/*
    Complete binary tree implementation

    Akshay Anand
    CSE, 4th Sem
    29/06/2017

*/

#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

bool powerOfTwo(int);

class Node
{
    //Tree node
    int data;
    Node* left;
    Node* right;
    public:
        Node(){ this->left = NULL; this->right=NULL; };
        int getData() { return this->data; };
        void setData(int data) { this->data = data; };
        Node* getLeft()  { return this->left; };
        Node* getRight() { return this->right; };
        void setLeft(Node* node) { this->left = node; };
        void setRight(Node* node) { this->right = node; };       

};


void Display(Node*);  //  Dummy function to get rid of parameter in class function 
int GetHeight(Node*); //  " " " 


class Tree
{
    Node* root;
    public:
        Tree(){root= NULL;};
        Node* Root(){return this->root;};
        void insert(int data);
        void display();
        int getHeight();

};

class qNode
{
    // Queue node
    Node* tree_node;
    qNode* next;
    public:
        qNode() { next=NULL; };
        Node* getTreeNode() { return this->tree_node; };
        qNode* getNext() { return this->next; };
        void setTreeNode(Node* tree_node) { this->tree_node = tree_node; };
        void setNext(qNode *next) { this->next = next; };
};

class queue
{
    /*
        Queue implemented using linked list to store tree nodes
    */
    qNode* head;
    public:
        queue(){head=NULL;};
        qNode* Head(){return this->head;};
        void enqueue(Node* tree_node);
        Node* dequeue();
        void display();
};


void queue::enqueue(Node* tree_node)
{
    qNode* temp = this->head;
    if(this->head == NULL)
    {
        this->head = new qNode();
        this->head->setTreeNode(tree_node);
        return;        
    }
    else
    {
        while(this->head->getNext() != NULL)
            this->head = this->head->getNext();

        qNode *newnode = new qNode();
        newnode->setTreeNode(tree_node);
        this->head->setNext(newnode);
        this->head = temp;
        return;  

    }
}

Node* queue::dequeue()
{
    if(this->head)
    {
        Node* res=this->head->getTreeNode();
        this->head=this->head->getNext();
        return res;
    }
    else throw std::invalid_argument( "QUEUE EMPTY! Can't dequeue." ); 
}

/* //Dummy test function
void queue::display()
{
    qNode* temp =this->head;
    std::cout << "[ ";
    while(this->head!=NULL)
    {
        std::cout << (this->head)->getTreeNode()->getData() << ", ";
        this->head = this->head->getNext();
    }
    std::cout<< "]" << endl;
    this->head = temp;
}
*/

void Tree::insert(int data)
{
    static queue q1;
    if(this->Root() == NULL)
    {
        this->root = new Node();
        this->root->setData(data);
        Node* n1 = new Node();
        Node* n2 = new Node();
        this->Root()->setLeft(n1);
        this->Root()->setRight(n2);
        q1.enqueue(this->Root()->getLeft());
        q1.enqueue(this->Root()->getRight());
        return;
    }
    else
    {
        Node* temp = q1.dequeue();
        temp->setData(data);
        Node* n1 = new Node();
        Node* n2 = new Node();
        temp->setLeft(n1);
        temp->setRight(n2);
        q1.enqueue(temp->getLeft());
        q1.enqueue(temp->getRight());
    }

}


int GetHeight(Node *node)
{
    static int i=0;
    static int height = 0;    
    if(node == NULL)  return height - 1;       
    else
    {               
        if(powerOfTwo(++i)){ height++;}        
        GetHeight(node->getLeft());
        GetHeight(node->getRight());                       
    }
}

int Tree::getHeight()
{
    GetHeight(this->Root());
}



void Display(Node* node)
{
    /*
        Level order display
    */
    static queue q1;
    static int i=1;
    if(node->getLeft()==NULL || node->getRight() ==NULL) return;
    if(powerOfTwo(i)) std::cout<< "Level " << (log(i)/log(2)) <<": ";
    std::cout << node->getData() << " ";
    if(powerOfTwo(++i))  std::cout<<endl;
    if(node->getLeft()!=NULL)
        q1.enqueue(node->getLeft());
    if(node->getRight()!=NULL)    
        q1.enqueue(node->getRight());
    Display(q1.dequeue());     

}

void Tree::display()
{
    Display(this->Root());
   
}

int main()
{
    Tree t1;   
    t1.insert(1);
    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);
    t1.insert(7); 
    t1.display();
    return 0;
}

bool powerOfTwo(int num)
{
    /*returns true if the number is a power of 2, false otherwise*/
    for(int i=0; i<=num/2; i++)
    {
        if(pow(2, i) == num)
            return true;
    }
    return false;
}