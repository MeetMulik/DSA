#include <stdio.h>

int partition(int a[], int lb, int ub)
{

    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void quickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int location = partition(a, lb, ub);
        quickSort(a, lb, location - 1);
        quickSort(a, location + 1, ub);
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
    int a[] = {63,42,78,54,15,9};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements are - \n");
    printArr(a, n);
    quickSort(a, 0, n - 1);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, n);
    return 0;
}