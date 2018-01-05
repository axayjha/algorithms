#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

/*  binary_search: finds 'number' in 'array' in log(n) time 
	Assumed the array is sorted. 
	Returns -1 if not found
*/
int binary_search_rec(int *array, int start, int end, int number)
{	
	if (start <= end) {
		int mid = (start + end) / 2;
		if (array[mid] == number)
			return mid;
		else if (array[mid] < number)
			return binary_search_rec(array, mid+1, end, number);
		else
			return binary_search_rec(array, start, mid-1, number);
	} else 
		return -1;
}

int main()
{
	int array[] = {1, 5, 7, 12, 17, 19};
	int number = 0;
	printf("Position: %d\n", binary_search_rec(array, 0, SIZE(array), number));

}