// proj2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template  <typename whatever> void sort(whatever *, int ,  bool (*cmp)(whatever, whatever, const string), const string order="ascending");
template <typename whatever> void swap(whatever *, whatever *);
template <typename whatever> bool cmp(whatever , whatever , const string);

int main(int argc, char* argv[])
{
	string s[] = {"aksha", "aa", "sad"};
	sort(s, 3, cmp);
	for(int i=0; i<3; i++)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}

template  <typename whatever> void sort(whatever *a, int n,  bool (*cmp)(whatever, whatever, const string), const string order)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
			if(cmp(a[j], a[j+1], order))
				swap(a+j, a+j+1);

}

template <typename whatever> void swap(whatever *a, whatever *b){
	whatever temp = *a;
	*a = *b;
	*b = temp;
}

template <typename whatever> bool cmp(whatever a, whatever b, const string order){
	if(order== "ascending")
		return a>b;
	return a<b;
}
