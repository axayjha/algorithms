/**
	Implemetation of heap sort
	@author Akshay
*/

#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void heapsort(int *array, size_t n);
void max_heapify(int *array, int i, int n);
void build_max_heap(int *array, int n);
void swap(int *array, int i, int j);

int main(int argc, char *argv[])
{
	int arr[] = {6, 2, 7, 8, 9, 1};
	heapsort(arr, SIZE(arr));
	for(int i = 0, n = SIZE(arr); i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

/* heapsort: sorts an array in ascending order in O(nlogn) */
void heapsort(int *array, size_t n) {
	build_max_heap(array, n);
	for(int i = n-1; i>=0; i--){
		swap(array, i, 0);
		max_heapify(array, 0, i);	
	}
}

/* build_max_heap: modifies an array to represent a max heap */
void build_max_heap(int *array, int n) {
	for (int i = n/2 - 1; i >= 0; i--)
		max_heapify(array, i, n);
}

/* max_heapify: restores max heap property of 
a heap's array representation */
void max_heapify(int *array, int i, int n) {
	int largest = i,
		l = 2*i + 1,
		r = 2*i + 2;

	if(l < n && array[l] > array[largest])
		largest = l;
	if(r < n && array[r] > array[largest])
		largest	= r;

	if(i != largest) {
		swap(array, i, largest);
		max_heapify(array, largest, n);
	}
}

/* swap: swaps the element at position i and j in the array */
void swap(int *array, int i, int j) {	
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}