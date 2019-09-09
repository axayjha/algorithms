#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>
#define INF 9999
using namespace std;

template <typename T>class Queue
{
public:
        T *data;
        uint32_t capacity;
        int front, rear, size;

        Queue(int capacity)
        {
                this->size = 0;
                this->front = 0;
                this->capacity = capacity;
                this->rear = capacity - 1;
                this->data = new T[capacity];
        }

        bool isEmpty()
        {
                return this->size == 0;
        }

        bool isFull(){
                return this->size == this->capacity;
        }

        void enqueue(T val) {
                if (this->isFull()){
                        cout << "QUEUE overflow" << endl;
                        return;
                }
                        
                this->rear = (this->rear + 1) % this->capacity;
                this->data[this->rear] = val;
                this->size += 1;
        }

        T dequeue() {
                if (this->isEmpty()) {
                        cout << "QUEUE underflow" << endl;
                        T t;
                }
                T val = this->data[this->front];
                this->front = (this->front + 1) % this->capacity;
                this->size -= 1;
                return val;
        }
};

enum COLOR
{
        BLACK,
        GRAY,
        WHITE
};

class Node
{
        enum COLOR color;
        int distance;
        Node *parent;
        char name;

public:

        Node(char c)
        {
                this->name = c;
        }

        void setDistance(int d)
        {
                this->distance = d;
        }

        int getDistance()
        {
                return this->distance;
        }

        void setParent(Node *p)
        {
                this->parent = p;
        }
        Node *getNode()
        {
                return this->parent;
        }

        void setColor(COLOR c)
        {
                this->color = c;
        }

        COLOR getColor()
        {
                return this->color;
        }

        char getName()
        {
                return this->name;
        }

        void setName(char c)
        {
                this->name = c;
        }
};

int main(int argc, char const *argv[])
{
        Node *a = new Node('a');
        Node *b = new Node('b');
        Node *c = new Node('c');
        Node *d = new Node('d');
        Node *e = new Node('e');
        Node *f = new Node('f');

        Node *nodes[] = {a, b, c, d, e, f};

        map<Node *, vector<Node *> > adjList;
        adjList[a] = vector<Node *>();
        adjList[a].push_back(b);
        adjList[a].push_back(c);

        adjList[b] = vector<Node *>();
        adjList[b].push_back(d);
        adjList[b].push_back(e);

        adjList[c] = vector<Node *>();
        adjList[c].push_back(f);

        Queue<Node *> queue(100);

        for (Node *n : nodes) {
                n->setColor(WHITE);
                n->setDistance(INF);
        }
        a->setColor(GRAY);
        a->setDistance(0);
        
        queue.enqueue(a);

        while(queue.isEmpty() == false) {
                Node *u = queue.dequeue();
                for (Node* v : adjList[u]) {
                        if (v->getColor() == WHITE) {
                                v->setColor(GRAY);
                                v->setDistance(u->getDistance()+1);
                                v->setParent(u);
                                queue.enqueue(v);
                        }
                }
                u->setColor(BLACK);
                cout << u->getName() << endl;
        }

        cout << d->getDistance() << endl;

        return 0;
}
