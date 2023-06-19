#include <stdio.h>

void printRights(int number)
{
    printf((number & 4) ? "R" : "-");
    printf((number & 2) ? "W" : "-");
    printf((number & 1) ? "X" : "-");
}

int main()
{
    int octalNumber;
    scanf("%o", &octalNumber);

    printRights((octalNumber >> 6) & 7); // taking the first digit of octal number
    printRights((octalNumber >> 3) & 7); // taking the second digit of octal number
    printRights(octalNumber);

    return 0;
}