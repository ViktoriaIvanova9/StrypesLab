#include <stdio.h>

short int isCorrectInput(char c)
{
    return c >= 'a' && c <= 'z';
}

int main()
{
    char smallLetter;
    printf("Enter small letter: ");
    scanf("%c", &smallLetter);

    if (!isCorrectInput(smallLetter))
    {
        printf("Incorrect input!");
        return -1;
    }

    printf("The capital representation is: %c\n", smallLetter - 32);
    return 0;
}