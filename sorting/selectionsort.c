/**
	Implementation of selection sort
	@author: Akshay
*/

#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void selectionsort(int *array, size_t n);
int  min(int *array, int start, int end);
void swap(int *array, int i, int j);

int main(int argc, char *argv[])
{
	int arr[] = {6, 2, 7, 8, 9, 1};
	selectionsort(arr, SIZE(arr));
	for(int i = 0, n = SIZE(arr); i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

/* min: returns the index of min of the subarray array[start .... end] */
int min(int *array, int start, int end) {
	int smallest = array[start], pos_smallest = start;
	for (int i = start; i <= end; i++) 
		if (array[i] < smallest) 
			smallest = array[i], pos_smallest = i;
	return pos_smallest;	
}


/* swap: swaps the element at position i and j in the array */
void swap(int *array, int i, int j) {	
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/* selectionsort: sort an array in ascending order */
void selectionsort(int *array, size_t n) {	
	for (int i = 0; i < n; i++) {	
		int smallest_pos = min(array, i, n-1);						

		/* place the smallest element in start 
		   if its already not there */
		if (smallest_pos != i) 	
			swap(array, smallest_pos, i);		
	}
}