#include <stdio.h>

unsigned short int isCorrectInput(int number)
{
    return (number >= -100000) && (number <= 100000);
}

unsigned short int positiveNumber(int number) // 0 for positive, -1 for negative
{
    return 1 + (number >> 31) - (-number >> 31);
}

int main()
{
    int number;
    printf("Enter number in interval [-100000, 100000]: ");
    scanf("%d", &number);

    if (!isCorrectInput(number))
    {
        printf("The number isn't in the correct interval!");
        return -1;
    }

    int result = positiveNumber(number);
    if (result == 1)
    {
        printf("ZERO\n");
    }
    else if (result == 0) // is positive?
    {
        printf("NO\n");
    }
    else // isNegative?
    {
        printf("YES\n");
    }

    return 0;
}