#include <stdio.h>

int main(void)
{
	int N = 0;
	int M = 0;
	unsigned long res = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	res = N * (M+1);

	printf("%lu", res);

	return 0;
}
