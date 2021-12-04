#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {56, 78, 41, 62, 35, 98};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\nBefore sorting array elements are - \n");
    printArr(a, n);
    insertionSort(a, n);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, n);

    return 0;
}