#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double *x1, double *x2)
{
    int D = b * b - 4 * a * c;

    if (D < 0)
    {
        return -1;
    }

    *x1 = (-b + sqrt(D)) / (2 * a);
    *x2 = (-b - sqrt(D)) / (2 * a);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Three arguments needed!");
        return -1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    double x1, x2;

    if (quadEq(a, b, c, &x1, &x2) == 0)
    {
        printf("x1 = %.2lf\n", x1);
        printf("x1 = %.2lf\n", x2);
    }
    else
    {
        printf("No real roots!\n");
    }
    return 0;
}