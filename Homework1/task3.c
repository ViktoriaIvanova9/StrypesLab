#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define EPS 0.00001

int main()
{
    float number;
    printf("Enter PI aproximation: ");
    scanf("%f", &number);

    printf(fabs(PI - number) < EPS ? "YES\n" : "NO\n");
    return 0;
}