/**
	Implementation of insertion sort
	@author: Akshay
*/

#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void insertionsort(int *array, size_t n);

int main(int argc, char *argv[])
{
	int arr[] = {6, 2, 7, 8, 9, 1};
	insertionsort(arr, SIZE(arr));
	for(int i = 0, n = SIZE(arr); i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

/* insertionsort:  sorts the array in ascending order */
void insertionsort(int *array, size_t n) {
	for(int i = 1; i < n; i++) {
		int key = array[i],
		      j = i-1;

		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	} 
}