#include <stdio.h>
#include <stdint.h>

#define B2(n) n, n+1, n+1, n+2
#define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

uint8_t lookup[256] = { COUNT_BITS };  /* lookup table */

uint8_t _numOfSetBits(int n)  /* takes linear time */
{
	uint8_t count = 0;
	while(n!=0)
		count++, n = n & (n-1);
	return count;
}

uint8_t numOfSetBits(int n) 	/* takes constant time */
{
	uint8_t count = lookup[n & 0xff] +
					lookup[(n>>8) & 0xff] +
					lookup[(n>>16) & 0xff] +
					lookup[(n>>24) & 0xff];
	return count;				 
}

int main()
{
	printf("%d\n", numOfSetBits(-1) );
	printf("%d\n", _numOfSetBits(13) );
}
