#include <iostream>
#include <limits>
#include <vector>

using namespace std;


template <typename T> T memoized_cut_rod_aux(std::vector<T> p, int n, std::vector<T> &r);

template <typename T> T memoized_cut_rod(std::vector<T> p, int n)
{
	/**
            memoized_cut_rod(p, n);
            Calculates the maximum revenue possible by 
            cutting a rod of length 'n' with profits for 
            different cuts is in the array 'p'

            @param p: an array of prices.
            @param n: size of the rod 
            @return memoized_cut_rod_aux(p, n-1, r)
            	: the max revenue possible (an optimal value)    
    */
	std::vector<T> r(n, std::numeric_limits<T>::min());
	return memoized_cut_rod_aux(p, n-1, r);
}

template <typename T> T memoized_cut_rod_aux(std::vector<T> p, int n, std::vector<T> &r)
{
	T q;
	if (r[n] >= 0) 
		return r[n];
	if (n == 0)
		q = 0;
	else {
		q = std::numeric_limits<T>::min();
		for (int i = 1; i <= n; ++i)
			q = max(q, p[i] + memoized_cut_rod_aux(p, n-i-1, r));
	}
	r[n] = q;
	return q;
}


int main(int argc, char const *argv[])
{
	//std::vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	std::vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << "Max profit: $" << cut_rod(v, 4) << endl;
	cout << "Max profit: $" << memoized_cut_rod(v, (int)8) << endl;
}