/**
	Implementation of quicksort
	@author: Akshay
*/

#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void swap(int *array, int i, int j);
void quicksort(int *array, int p, int r);
int partition(int *array, int p, int r);

int main(int argc, char *argv[])
{
	int arr[] = {6, 2, 7, 8, 9, 1};
	quicksort(arr, 0, SIZE(arr)-1);
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

/* quicksort: sorts an array in O(nlogn) in average case */
void quicksort(int *array, int p, int r) {
	if(p<r) {
		int q = partition(array, p, r);
		quicksort(array, p, q-1);
		quicksort(array, q+1, r);
	}
}

/* parition: paritions the array setting last element as pivot */
int partition(int *array, int p, int r) {
	int pivot = array[r];
	int j = p-1;
	for (int i = p; i <= r; i++)
		if(array[i] < pivot) {
			j++;
			swap(array, i, j);
		}
	swap(array, r, j+1);
	return j+1;
}