#include <stdio.h>

#define MAX(x, y, z) (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z)

#define MIN(x, y, z) (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z)

#define SETBIT(mask, bit) mask |= (1ULL << bit)

#define CLEARBIT(mask, bit) mask &= ~(1ULL << bit)

#define INVERSEBIT(mask, bit) mask ^= (1ULL << bit)

#define CHECKBIT(mask, bit) !!(mask & (1ULL << bit))

#define SWAP(a, b) \
    (a ^= b);      \
    (b ^= a);      \
    (a ^= b);

void printInBinary(int number)
{
    for (int i = 63; i >= 0; --i)
    {
        putchar(!!(number & (1ULL << i)) ? '1' : '0');
    }
    putchar('\n');
}

int main()
{
    int x = -3, y = 1, z = 10;

    printf("MAX: %d\n", MAX(x, y, z));
    printf("MIN: %d\n", MIN(x, y, z));

    int mask = 5377;
    printf("ORIGINAL:   ");
    printInBinary(mask);

    printf("SETBIT:     ");
    printInBinary(SETBIT(mask, 5));

    printf("CLEARBIT:   ");
    printInBinary(CLEARBIT(mask, 0));

    printf("INVERSEBIT: ");
    printInBinary(INVERSEBIT(mask, 2));

    printf("CHECKBIT: %d\n", CHECKBIT(mask, 2));

    SWAP(x, y);
    printf("x: %d, y: %d\n", x, y);

    return 0;
}