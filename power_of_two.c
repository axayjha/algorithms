#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool powerOfTwo(int n){ /* constant time */
	return ((n & (n-1)) == 0);
}


bool _powerOfTwo(uint32_t n) /* log linear time assuming pow is O(log(n)) */
{
	if(n<=2) return true;
	for(int i=0, x=n/2; i<=x; i++)
	{
		if(pow(2, i) == n)
			return true;
	}
	return false;
}

int main()
{
	printf("%d\n", _powerOfTwo(16));
	printf("%d\n", powerOfTwo(8));
}