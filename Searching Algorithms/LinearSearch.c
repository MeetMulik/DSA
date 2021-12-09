#include <stdio.h>
#include <stdbool.h>

void linearSearch(int a[], int n, int key)
{
    bool notFound = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            notFound = true;
            printf("\nValue found at position %d", i + 1);
        }
    }
    if (!notFound)
    {
        printf("\nValue not found the Array!");
    }
}

int main()
{

    int a[] = {70, 40, 30, 11, 57, 41, 25, 14, 52};
    int key = 70;
    int n = sizeof(a) / sizeof(a[0]);
    printf("\nThe elements of the array are - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nThe value to be found is %d", key);
    linearSearch(a, n, key);
}