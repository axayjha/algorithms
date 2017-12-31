/**
	Implementation of randomized quicksort
	@author: Akshay
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void swap(int *array, int i, int j);
void rand_quicksort(int *array, size_t n);

int main(int argc, char *argv[])
{
	int arr[] = {6, 2, 7, 8, 9, 1};
	rand_quicksort(arr, SIZE(arr));
	for(int i = 0, n = SIZE(arr); i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

/* swap: swaps the element at position i and j in the array */
void swap(int *array, int i, int j) {	
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/* rand_quicksort: sorts an array in O(nlogn) in average case */
void rand_quicksort(int *array, size_t n) {
	if (n <= 1) return;
	
	int last = 0;	

	swap(array, 0, rand()%n);		/* setting random pivot at 0th position */
	for (int i = 0; i < n; i++)
		if (array[i] < array[0])
			swap(array, ++last, i);
	swap(array, last, 0);
	
	rand_quicksort(array, last);
	rand_quicksort(array+last+1, n-last-1);
}

