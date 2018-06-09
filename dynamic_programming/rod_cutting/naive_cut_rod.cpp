#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <typename T> T cut_rod(std::vector<T> p, int n)
{
	/**
            cut_rod(p, n);
            Calculates the maximum revenue possible by 
            cutting a rod of length 'n' with profits for 
            different cuts is in the array 'p'

            @param p: an array of prices.
            @param n: size of the rod 
            @return q: the max revenue possible (an optimal value)    
    */

	if (n == 0)
		return (T)0;
	T q = std::numeric_limits<T>::min();
	for (int i = 0; i < n; i++) {
		q = max(q, p[i] + cut_rod(p, n-i-1));
	}
	return q;
}


int main(int argc, char const *argv[])
{
	std::vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	cout << "Max profit: $" << cut_rod(v, 4) << endl;
}