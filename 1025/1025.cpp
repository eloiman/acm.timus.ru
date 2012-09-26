#include <stdio.h>

#define lfmt	"%ld"
#define ulfmt	"%lu"

#define llfmt	"%lld"
#define ullfmt	"%llu"

typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

void sort_weights(ulong *w, int n)
{   
    int mid = 0;
    ulong *w1 = NULL;
    ulong *w2 = NULL;
    int i1 = 0;
    int i2 = 0;
    ulong wmid = 0;
    int i = 0;
    int j = 0;
    ulong tmp;
	ulong *pout = NULL;
       
    if (n <= 1) return;

    if (n <= 2 && w[0] > w[n - 1]) {
        tmp = w[0];
        w[0] = w[1];
        w[1] = tmp;
    } else {
        mid = n / 2;
        wmid = w[mid];
        w1 = new ulong[n];
        w2 = new ulong[n];
        i1 = i2 = 0;
        for (i = 0; i < n; i += 1) {
			if (i != mid) {
				if (w[i] < wmid) { 
					w1[i1++] = w[i];
				} else {
					w2[i2++] = w[i];
				}
			}
        }

        sort_weights(w1, i1);
        sort_weights(w2, i2);

		pout = w1;
		j = 0;
        for (i = 0; i < n; i += 1) {
			if (i == i1) {
				w[i] = wmid;
				pout = w2;
				j = 0;
			} else {
				w[i] = pout[j++];
			}
        }

        delete [] w1;
        delete [] w2;
    }
}

int main(void)
{
	int N = 0;
	ulong w[200];
	ulong s = 0;

	scanf("%d", &N);
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &w[i]);
    }

	sort_weights(w, N);

	for (int i = 0; i < ((N / 2) + 1); i++) {
		s += w[i] / 2 + 1;
	}

	printf(lfmt, s);

    return 0;
}
