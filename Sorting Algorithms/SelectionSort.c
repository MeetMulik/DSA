#include <stdio.h>

void SelectionSort(int arr[], int n)
{
    int minElement;

    for (int i = 0; i < n - 1; i++)
    {
        minElement = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minElement])
            {

                minElement = j;
            }
        }

        int temp = arr[minElement];
        arr[minElement] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {12,24,8,99,74,101};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\nBefore sorting array elements are - \n");
    printArray(a, n);
    SelectionSort(a, n);
    printf("\nAfter sorting array elements are - \n");
    printArray(a, n);
    return 0;
}