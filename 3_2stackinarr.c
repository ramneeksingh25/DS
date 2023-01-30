#include <stdio.h>
int main()
{
    int n, a[100] = {0}, top1, top2, s1, e1, s2, e2, o, s;
    printf("Enter size of array:");
    scanf("%d", &n);
    top1 = -1;
    top2 = n;
    s1 = 0;
    e1 = n / 2;
    e2 = e1 + 1;
    s2 = n - 1;
    for (int x = 0; x < 100; x++)
    {
        printf("Enter 1 for first stack and 2 for second stack and 3 to exit: ");
        scanf("%d", &s);
        if (s == 1)
        {
            printf("Implementing Stack 1: \n");
            for (int j = 0; j < 100; j++)
            {

                printf("Enter 1 for Push, 2 for Pop, 3 to exit stack: ");
                scanf("%d", &o);
                if (o == 1)
                {
                    if (top1 >= e1 - 1)
                    {
                        printf("Stack 1 is full!(Overflow)\n");
                    }
                    else
                    {
                        top1++;
                        printf("Enter element to be pushed:");
                        scanf("%d", &a[top1]);
                        printf("Stack 1: \n");
                        for (int i = s1; i < e1; i++)
                        {
                            printf("%d\t", a[i]);
                        }
                        printf("\n");
                    }
                }
                else if (o == 2)
                {
                    if (top1 == -1)
                    {
                        printf("Stack 1 is empty!(Underflow!)\n");
                    }
                    else
                    {
                        printf("%d... Element is popped!\n", a[top1]);
                        a[top1] = 0;
                        top1 -= 1;
                        for (int i = s1; i < e1; i++)
                        {
                            printf("%d\t", a[i]);
                        }
                        printf("\n");
                    }
                }
                else if (o == 3)
                {
                    printf("Exiting stack 1!\n");
                    break;
                }
                else
                {
                    printf("Error!\n");
                }
            }
        }
        else if (s == 2)
        {
            printf("Implementing Stack 2: \n");
            for (int j = 0; j < 100; j++)
            {
                printf("Enter 1 for Push, 2 for Pop, 3 to exit stack: ");
                scanf("%d", &o);
                if (o == 1)
                {
                    if (top2 == e1)
                    {
                        printf("Stack 2 is full!(Overflow)\n");
                    }
                    else
                    {
                        top2--;
                        printf("Enter element to be pushed:");
                        scanf("%d", &a[top2]);
                        printf("Stack 2: \n");
                        for (int y = s2; y >= e2-1; y--)
                        {
                            printf("%d\t", a[y]);
                        }

                        printf("\n");
                    }
                }
                else if (o == 2)
                {
                    if (top2 == n)
                    {
                        printf("Stack 2 is empty!(Underflow!)\n");
                    }
                    else
                    {
                        printf("%d... Element is popped!\n", a[top2]);
                        a[top2] = 0;
                        top2++;
                        for (int y = s2; y >= e2-1; y--)
                        {
                            printf("%d\t", a[y]);
                        }
                        printf("\n");
                    }
                }
                else if (o == 3)
                {
                    printf("Exiting stack 2!\n");
                    break;
                }
                else
                {
                    printf("Error!\n");
                }
            }
        }
        else if (s == 3)
        {
            printf("Exiting array!\n");
            break;
        }
    }
}