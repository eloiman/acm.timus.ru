#include <stdio.h>

#define MAXN    (170000)

unsigned long long Nums[MAXN + 1] = {0};

void build_siege(void)
{
    long i = 0;
    long j = 0;
    long next_p = 0;

    for (i = 2; i < MAXN; i++) {
        for (j = i; j < MAXN; j++) {
            if (!Nums[j]) {
                next_p = j;
                break;
            }
        }

        for (j = next_p * 2; j < MAXN; j += next_p) {
            Nums[j] = 1;
        }
    }
}

unsigned long long find_num(int k)
{   
    unsigned long long num = 0;   
    unsigned long long i = 2;

    do {
        if (!Nums[i]) {
            k--;
            num = i;
        }
        i++;
    } while (k);

    return num;
}

int main(void)
{
    int N = 0;
    unsigned long long num = 0;
    int k = 0;

    build_siege();

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &k);
        num = find_num(k);
        printf("%llu\n", num);
    }

}
