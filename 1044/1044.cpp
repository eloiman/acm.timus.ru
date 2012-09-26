#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, sums[100], end, t, t2, cursum, total = 0;

	scanf("%d" , &N);

	if (N % 2) {
		printf("0");
		return 0;
	}

	for(t = 0 ; t <= 36 ; t++) {
		sums[t] = 0;
	}

	end = powl(10 , N / 2);
	for(t = 0 ; t < end ; t++) {
		cursum = 0;
		t2 = t;
		while(t2 > 0) {
			cursum += t2 % 10;
			t2 /= 10;
		}
		sums[cursum]++;
	}

	for(t = 0 ; t <= 36 ; t++) {
		total += sums[t] * sums[t];
	}

	printf("%d" , total);

	return 0;
}