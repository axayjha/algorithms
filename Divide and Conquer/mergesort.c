/*
	Merge-sort implementation for integer arrays
	Akshay Anand
*/

#include <stdio.h>
#include <limits.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])


void mergesort(int *array, int low, int high);
void merge(int *array, int low, int mid, int high);

int main(int argc, char *argv[])
{
	int a[] = {1, 5, 3, 8, 4, 6, 2};
	mergesort(a, 0, (SIZE(a)-1));
	for(int i = 0; i < SIZE(a); i++)
		printf("%d ", a[i]);
	printf("\n");
}

void mergesort(int *array, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(array, low, mid);		/* sort left half */
		mergesort(array, mid+1, high);  /* sort right half */
		merge(array, low, mid, high);	/* merge sorted arrays */
	}
}

void merge(int *array, int low, int mid, int high) {
	int n1 = mid - low + 1;			/* size of the left half array */
	int n2 = high - mid;			/* size of the right half array */
	int left[n1+1], right[n2+1];	

	/* divide */
	for (int i = 0; i < n1; i++)
		left[i] = array[i + low];

	for (int j = 0; j < n2; j++)
		right[j] = array[mid + j + 1];

	left[n1] = right[n2] = INT_MAX;		/* setting sentinel */

	/* conquer and merge */
	for(int k = low, i = 0, j = 0; k <= high; k++) {	/* selecting smaller element of both half*/
		if (left[i] < right[j])
			array[k] = left[i++];
		else
			array[k] = right[j++];
	}

}