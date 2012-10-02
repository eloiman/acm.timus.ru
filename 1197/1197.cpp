#include <stdio.h>

int p[8][8]={2,3,4,4,4,4,3,2,
             3,4,6,6,6,6,4,3,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             3,4,6,6,6,6,4,3,
             2,3,4,4,4,4,3,2};

int main(void)
{
	int N = 0;
	char pos[4];
	int posx = 0;
	int posy = 0;
	int moves = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", pos);
		posx = pos[0] - 'a';
		posy = pos[1] - '1';
		printf("%d\n", p[posx][posy]);
	}

	return 0;
}

