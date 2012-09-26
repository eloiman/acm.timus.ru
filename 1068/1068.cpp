#include <stdio.h>
#include <math.h>

#define lfmt	"%ld"
#define ulfmt	"%lu"

#define llfmt	"%lld"
#define ullfmt	"%llu"

typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

int main(void)
{
	int n = 0;
	long N = 0;
	long s = 0;

	scanf("%d" , &n);

	N = n;
	if (0 == N) {
		s = 1;
	} else if (N<0) {
		s = ((1 + abs(N)) * N) / 2 + 1;
	} else {
		s = ((1 + N) * N) / 2;
	}

	printf("%d", s);

	return 0;
}