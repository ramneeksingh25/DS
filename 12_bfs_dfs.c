#include<stdio.h>
void printmatrix(int n,float matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f \t",matrix[i][j]);
        }
        printf("\n");
    }
}
void bfs(float matrix, int n){
    
}
int main()
{
    int n;
    printf("Enter the number of nodes in graph: ");
    scanf("%d",&n);
    float matrix[n][n];
    printf("Enter adjacency matrix of the graph: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]=",i+1,j+1);
            scanf("%f",&matrix[i][j]);
        }
    }
    printmatrix(n,matrix);
    bfs(matrix,n);
}