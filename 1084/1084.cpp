#include <math.h>
#include <stdio.h>

int main(void)
{
	int garden1, rope1;
	double diag_half, answer, alpha, sector, tre, garden, rope;

	scanf("%d", &garden1);
	scanf("%d", &rope1);

	garden = (double) garden1;
	rope = (double) rope1;

	diag_half = 0.5 * sqrt(garden*garden + garden*garden);

	if(rope < garden / 2.)
	{
		printf("%.3f", (3.1415926*rope*rope));
	}		
	else if (rope >= diag_half)
	{
		printf("%.3f", (garden*garden));
	}
	else
	{
		alpha = acos(garden/(rope*2));
		sector = rope*rope*alpha;
		tre = (0.5*rope*rope*sin(2*alpha));
		answer = (3.1415926*rope*rope) - 4*(sector - tre);
		printf("%.3f", answer);
	}


	return 0;
}
