#include <stdio.h>

int main(void)
{
int A, B;

scanf("%d", &A);
scanf("%d", &B);

printf("%s", ((0 == (B & 1)) && (A & 1) ) ? "no" : "yes");

return 0;
}