/*Kruskals Algo*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct set *container;
	char name;
	struct node *next;
};

struct set
{
	struct node *head;
	struct node *tail;	
};

struct edge
{
	struct set* pair[2];
	int weight;
};


typedef struct node Node;
typedef struct set Set;
typedef struct node Vertex;
typedef struct edge Edge;

Vertex *MakeNode(char);
Set *MakeSet(Vertex *node);
Set *Find(Vertex *node);
Set *Union(Set *x, Set *y);
void Display(Set *x);

int main()
{
	Set* a = MakeSet(MakeNode('a'));
	Set* b = MakeSet(MakeNode('b'));
	Set* c = MakeSet(MakeNode('c'));
	Set* d = MakeSet(MakeNode('d'));
	Set* e = MakeSet(MakeNode('e'));

	Set* GV[] = {a,b,c,d,e};
	Edge GE[] = { {{a,b} ,1}, {{b,e}, 2}, {{a,d}, 3}, {{c,d}, 4}, {{a,c}, 10},  {{e,d}, 15}}; 
	Edge A[4]; 
	int edgeTop=0, weight=0;
	Set* newset[6];


	printf("Graph: \n");
	for(int i=0, n=sizeof(GE)/sizeof(GE[0]); i<n; i++)
	{
		if(Find(GE[i].pair[0]->head) != Find(GE[i].pair[1]->head))
		{
			newset[0] = Union(Find(GE[i].pair[0]->head), Find(GE[i].pair[1]->head));
			printf("iteration #%d: ", edgeTop+1);
			Display(newset[0]);
			A[edgeTop++] = GE[i];
		}
	}

	printf("\nEdges added=\n");
	for(int i=0, n=edgeTop; i<n; i++)
	{
		weight += A[i].weight;
		printf("%c %c : ", A[i].pair[0]->head->name, A[i].pair[1]->head->name);
		printf("%d\n", A[i].weight);
	}

	printf("Total weight of MST = %d\n", weight );




}

Vertex *MakeNode(char name)
{
	Node *newnode = (Node *)malloc(sizeof(Node));

	/*making the node for the vertex */
	newnode->name = name;
	newnode->container = NULL;
	newnode->next=NULL;
	return newnode;
}

Set *MakeSet(Vertex *node)
{
	/* Allocating memory*/
	Set *disjointSet = (Set *)malloc(sizeof(Set));	
	node->container = disjointSet;
	/*assigning node to the container set*/
	disjointSet->head = node;
	disjointSet->tail = node;

	return disjointSet;
}

void Display(Set *x)
{
	Node *temp = x->head;
	while(x->head!=NULL)
	{

		printf("%c ", x->head->name);
		x->head = x->head->next;
	}
	printf("\n");
	x->head = temp;
}

Set *Find(Vertex *node)
{
	return node->container;
}

Set *Union(Set *s1, Set *s2)
{
	/* allocating memory for the new set */
	Set *newSet = (Set *)malloc(sizeof(Set));

	newSet->head = s1->head;	// setting head to the head of first set
	newSet->tail = s2->tail;	// setting tail to the tail of second set

	/* making container pointer of each node of first set point to the new set */
	Node *temp = s1->head;
	while(s1->head!=NULL)
	{
		s1->head->container = newSet;
		s1->head = s1->head->next;
	}	
	s1->head=temp;

	/* making container pointer of each node of second set point to the new set */
	temp = s2->head;
	while(s2->head!=NULL)
	{
		s2->head->container = newSet;
		s2->head = s2->head->next;
	}
	s2->head = temp;

	/* joining the first and second set */
	s1->tail->next = s2->head;

	/* returning the new union set */
	return newSet;
}
