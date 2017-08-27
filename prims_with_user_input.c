/*  Implementation of Prim's algorithm using adjacency list
    this code is unnecessarily huge due to the implementations of 
    linked list, priority queue, hashtales and graph data structures.
    
    Not for faint-hearteds, for the code is dark and full of POINTERS!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 128
#define INF 99999
#define MAX 20

struct link
{
    //linked list to create adjacency list to put as 'value' in hashtable
    struct vertex *data;
    int weight;
    struct link *next;
};

struct hashElement
{   
    char *key;
    struct link *value;
};

struct hashTable
{
    struct hashElement **table;
};

struct vertex
{
    char name[MAX];
    int key; //for priority queue
    struct vertex *parent;
};

struct graph
{
    struct vertex** V; //array of pointers to vertices
    struct hashTable *Adj;
};

struct pqueue
{
    //priority queue using linked list
    struct vertex* data;
    struct pqueue* next;
};

typedef struct hashElement HashElement;
typedef struct hashTable HashTable;
typedef struct pqueue pQueue;
typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct link Link;   

/*Hash table methods------------------*/
int hash(char *);
HashTable *newHashTable();
HashElement *newHashElement(char *key, Link* value);
void insert(HashTable *table, char *key, Link* value);
void delete(HashTable *table, char *key);
Link* search(HashTable *table, char *key);
/*------------------------------------*/

/*Priority Queue methods ---------------*/
void priority_insert(pQueue **head, Vertex* node);
Vertex *extract_min(pQueue **head);
bool is_in(pQueue *head, Vertex *node);
/*--------------------------------------*/

void link_insert(Link **head, Vertex *node, int weight); //inserts element into the adjacency list in hashtable


//Vertex *newVertex(char *name); //initializes new vertex

int w(HashTable *h, char *u, char *v); //returns weight of the edge u-v


int main()
{
    int n;
    char name[20];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Vertex *vertices[n];
    for(int i=0; i<n; i++)
    {   
        vertices[i] = (Vertex*)malloc(sizeof(Vertex));     
        printf("Enter the name of the vertex #%d: ", i+1);
        scanf("%s", vertices[i]->name);
        vertices[i]->key = INF;
        vertices[i]->parent = NULL; 
    }

    printf("Enter the name of starting vertex: ");
    scanf("%s", name);
    for(int i=0; i<n; i++)
    {
        if(strcmp(vertices[i]->name, name)==0)
        {
            vertices[i]->key=0;
            break;
        }
    }
   
    Link *lists[n];
    for(int i=0; i<n; i++)
    {
        lists[i] = (Link* )malloc(sizeof(Link));
        int m, d;
        printf("Enter the number of vertices adjacent to vertex %s: ", vertices[i]->name);
        scanf("%d", &m);
        printf("Enter the adjacent vertices and their distance: \n");        
        for(int j=0; j<m; j++)
        {
            printf("Enter edge %d/%d and distance: ", j+1, m);
            scanf("%s %d", name, &d);
            for(int k=0; k<n; k++)
            {
                if(strcmp(vertices[k]->name, name)==0)
                {
                    link_insert(&lists[i], vertices[k], d);
                    break;
                }
            }

        }

    }

   

    // creating hashtable and priority queue
    HashTable* Adj =  newHashTable();
    pQueue *Q = (pQueue *)malloc(sizeof(pQueue));
    for(int i=0; i<n; i++)
    {
        insert(Adj, vertices[i]->name, lists[i]);
        priority_insert(&Q, vertices[i]);
    }
    

    Graph* G = (Graph *)malloc(sizeof(Graph));
    G->V = vertices;
    G->Adj = Adj;

    while(Q != NULL)
    {
        Vertex* u = extract_min(&Q);
        Link* head = search(G->Adj, u->name);
        Link* temp = head;
        while(head!=NULL)
        {
            if( (w(G->Adj, u->name, head->data->name) < head->data->key) && is_in(Q, head->data))
            {
                head->data->parent = u;
                head->data->key = w(G->Adj, u->name, head->data->name);
            }
            head=head->next;
        }    
        head=temp;
    }   
    
    printf("\nGraph connections:\n------------------- \n");
    int total_weight=0;
    for(int i=1; i<n; i++)
    {
        total_weight += vertices[i]->key;
        printf("%s -- %s\n", G->V[i]->name, G->V[i]->parent->name);
    }
    printf("\n-------------------\nMST weight = %d\n", total_weight);

}


int w(HashTable *h, char *u, char *v)
{
    Link *head = search(h, u);
    Link *temp = head;
    int weight = INF;
    
    while(head!=NULL)
    {        
        if(strcmp(head->data->name, v)==0)
        {
            weight = head->weight;
            break;
        }
        head = head->next;
        
    }
    head=temp;
    return weight;
}

/*
Vertex *newVertex(char *name)
{
    Vertex *newV = (Vertex *)malloc(sizeof(Vertex));
    newV->key = INF;
    newV->name = name;
    newV->parent = NULL;   //saddest line of code i've ever written
    return newV;
}
*/

int hash(char *str)
{
    int sum=0; 
    for(int i=0, n=strlen(str); i<n; i++)
    {
        sum += (int)str[i];
    }
    return sum%SIZE;
}

HashTable *newHashTable()
{
    HashTable *t = (HashTable *)malloc(sizeof(HashTable));
    //t->table = HashElement **
    t->table = (HashElement **)malloc(SIZE*sizeof(HashElement *));
    for(int i=0; i<SIZE; i++) t->table[i]=NULL;
    return t;
}

HashElement *newHashElement(char *key, Link* value)
{
    HashElement *newEntry = (HashElement *)malloc(sizeof(HashElement));
    newEntry->key= (char *)malloc(20*sizeof(char));
    strcpy(newEntry->key, key);
    newEntry->value = value;
    return newEntry;
}

void insert(HashTable *t, char *key, Link* value)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL && (strcmp(t->table[hashedkey]->key, key) != 0))
    {
        hashedkey = (hashedkey+1)%SIZE;
    }
    
    t->table[hashedkey] = (HashElement *)malloc(sizeof(HashElement));
    t->table[hashedkey] = newHashElement(key, value);
}   


void delete(HashTable *t, char *key)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL)
    {
        if(strcmp(t->table[hashedkey]->key, key) == 0) break;
        hashedkey = (hashedkey+1)%SIZE;
    }
    if(t->table[hashedkey]==NULL)
    {
        printf("Nothing found for key %s\n", key);
        return;
    }
    else t->table[hashedkey]=NULL;
}  

Link* search(HashTable *t, char *key)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL && (strcmp(t->table[hashedkey]->key, key) != 0))
    {
        hashedkey = (hashedkey+1)%SIZE;
    }

    if(t->table[hashedkey]==NULL)
    {
        printf("Nothing found for key %s\n", key);
        return NULL;
    }
    
    return t->table[hashedkey]->value; //returns linked list head
}


/*Priority Queue methods-----------------*/


void priority_insert(pQueue **head, Vertex* node)
{
    if(*head!=NULL)
    {
        if((*head)->data==NULL && node!=NULL)
        {

            (*head)->data = node;
            return;
        }

    }
    pQueue *newnode = (pQueue *)malloc(sizeof(pQueue));
    newnode->data = node;
    newnode->next = *head;
    *head = newnode;
}

Vertex *extract_min(pQueue **head)
{
    int min = (*head)->data->key;
    pQueue *temp = *head;

    if(*head==NULL) 
    {
        printf("pQueue empty");
        return NULL;
    }
    if((*head)->next==NULL)
    {
        (*head)=NULL;
        return temp->data;
    }
    // finding the minimum key
    while((*head)!=NULL)
    {
        if(min > ((*head)->data->key))
            min=(*head)->data->key;
        *head = (*head)->next;    
    }    
    *head = temp;
    
    // extracting the node with min key
    
    Vertex *minNode;
    //if head has the min key, return it
    if((*head)->data->key == min)
    {
        minNode = (*head)->data;
        (*head)=(*head)->next;
        return minNode;
    }

    while((*head)->next != NULL)
    {
        if((*head)->next->data->key == min)
        {
            minNode = (*head)->next->data;
            pQueue *next = (*head)->next->next;
            free((*head)->next);
            (*head)->next = next;
            (*head) = temp;
            return minNode;
        }
        (*head) = (*head)->next;
    }
    (*head) = temp;
    printf("You messed up somewhere\n");
    exit(0);    
}

bool is_in(pQueue *head, Vertex *node)
{
    pQueue *temp = head;
    bool res=false;
    while(head!=NULL)
    {
        if(head->data == node)
        {
            res = true;
            break;
        }
        head = head->next;
    }
    head = temp;
    return res;
}
/*-----------------------------------------------*/

/*Linked list methods ---------------------------*/


void link_insert(Link **head, Vertex *node, int weight)
{
    if(*head!=NULL)
    {
        //to debug
        if((*head)->data == NULL)
        {
            (*head)->data = node;
            (*head)->weight = weight; 
            return;
        }
    }
    Link *newnode   =  (Link *)malloc(sizeof(Link));
    newnode->data   = node;
    newnode->weight = weight;
    newnode->next   = *head;
    *head            = newnode;
}

/*-----------------------------------------------*/


/* How to use

Let's find the MST of the following graph:
  
    
             1
        A --------- B\
        | \            \2
        |   \           \
    10  |     \  3        E
        |       \       /  
        |         \   / 15
        C-----------D/
            4

Adjacency list with distance for the following graph:

A: [B 1], [C 10], [D 3]
B: [A 1], [E 2]
C: [A 10], [D 4]
D: [C 4], [E 15], [A 3]
E: [B 2], [D 15]  

OUTPUT
---------------------------------------------------------------------

Enter the number of vertices: 5
Enter the name of the vertex #1: A
Enter the name of the vertex #2: B
Enter the name of the vertex #3: C
Enter the name of the vertex #4: D
Enter the name of the vertex #5: E
Enter the name of starting vertex: A
Enter the number of vertices adjacent to vertex A: 3
Enter the adjacent vertices and their distance:
Enter edge 1/3 and distance: B 1
Enter edge 2/3 and distance: C 10
Enter edge 3/3 and distance: D 3
Enter the number of vertices adjacent to vertex B: 2
Enter the adjacent vertices and their distance:
Enter edge 1/2 and distance: A 1
Enter edge 2/2 and distance: E 2
Enter the number of vertices adjacent to vertex C: 2
Enter the adjacent vertices and their distance:
Enter edge 1/2 and distance: A 10
Enter edge 2/2 and distance: D 4
Enter the number of vertices adjacent to vertex D: 3
Enter the adjacent vertices and their distance:
Enter edge 1/3 and distance: C 4
Enter edge 2/3 and distance: E 15
Enter edge 3/3 and distance: A 3
Enter the number of vertices adjacent to vertex E: 2
Enter the adjacent vertices and their distance:
Enter edge 1/2 and distance: B 2
Enter edge 2/2 and distance: D 15

Graph connections:
-------------------
B -- A
C -- D
D -- A
E -- B

-------------------
MST weight = 10

*/