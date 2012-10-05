#include <stdio.h>

unsigned long calc_fact(int N, int K)
{   
    unsigned long fact = 1;
    unsigned long rem = N % K;
    unsigned long end = (rem ? rem : K);
    unsigned long kk = 0;
    unsigned long v = 0;

    do {
        v = (N - K * kk);
        fact *= v;
        kk++;
    } while (v != end);

    return fact;
}

int main(void)
{
    int N = 0;
    char kstr[21];
    int K = 0;
    int i = 0;
    
    scanf("%d", &N);
    scanf("%s", (char *) kstr);
       
    while (kstr[i] == (char ) '!') {
        K++;
        i++;
    }

    printf("%lu", calc_fact(N, K));

    return 0;
}
