#include <stdio.h>
#include <math.h>

int N = 0;
double R = 0.;
double nails[100][2] = {0};

double calc_lace(void)
{
    const double PI = acos(-1.);

    double len = 0.;
    double x = 0.;
    double y = 0.;

    if (N > 1) {
        for (int i = 1; i < N; i++) {        
            x = nails[i][0] - nails[i - 1][0];
            y = nails[i][1] - nails[i - 1][1];
            len += sqrt(x*x + y*y);
        }
        
        x = nails[0][0] - nails[N - 1][0];
        y = nails[0][1] - nails[N - 1][1];
        len += sqrt(x*x + y*y);
    }

    len += 2. * PI * R;

    return len;
}

int main(void)
{
    scanf("%d", &N);
    scanf("%lf", &R);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &nails[i][0]);
        scanf("%lf", &nails[i][1]);
    }

    printf("%.2f", calc_lace());

    return 0;
}
