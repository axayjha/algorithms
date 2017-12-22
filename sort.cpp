/*
	Generic randomized quicksort
	Akshay Anand
	29/11/17
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

using namespace std;

enum { ASCENDING = 0xbabe, DESCENDING = 0xface };
typedef uint64_t sorting;

template <typename whatever> void sort(whatever *, size_t ,
										 bool (*cmp)(whatever, whatever, sorting),
										 sorting order = ASCENDING);

template <typename whatever> void swap(whatever *, whatever *);
template <typename whatever> bool cmp(whatever , whatever , sorting);


int main(int argc, char* argv[])
{	
	int a[]={1,3,45,2,6,2};
	sort(a, SIZE(a), cmp, DESCENDING);
	for(int i=0; i<SIZE(a); i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

template <typename whatever> void sort(
		whatever *array, size_t n, 
		bool (*cmp)(whatever value1, whatever value2, sorting order), 
		sorting order){

	if(n<=1) return;
	int last = 0;

	swap(&array[0], &array[rand()%n]);
	for(int i=0; i<n; i++)
		if(cmp(array[0] , array[i], order))
			swap(&array[++last], &array[i]);
	swap(&array[0], &array[last]);
	
	sort(array, last, cmp, order);
	sort(array+last+1, n-last-1, cmp, order);	
}

template <typename whatever> void swap(
			whatever *value1, whatever *value2) {
	whatever temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

template <typename whatever> bool cmp(
			whatever value1, whatever value2, sorting order){
	if(order == ASCENDING)
		return value1 > value2;
	return value1 < value2;
}
