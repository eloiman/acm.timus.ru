#include <stdio.h>

int main(void)
{
	long k, n, t;
	long s;

	scanf("%ld", &k);
	scanf("%ld", &n);

	s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%ld", &t);
		s += t;
		s -= k;
		if (s < 0) {
			s = 0;
		}
	}

	printf("%ld", s);

	return 0;
}