#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

/*  binary_search: finds 'number' in 'array' in log(n) time 
	Assumed the array is sorted. 
	Returns -1 if not found
*/
int binary_search(int *array, int n, int number)
{
	int low  = 0,
		high = n-1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (array[mid] == number)
			return mid;
		else if (array[mid] < number)
			low = mid + 1;
		else
			high = mid - 1;
	}	 
	return -1;
}

int main()
{
	int array[] = {1, 5, 7, 12, 17, 19};
	int number = 1;
	printf("Position: %d\n", binary_search(array, SIZE(array), number));

}