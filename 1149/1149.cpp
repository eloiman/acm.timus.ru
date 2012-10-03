#include <stdio.h>


void print_an(int n)
{
	int i = 0;

	for (i = 1; i <= n; i++) {
		printf("sin(%d", i);
		if (i != n) {
			printf("%c", (i & 1)? '-' : '+');
		}
	}

	for (i = 1; i <= n; i++) {
		printf(")");
	}
}

void print_sn(int n)
{
	int i = 0;

	for (i = 1; i < n; i++) {
		printf("(");
	}

	for (i = 1; i <= n; i++) {
		print_an(i);
		printf("+%d", n - i + 1);
		if (i != n) {
			printf(")");
		}
	}
}

int main(void)
{
	int N = 0;
	scanf ("%d", &N);

	print_sn(N);

	return 0;
}

