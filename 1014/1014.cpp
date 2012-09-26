#include <stdio.h>

#define lfmt	"%ld"
#define ulfmt	"%lu"

#define llfmt	"%lld"
#define ullfmt	"%llu"

typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

llong resolve(int N)
{
	llong Q = 0;
	llong down_q = 0;
	int is_div = 0;

	if (N < 10) {
		return N;
	}

	for (int i = 9; i > 1; i--) {
		if (0 == N % i) {
			down_q = resolve(N / i);
			if (down_q > 0) {
				is_div = 1;
				Q = down_q * 10 + i;
				break;
			}			
		}
	}

	return (is_div) ? Q : -1;
}

int main(void)
{
    int N = 0;
	llong Q = 0;

    scanf("%d", &N);

	if (N == 0) {
		Q = 10;
	} else {
		Q = resolve(N);
	}

	printf(llfmt, Q);

    return 0;
}
