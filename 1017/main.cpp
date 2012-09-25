#include <stdio.h>

#define NMAX    (501)

static int N = 0;
static unsigned long long S = 0;
static long long mtrx[NMAX][NMAX];

long long count(const int Y, const int cubes)
{
    int availCubes;
    int nexty;
    long long Slocal = 0;

    if (mtrx[Y][cubes] >= 0) {
        Slocal = mtrx[Y][cubes];
    } else {
        for (int y = Y; y < N; y++) {
            availCubes = cubes - y;
            if (0 != availCubes) {
                nexty = y + 1;

                if (availCubes >= nexty) {
                    Slocal += count(nexty, availCubes);
                } else {
                    if (Y > 1) {
                        Slocal++;
                    }
                    break;
                }
            } else {
                if (Y > 1) {
                    Slocal++;
                }
                break;
            }
        }

        mtrx[Y][cubes] = Slocal;
    }

    return Slocal;
}

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            mtrx[i][j] = -1;
        }   
    }
    
    S = count(1, N); 

#if (__GNUC__ || __GNUG__)
    printf("%llu", S);
#else
    printf("%I64u", S);
#endif

    return 0;
}
