#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j, a[10][10], count = 0;
    printf("Enter number of columns: ");
    scanf("%d", &c);
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter the elements of the Matrix: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The elements of the matrix are:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] == 0)
            {
                count++;
            }
        }
    }
    if (count > ((r * c) / 2))
        printf("Given matrix is a sparse matrix \n");
    else
        printf("Given matrix is not a sparse matrix\n");
}