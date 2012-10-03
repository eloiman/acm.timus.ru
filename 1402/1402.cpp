#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

#define BIGN_SZ     (100)

typedef long long llong;
typedef unsigned long long ullong;
typedef struct {
    char * arr;
    int sz;
} bign;

bign bign_alloc(int sz = BIGN_SZ)
{
    bign n;
    n.arr = static_cast<char*>(calloc(sz, 1));
    n.sz = sz;

    return n;
}

void bign_free(bign n)
{
    free(n.arr);
}

void bign_assign(bign n, ullong val)
{
    int i;
    int r;
    int k = 0;
   
    memset(n.arr, 0, n.sz);
 
    do {
        r = val % 10;
        i = val / 10;
        val = i;

        n.arr[k++] = r;
    } while (i);
}

bign bign_dup(bign n)
{
    bign m = bign_alloc(n.sz);
    
    memcpy(m.arr, n.arr, n.sz);

    return m;
}


bign operator +(bign n, bign m)
{
    bign summ = bign_alloc(n.sz);
    int tmp;
    int sz = n.sz;

    for (int i = 0; i < sz; i++) {
        tmp = n.arr[i] + m.arr[i];
        summ.arr[i] += tmp;
        if (summ.arr[i] > 9 && i != (sz - 1)) {
            summ.arr[i] -= 10;
            summ.arr[i + 1] += 1;
        }
    }

    return summ;
}

bign operator *(bign n, bign m)
{
    std::vector<bign> muls;
    std::vector<bign>::iterator muls_iter;
    bign mul = bign_alloc(n.sz);
    bign mul0;
    int tmp;
    int ii;
    int rr;
    int kk = 0;
    int pos = 0;
    int tup = 0;
     
    for (int i = 0; i < m.sz; i++) {
        bign t = bign_alloc();
        tup = 0;
        for (int j = 0; j < n.sz; j++) {
            tmp = m.arr[i] * n.arr[j];
            if (tmp) {
                kk = i + j;
                do {
                    rr = tmp % 10;
                    ii = tmp / 10;
                    tmp = ii;
                    t.arr[kk] += rr;
                    if (t.arr[kk] > 9) {
                        t.arr[kk] -= 10;
                        t.arr[kk + 1] += 1;
                    }
                    kk++;
                } while (ii);
                tup = 1;
            }
        }
        if (tup) {
            muls.push_back(t);
        } else {
            bign_free(t);
        }
    }

    mul0 = mul;
    for (muls_iter = muls.begin(); muls_iter != muls.end(); muls_iter++) {
        bign t = *muls_iter;
        mul = mul0 + t;
        bign_free(mul0);
        mul0 = mul;
        bign_free(t);
    }

    return mul;
}

void bign_print(bign n)
{
    int a = 0;

    for (int i = n.sz - 1; i >= 0; i--) {
        if (n.arr[i] || a) {
            printf("%d", n.arr[i]);
            a = 1;
        }
    }

    if (!a) {
        printf("0");
    }
}

bign calc_a_n_m(int n, int m)
{
    int en = n - m + 1;
    int ni = n;
    bign res = bign_alloc();
    bign res0;
    bign tmp = bign_alloc();

    bign_assign(res, n);

    res0 = res;
    do {
        ni -= 1;
        bign_assign(tmp, ni);
        res = res0 * tmp;
        bign_free(res0);
        res0 = res;        
    } while (ni != en);

    return res;
}

bign resolve(int n)
{
    bign res = bign_alloc();
    bign res0;
    bign anm;

    bign_assign(res, 0);

    if (n == 1) {
        return res;
    }

    res0 = res;
    for (int m = 2; m <= n; m++) {
        anm = calc_a_n_m(n, m);
        res = res0 + anm;
        bign_free(res0);
        bign_free(anm);
        res0 = res;
    }

    return res;
}

int main(void)
{
    int N = 0;
    bign res;

    scanf("%d", &N);
    
    res = resolve(N);
    
    bign_print(res);

    bign_free(res);

    return 0;
}
