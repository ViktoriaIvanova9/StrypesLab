#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Връща 1 ако множеството е празно. Иначе - връща 0.
bool isEmpty(uint64_t set)
{
    while (set)
    {
        if (set & 1)
        {
            return 0;
        }
        set >>= 1;
    }

    return 1;
}

// Добавя елемента с подадения индекс към множеството set и връща новото множество като резултат.
uint64_t addElement(uint64_t set, char index)
{
    if (set & (1ULL << (64 - index)))
    {
        printf("This element is already in the set!\n");
        return EXIT_FAILURE;
    }

    return set |= (1ULL << (64 - index));
}

// Премахва елемента с подадения индекс от множеството set и връща новото множество като резултат.
uint64_t removeElement(uint64_t set, char index)
{
    if (!(set & (1ULL << index)) == 0)
    {
        printf("This element isn't in the set!\n");
        return EXIT_FAILURE;
    }

    return set &= ~(1ULL << (64 - index));
}

// Връща 1 ако всички възможни елементи принадлежат на множеството. Иначе - връща 0.
bool isFull(uint64_t set)
{
    while (set)
    {
        if (!(set & 1))
        {
            return 0;
        }
        set >>= 1;
    }

    return 1;
}

// Връща 1 ако setB е подмножество на setA.
bool isSubset(uint64_t setA, uint64_t setB)
{
    return (setA | setB) == setA;
}

// Връща обединението на setA и setB.
uint64_t unionSets(uint64_t setA, uint64_t setB)
{
    return setA | setB;
}

// Връща сечението на setA и setB.
uint64_t intersectSet(uint64_t setA, uint64_t setB)
{
    return setA & setB;
}

// Връща разликата на setA и setB.
uint64_t difference(uint64_t setA, uint64_t setB) // implication (A -> B) is equivalent to (~A | B)
{
    return ~((~setA) | setB);
}

// Връща броя на елементите в set.
char numElements(uint64_t set)
{
    char counter = 0;
    while (set)
    {
        if (set & 1)
        {
            counter++;
        }
        set >>= 1;
    }

    return counter;
}

void printSet(uint64_t set)
{
    for (int i = 63; i >= 0; --i)
    {
        putchar(!!(set & (1ULL << i)) ? '1' : '0');
    }
    putchar('\n');
}

int main()
{
    // I decided that I won't alter the sets after calling these functions.
    uint64_t setA = 12345;
    uint64_t setB = 2567;

    printf("SetA: ");
    printSet(setA);

    printf("SetB: ");
    printSet(setB);

    printf("Is empty: %d\n", isEmpty(setA));

    printf("Add element: ");
    printSet(addElement(setA, 55));

    printf("Remove element: ");
    printSet(removeElement(setA, 60));

    printf("Is full: %d\n", isFull(setA));
    printf("Is setB subset of setA: %d\n", isSubset(setA, setB));

    printf("Union setA and setB: ");
    printSet(unionSets(setA, setB));

    printf("Intersection setA and setB: ");
    printSet(intersectSet(setA, setB));

    printf("Difference setA and setB: ");
    printSet(difference(setA, setB));

    printf("Num elements: %d\n", numElements(setA));

    return 0;
}