#include <stdio.h>

unsigned long long MaxNum = 0;
unsigned long long Nums[15001] = {0};

unsigned long long find_num(int k)
{
    unsigned int ok = 0;
    unsigned long long num = Nums[MaxNum];
    
    if (k <= MaxNum) {
        return Nums[k];
    }

    for (int i = MaxNum + 1; i <= k; i++) {
        num = Nums[i - 1] + 1;
        do {
            ok = 1;        
            for (int j = 1; j < i && ok; j++) {
                if (0 == num % Nums[j]) {
                    ok = 0;
                }
            }
            if (!ok) {
                num += ((num & 1) ? 2 : 1);
            }
        } while (!ok);
        
        Nums[i] = num;
        MaxNum++;
    }

    return num;
}

int main(void)
{
    unsigned long long N = 0;
    unsigned long long num = 0;
    int k = 0;

    Nums[1] = 2;
    Nums[2] = 3;
    Nums[3] = 5;
    Nums[4] = 7;
    Nums[5] = 11;
    MaxNum = 5;

    scanf("%llu", &N);

    for (unsigned long long i = 0; i < N; i++) {
        scanf("%d", &k);
        num = find_num(k);
        printf("%llu\n", num);
    }

}
