/*  Implementation of DFS algorithm using adjacency list
    this code is unnecessarily huge due to the implementations of 
    linked list, hashtable and graph data structures.
    
    Not for faint-hearteds, for the code is dark and full of POINTERS!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 128
#define NIL -99999
#define INF 99999
#define MAX 20

struct link
{
    //linked list to create adjacency list to put as 'value' in hashtable
    struct vertex *data;
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
    char *name;
    char *colour;
    int distance, finish; 
    struct vertex *parent;
};

struct graph
{
    int n;
    struct vertex** V; //array of pointers to vertices
    struct hashTable *Adj;
};



typedef struct hashElement HashElement;
typedef struct hashTable HashTable;
typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct link Link; 
typedef struct link Queue;  

/*Hash table methods------------------*/
int hash(char *);
HashTable *newHashTable();
HashElement *newHashElement(char *key, Link* value);
void insert(HashTable *table, char *key, Link* value);
void delete(HashTable *table, char *key);
Link* search(HashTable *table, char *key);
/*------------------------------------*/

void link_insert(Link **head, Vertex *node); //inserts element into the adjacency list in hashtable

Vertex *newVertex(char *name); //initializes new vertex

void Enqueue(Queue **head, Vertex *node);
Vertex *Dequeue(Queue **head);

void DFS(Graph* G);
void DFS_visit(Graph *G, Vertex *u);

int main()
{
    // creating vertices
    Vertex *s = newVertex("s");
    Vertex *b = newVertex("b");
    Vertex *c = newVertex("c");
    Vertex *d = newVertex("d");
    Vertex *e = newVertex("e");
    Vertex *f = newVertex("f");
    Vertex *h = newVertex("h");


    s->distance = 0; //a is the start vertex
    strcpy(s->colour, "gray");


    Vertex* vertices[] = {s,b,c,d,e, f, h};
   
    // creating lists for adjacency list
    Link *S = (Link* )malloc(sizeof(Link));
    Link *B = (Link* )malloc(sizeof(Link));
    Link *C = (Link* )malloc(sizeof(Link));
    Link *D = (Link* )malloc(sizeof(Link)); 
    Link *E = (Link* )malloc(sizeof(Link));    
    Link *F = (Link* )malloc(sizeof(Link));
    Link *H = (Link* )malloc(sizeof(Link));

    link_insert(&S, b); link_insert(&S, c); 
    link_insert(&B, s); link_insert(&B, d);link_insert(&B, h);
    link_insert(&C, s); link_insert(&C, f);
    link_insert(&D, b); link_insert(&D, e);
    link_insert(&E, d);
    link_insert(&F, c);
    link_insert(&H, b);

    
    // creating hashtable
    HashTable* Adj =  newHashTable();
    insert(Adj, "s", S);
    insert(Adj, "b", B);
    insert(Adj, "c", C);
    insert(Adj, "d", D);
    insert(Adj, "e", E);
    insert(Adj, "f", F);
    insert(Adj, "h", H);
    



    Graph* G = (Graph *)malloc(sizeof(Graph));
    G->V = vertices;
    G->Adj = Adj;
    G->n = 7;

    DFS(G);

    printf("\nGraph Connections: \n");
    for(int i=0; i<G->n ; i++)
    {
        if(G->V[i]->parent!=NULL)
            printf("%s---%s\n", G->V[i]->name, G->V[i]->parent->name);  
    }
    
    

}


/*----------------------------------------------------------*/

void DFS(Graph *G)
{
    for(int i=0 ; i<G->n ; i++)
    {
        strcpy(G->V[i]->colour, "white");
        G->V[i]->parent = (Vertex *)malloc(sizeof(Vertex));
    }
    printf("DFS traversal:\n%s", G->V[0]->name);
    for(int i=0 ; i< G->n ; i++)
    {
        if(strcmp(G->V[i]->colour, "white")==0)
        {            
            DFS_visit(G, G->V[i]);
        }        
    }
    printf("\n");
}

void DFS_visit(Graph *G, Vertex *u)
{
    int time=0;
    time = time + 1;
    u->distance = time;
    strcpy(u->colour, "gray");

    Link* head = search(G->Adj, u->name);
    Link* temp = head;
    while(head!=NULL)
    {
        if(strcmp(head->data->colour, "white")==0 )
        {
            printf("-> ");
            head->data->parent = u;
            printf("%s", head->data->name);            
            DFS_visit(G, head->data);
            
        }
        head=head->next;
    }    
    
    head=temp;
    strcpy(u->colour, "black");
    time ++;
    u->finish= time;
}

Vertex *Dequeue(Queue **head)
{
    Link *temp = *head;
    Vertex *node = temp->data;  
    (*head)=(*head)->next;
    free(temp);
    temp=NULL;
    return node;
}


void Enqueue(Queue **head, Vertex *node)
{
    Link *temp = *head;
    if((*head)==NULL)
    {
        (*head) = (Link *)malloc(sizeof(Link));
        (*head)->data = node;
        (*head)->next=NULL;
        return;

    }
    while((*head)->next != NULL)
    {
        *head = (*head)->next;
    }

    if((*head)->data==NULL)
    {
        (*head)->data = node;
        (*head)->next = NULL;
        *head = temp;
        return;
    }

    (*head)->next = (Link *)malloc(sizeof(Link));
    (*head) = (*head)->next;
    (*head)->data = node;
    (*head)->next = NULL;
    *head = temp;
}



Vertex *newVertex(char *name)
{
    Vertex *newV = (Vertex *)malloc(sizeof(Vertex));
    newV->distance = NIL;
    newV->name = (char *)malloc(20*sizeof(char));
    newV->colour = (char *)malloc(20*sizeof(char));
    strcpy(newV->name, name);
    strcpy(newV->colour, "white");
    newV->parent = NULL;   //saddest line of code i've ever written
    return newV;
}

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


/*Linked list methods ---------------------------*/


void link_insert(Link **head, Vertex *node)
{
    if(*head!=NULL)
    {
        //to debug
        if((*head)->data == NULL)
        {
            (*head)->data = node;
            return;
        }
    }
    Link *newnode   =  (Link *)malloc(sizeof(Link));
    newnode->data   = node;
    newnode->next   = *head;
    *head            = newnode;
}

/*-----------------------------------------------*/