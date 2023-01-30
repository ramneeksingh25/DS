#include <stdio.h>
int LS(int a[], int size, int key)
{
    for (int i = 0; i <= size; i++)
    {
        if (a[i] == key)
        {
            return i + 1;
        }
    }
    return -1;
}

int BS(int a[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, a[100], x1, x2, r1, r2;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to found by Linear Search: ");
    scanf("%d", &x1);
    r1 = LS(a, n, x1);
    if (r1 == -1)
    {
        printf("The element you entered isn't present in the array.\n");
    }
    else
    {
        printf("The element is at position %d \n", r1);
    }
    printf("Enter the element to found by Binary Search: ");
    scanf("%d", &x2);
    r2 = BS(a, 0, n, x2);
    if (r2 == -1)
    {
        printf("The element you entered isn't present in the array.");
    }
    else
    {
        printf("The element is at position %d \n", r2 + 1);
    }
    return 0;
}