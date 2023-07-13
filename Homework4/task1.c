#include <stdio.h>

// the time complexity will be 2(n - 1) ~ n
// If the array is sorted the complexity will be n*logn

int secondMax(const int *arr, size_t n, int *secondMax)
{
    if (!arr)
    {
        return -1;
    }

    if (n == 1)
    {
        return -2;
    }

    size_t count = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
    }

    if (count == n - 1)
    {
        return -3;
    }

    int firstMax = arr[0];
    *secondMax = arr[0];

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > firstMax)
        {
            *secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (arr[i] < firstMax && arr[i] > *secondMax)
        {
            *secondMax = arr[i];
        }
    }

    return 0;
}

int main()
{
    int sm;

    int* arr1 = NULL;
    int arr2[] = {15};
    int arr3[] = {12, 34, 5, 70, 46};
    int arr4[] = {12, 12, 12, 12, 12};

    int validationResult = secondMax(arr3, 5, &sm); // for different results change arr1/2/3/4 and number of elements

    if (validationResult == 0)
    {
        printf("Second max is: %d\n", sm);
    }
    else if (validationResult == -1)
    {
        fprintf(stderr, "Array is empty!\n");
        return -1;
    }
    else if (validationResult == -2)
    {
        fprintf(stderr, "Only one element in array!\n");
        return -1;
    }
    else if (validationResult == -3)
    {
        fprintf(stderr, "All elements are equal!\n");
        return -1;
    }

    return 0;
}