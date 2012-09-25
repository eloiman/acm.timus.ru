#include <math.h>
#include <stdio.h>

int main(void)
{
    long sz = 256 * 1024;
    double *buff;
    double *ptr; 

    buff = new double[sz];
    ptr = buff;
 
    while(EOF != scanf("%lf", ptr)) {
        ptr++;
    }

    ptr--;

    while(ptr >= buff ) {
        printf("%.4lf\n", sqrt(*ptr--));
    }

    return 0;
}

