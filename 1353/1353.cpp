#include <stdio.h>

#define lfmt "%ld"
#define ulfmt "%lu"

#define llfmt "%lld"
#define ullfmt "%llu"

typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

llong mem_vf[81][10] = {0};

llong resolve(int S, int width)
{
    int i;
    int S1;
    llong VF = 0;
    llong subVF = 0;

    if (width > 0) {
        VF = mem_vf[S][width];
        if (0 == VF) {
            for (i = (S > 9) ? 9 : S; i >= 0; i--) {
                S1 = S - i;
                if (S1) {
                    subVF = resolve(S1, width - 1);
                } else {
                    subVF = 1;
                }
                VF = (mem_vf[S][width] += subVF);
            }
        }
    }

    return VF;
}

int main(void)
{
    int S = 0;
    llong VF = 0;

    scanf("%d", &S);

    if (S == 81) {
        VF = 1;
    } else if (S == 80) {
        VF = 9;
    } else {
        if (S > 40) {
            S = 81 - S;
        }
        VF = resolve(S, 9);    
        if (S == 1) {
            VF += 1;
       }
    }
    
    printf(llfmt, VF); 

    return 0;
}
