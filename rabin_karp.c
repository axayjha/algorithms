#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define D 256
#define Q 101

int rabin_karp_matcher(char T[], char P[], int d, int q)
{
	int n = strlen(T), m = strlen(P);
	int h = ((int)pow(d, m-1))%q;
	int p = 0, t = 0, s;

	for(int i=0; i<m; i++){
		p = (d*p + P[i])%q;
		t = (d*t + T[i])%q;
	}
	//printf("%d %d\n", p, t);
	for(s=0; s <= n-m; s++){
		//printf("%d %d\n", p, t);
		if(p == t){
			for(int i=0; i<m; i++){
				printf("%c %c\n", P[i], T[s+i] );
				if(P[i] == T[s+i]){
					if(i==(m-1)){
						return s;
					}
				}
				else break;	
			}

		}
		if( s < n-m ){
			t = (d*(t - T[s]*h) + T[s+m])%q;
			if (t<0) t+=q;
		}
		
	}

	return -1;

}


int main()
{
	char T[] = "mykjsakshay";
	char P[] = "kjsa";
	printf("%d\n", rabin_karp_matcher(T, P, D, Q));

}

