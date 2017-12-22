#include <stdio.h>
#include <stdlib.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void swap(int *, int *);
void rand_quicksort(int *, int );

void quicksort(int *, int, int);   // alternate method
int partition(int *, int, int);

int main(int argc, char* argv[])
{
	int a[] = {9,8,1,6,1,2,3};
	rand_quicksort(a, SIZE(a));
	for(int i=0, n=SIZE(a); i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
void rand_quicksort(int a[], int n)
{
	int last=0;
	if(n<=1) return;

	swap(&a[0], &a[rand()%n]);
	for(int i=0; i<n; i++)
		if(a[i] < a[0])
			swap(&a[++last], &a[i]);
	swap(&a[0], &a[last]);

	rand_quicksort(a, last);
	rand_quicksort(a+last+1, n-last-1);
}

void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}



//---------------------------ALTERNATE METHOD---------------------------

void quicksort(int *a, int p, int r)
{
	if(p<r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}

int partition(int *a, int p, int r)
{
	int pivot = a[r];
	int i = p-1;
	for(int j=p; j<r; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[r], &a[i+1]);
	return i+1;
}
