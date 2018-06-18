#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <typename T> T bottom_up_cut_rod(std::vector<T> p, int n)
{
	/**
            botton_up_cut_rod(p, n);
            Calculates the maximum revenue possible by 
            cutting a rod of length 'n' with profits for 
            different cuts is in the array 'p'

            @param p: an array of prices.
            @param n: size of the rod 
            @return r[n]: the max revenue possible (an optimal value)    
    */

	T q;
	std::vector<T> r(n+1);
	r[0] = 0;
	for (int j = 1; j <=n; ++j)
	{
		q = std::numeric_limits<T>::min();
		for (int i = 0; i < j; ++i)
			q = max(q, p[i] + r[j-i-1]);
		r[j] = q;
	}
	return r[n];

}

int main(int argc, char const *argv[])
{
	//std::vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	std::vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << "Max profit: $" << cut_rod(v, 4) << endl;
	cout << "Max profit: $" << bottom_up_cut_rod(v, 8) << endl;

}