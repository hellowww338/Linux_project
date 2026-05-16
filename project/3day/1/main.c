#include "stdio.h"
#include "cal.h"

int main(void)
{
    float x,y;
    printf("Please enter a two-digit number x&y\n");
    scanf("%f %f",&x,&y);
    printf("x+y=%.2f\n",add(x,y));
    printf("x-y=%.2f\n",sub(x,y));
    printf("x*y=%.2f\n",mul(x,y));
    printf("x/y=%.2f\n",div(x,y));
    printf("sqrt(x)=%.2f\nsqrt(y)=%.2f\n",mysqrt(x),mysqrt(y));
    return 0;
}
