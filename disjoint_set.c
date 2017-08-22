#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct set *container;
	int data;
	struct node *next;
};

struct set
{
	struct node *head;
	struct node *tail;	
};

typedef struct node Node;
typedef struct set Set;

Set *MakeSet(int x);
Set *Find(Node *node);
Set *Union(Set *x, Set *y);
void Display(Set *x);

int main()
{
	Set *m = MakeSet(3);
	Set *n = MakeSet(4);
	Display(m);
	Display(n);
	Set *k = Union(m, n);
	Display(k);
	Display(Find(m->head));
	Display(Find(n->head));
}

Set *MakeSet(int x)
{
	/* Allocating memory*/
	Set *disjointSet = (Set *)malloc(sizeof(Set));
	Node *newnode = (Node *)malloc(sizeof(Node));

	/*making the node for the data */
	newnode->data = x;
	newnode->container = disjointSet;
	newnode->next=NULL;

	/*assigning node to the container set*/
	disjointSet->head = newnode;
	disjointSet->tail = newnode;

	return disjointSet;
}

void Display(Set *x)
{
	Node *temp = x->head;
	while(x->head!=NULL)
	{

		printf("%d ", x->head->data);
		x->head = x->head->next;
	}
	printf("\n");
	x->head = temp;
}

Set *Find(Node *node)
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