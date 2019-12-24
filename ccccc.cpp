#include <stdio.h>

double mypow( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%f\n", mypow(x, n));

    return 0;
}
double mypow( double x, int n )
{
int i;
double sum=1;
for(i=1;i<=n;i++)
{
sum=sum*x;
}
return sum;
}
