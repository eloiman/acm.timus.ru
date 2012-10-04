#include <stdio.h>

#define lfmt	"%ld"
#define ulfmt	"%lu"

#define llfmt	"%lld"
#define ullfmt	"%llu"

typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

int N;
int mtrx[2 * 100 * 100] = {0};

void printout(void)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d ", mtrx[i * N + j]);
		}
	}

	for (i = 0; i < 2 * N; i++) {
		for (j = 1 + i; j < N; j++) {
			printf("%d ", mtrx[(i + N) * N + j]);
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mtrx[(i + j) * N + j]);
		}
	}

	printout();

	return 0;
}