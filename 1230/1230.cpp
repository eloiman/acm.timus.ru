#include <stdio.h>

int main(void)
{
    //X='"';Y="'";D='X='+Y+X+Y+';Y='+X+Y+X+';';A="D='X='+Y+X+Y+';Y='+X+Y+X+';';A=;B=$(A,1,31);C=$(A,32,43);?D;?B;?X;?A;?X;?C";B=$(A,1,31);C=$(A,32,43);?D;?B;?X;?A;?X;?C
    printf("X='\"';Y=\"'\";D='X='+Y+X+Y+';Y='+X+Y+X+';';A=\"D='X='+Y+X+Y+';Y='+X+Y+X+';';A=;B=$(A,1,31);C=$(A,32,43);?D;?B;?X;?A;?X;?C\";B=$(A,1,31);C=$(A,32,43);?D;?B;?X;?A;?X;?C");

    return 0;
}

