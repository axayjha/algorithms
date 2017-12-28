/*
	Generic randomized quicksort
	
	@author Akshay Anand
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>

#define SIZE(array) sizeof(array)/sizeof(array[0])
using namespace std;

enum { 
	ASCENDING = 0xbabe, 
	DESCENDING = 0xface 
};
typedef uint64_t sorting;

template <typename whatever> 
void quicksort(whatever *, size_t ,
					bool (*cmp)(whatever, whatever, sorting),
					sorting order = ASCENDING);

template <typename whatever> 
void swap(whatever *, whatever *);

template <typename whatever> 
bool cmp(whatever , whatever , sorting);

template <typename whatever> 
void print(whatever *, int );


int main(int argc, char* argv[])
{	
	int a[]={1,3,45,2,6,2};
	quicksort(a, SIZE(a), cmp);
	print(a, SIZE(a));
	return 0;
}

template <typename whatever> 
void quicksort(whatever *array, size_t n, 
		bool (*cmp)(whatever value1, whatever value2, sorting order), 
		sorting order){
	/**
	    Sorts an array using quicksort algorithm

	    @param array: the reference to array to sort
	    @param n: size of the array
	    @param cmp: the comparision function to compare elements
		@param order: the order in which to sort the array

	    @return nothing
	*/

	if (n <= 1) return;
	int last = 0;

	swap(&array[0], &array[rand()%n]);
	for(int i=0; i<n; i++)
		if(cmp(array[0] , array[i], order))
			swap(&array[++last], &array[i]);
	swap(&array[0], &array[last]);
	
	quicksort(array, last, cmp, order);
	quicksort(array+last+1, n-last-1, cmp, order);	
}

template <typename whatever> 
void swap(whatever *value1, whatever *value2) {
	/**
	    Swaps values of two variables

	    @param value1, value2: the variables to swap

	    @return nothing
	*/

	whatever temp = *value1;
	*value1 = *value2;
	*value2 = temp;
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