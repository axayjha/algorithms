/*
	Generic merge-sort

	@author Akshay Anand
*/

#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <string>
#include <limits.h>

#define SIZE(array) sizeof(array)/sizeof(array[0])

enum { 
	ASCENDING  = 0xbabe, 
	DESCENDING = 0xface 
};

typedef uint64_t sorting;

template <typename whatever> 
void msort(whatever *, size_t, sorting order = ASCENDING);

template <typename whatever> 
void mergesort(whatever *, int, int, 
					bool (*cmp)(whatever, whatever, sorting),
					sorting order);

template <typename whatever> 
void merge(whatever *, int, int, int,
					bool (*cmp)(whatever value1, whatever value2, sorting order), 
					sorting order);

template <typename whatever> 
void print(whatever *, int );

template <typename whatever> 
bool cmp(whatever , whatever , sorting);


int main(int argc, char *argv[])
{
	double array_d[] = {1, 5, 3.2, 8.4, 4, 6, 3};
	msort(array_d, SIZE(array_d));
	print(array_d, SIZE(array_d));

	int array_i[] = {45, 536, 655, 1, -1};
	msort(array_i, SIZE(array_i));
	print(array_i, SIZE(array_i));	

	return 0;
}

template <typename whatever> 
void msort(whatever *array, size_t n, sorting order) {

	/**
	    Sorts an array using mergesort algorithm

	    @param array: the reference to array to sort
	    @param n: size of the array
		@param order: the order in which to sort the array

	    @return nothing
	*/

	if (n <= 1) return;
	mergesort(array, 0, n-1, cmp, order);
}

template <typename whatever> 
void mergesort(whatever *array, int low, int high,
		bool (*cmp)(whatever value1, whatever value2, sorting order), 
		sorting order) {
	/**
	    Sorts an array using mergesort algorithm

	    @param array: the reference to array to sort
	    @param low, high: decides the portion of array to sort
		@param cmp: the comparision function to compare elements
		@param order: the order in which to sort the array

	    @return nothing
	*/

	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(array, low, mid, cmp, order);		/* sort left half */
		mergesort(array, mid+1, high, cmp, order);	/* sort right half */
		merge(array, low, mid, high, cmp, order);				/* merge sorted arrays */
	}
}

template <typename whatever> 
void merge(whatever *array, int low, int mid, int high,
		bool (*cmp)(whatever value1, whatever value2, sorting order), 
		sorting order) {

	/**
	    Divides the array in two halves
	    sorts them and merges the sorted portions into 
	    the actual array

	    @param array: the reference to array to sort
	    @param low, high: decides the portion of array to sort
		@param mid: the mid position of the array
	    @return nothing
	*/

	int n1 = mid - low + 1;		/* size of the left half array */
	int n2 = high - mid;		/* size of the right half array */
	whatever left[n1+1], right[n2+1];

	/* divide */
	for (int i = 0; i < n1; i++)
		left[i] = array[low + i];

	for (int j = 0; j < n2; j++)
		right[j] = array[j + mid + 1];

	left[n1] = right[n2] = (whatever)INT_MAX; /* setting sentinel; be cautious */

	/* conquer and merge */
	for (int k = low, i = 0, j = 0; k <= high; k++)	/* selecting smaller element of both half*/
		if (cmp(right[j], left[i], order))
			array[k] = left[i++];
		else
			array[k] = right[j++];

}

template <typename whatever> 
void print(whatever *array, int n) {

	/**
	    Prints an array

	    @param array: the array to print
	    @param n: the size of the array
	    @return nothing
	*/

	for(int i = 0; i < n; i++)
		std::cout <<  array[i] << " ";
	std::cout << std::endl;
}

template <typename whatever> 
bool cmp(whatever value1, whatever value2, sorting order){

	/**
	    compares two objects

	    @param value1, value2: the objects to compare
	    @param order: the order in which to sort the array
	    @return the boolean value
	*/

	if(order == ASCENDING)
		return value1 > value2;
	return value1 < value2;
}