#include <stdio.h>

typedef unsigned long ulong;

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
	ulong mask = 0;
	ulong end_mask = 0;
	ulong check_mask = 0;
	int pos = 0;
    ulong w[20];
	ulong s1 = 0;
	ulong s2 = 0;
	ulong diff_opt = 100000 * 20;
	ulong diff = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &w[i]);
    }

    sort_weights(w, N);

	end_mask = 1 << N;
	for (mask = 0; !(mask & end_mask); mask++) {
		check_mask = 1;
		s1 = s2 = 0;
		for (pos = 0; pos < N; pos++, check_mask <<= 1) {
			if (check_mask & mask) {
				s1 += w[pos];
			} else {
				s2 += w[pos];
			}			
		}

		diff = s1 - s2;
		diff = (diff > 0) ? diff : -diff;
		diff_opt = (diff < diff_opt) ? diff : diff_opt;
	}

	printf("%d", diff_opt);

    return 0;
}


