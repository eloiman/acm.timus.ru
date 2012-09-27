#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef long long llong;

char * alloc_bign(int sz)
{
    return (char *) calloc(sz, 1);
}

void free_bign(char *bign)
{
    free(bign);
}

void assign_bign(char *bign, int sz, llong n)
{
    int intgr;
    int rem;
    int i = 0;
    
    do {
        rem = n % 10;
        intgr = n / 10;
        n = intgr;

        bign[i++] = rem;
    } while (intgr);
}

char * copy_bign(char *bign, int sz)
{
    char *n = alloc_bign(sz);
    
    memcpy(n, bign, sz);

    return n;
}


char * summ_bign(char *a, char *b, int sz)
{
    char *summ = alloc_bign(sz);
    int tmp;

    for (int i = 0; i < sz; i++) {
        tmp = a[i] + b[i];
        summ[i] += (tmp % 10);
        if (tmp > 9 && i != (sz - 1)) {
            summ[i + 1] += 1;
        }
    }

    return summ;
}

char *mul_bign(char *a, int sz, int n)
{
    char * summ_prev = copy_bign(a, sz);
    char * summ = NULL;
    char *b = copy_bign(a, sz);
    int i = 1;

    do {
        summ = summ_bign(summ_prev, b, sz);
        free_bign(summ_prev);
        summ_prev = summ;
    } while(++i < n);
   
    return summ;
}

void print_bign(char *bign, int sz)
{
    int a = 0;

    for (int i = sz - 1; i >= 0; i--) {
        if (bign[i] || a) {
            printf("%d", bign[i]);
            a = 1;
        }
    }
}

double calc_a_n_m(int n, int m)
{
    int en = n - m + 1;
    int ni = n;
    double res = (double) n;

    do {
        ni -= 1;
        res *= double(ni);
    } while (ni != en);

    return res;
}

double resolve(int n)
{
    double res = 0.;

    if (n == 1) {
        return 0.;
    }

    for (int m = 2; m <= n; m++) {
        res += calc_a_n_m(n, m);
    }

    return res;
}

void out_double(double d)
{
    double fraq;
    double integral;

    if (d < 10) {
        printf("%d", int(d + 0.5));
        return;
    }
        
    fraq = modf(d / 10., &integral);
    out_double(integral);

    printf("%d", int((fraq + 0.5) * 10.));
}

int main(void)
{
    int N = 0;
    double res = 0.;
    double integral;

    //scanf("%d", &N);
    
    char *a = alloc_bign(100);
    assign_bign(a, 100, 21000);
    char *c0 = mul_bign(a, 100, 21001);
    char *c1 = mul_bign(c0, 100, 21000);
    char *c2 = mul_bign(c1, 100, 21000);
    char *c3 = mul_bign(c2, 100, 21000);
    
    print_bign(c3, 100);

    //res = resolve(N);

    //modf(res, &integral);
    
    //out_double(integral);

    return 0;
}
