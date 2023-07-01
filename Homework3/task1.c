#include <stdio.h>
#include <math.h>

#define EPS 0.001

int triangle(double a, double b, double c, double *S, double *P)
{
    if ((a + b - c <= EPS) || (a + c - b <= EPS) || (b + c - a <= EPS) || a <= EPS || b <= EPS || c <= EPS)
    {
        return -1;
    }

    *P = a + b + c;

    double semiPerimeter = *P / 2;

    *S = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

    return 0;
}

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double S, P;
    if (triangle(a, b, c, &S, &P) == 0)
    {
        printf("S = %.2lf\n", S);
        printf("P =  %.2lf\n", P);
    }
    else
    {
        printf("Invalid triangle sides!\n");
    }

    return 0;
}