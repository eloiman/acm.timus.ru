#include <stdio.h>
#include <limits.h>

unsigned long A[100000UL] = {0};

unsigned long lookup_max(long n)
{
	unsigned long tmp;
	unsigned long max = 0;

	A[0] = 0;
	A[1] = 1;

	if (n < 2) return n;

	for (unsigned long i = 2; i <= n; i++) {
		tmp = i >> 1;
		if (i & 1) {
			A[i] = A[tmp] + A[tmp + 1];
		} else {
			A[i] = A[tmp];
		}

		if (A[i] > max) {
			max = A[i];
		}
	}

	return max;
}

int main(void)
{
	long N = 0;

	scanf("%d", &N);
	while (N) {
		unsigned long X = lookup_max(N);
		printf("%d\n", X);
		scanf("%d", &N);
	}

	return 0;
}

