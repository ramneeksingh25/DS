#include <stdio.h>
#include <ctype.h>
#include <math.h>
int top = -1, stack[25] = {0};
void push(int n)
{
    if (top == 25)
    {
        printf("Overflow!!");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}
int pop()
{
    int ch;
    ch = stack[top];
    stack[top] = 0;
    top--;
    return ch;
}
void display()
{
    printf("The Stack is: \n");
    for (int i = 0; stack[i] != 0; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    char exp[25] = {'\0'}, e;
    int num1, num2, res;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("The expression you entered is: \n");
    for (int i = 0; exp[i] != '\0'; i++)
    {
        printf("%c ", exp[i]);
    }
    printf("\n");
    for (int i = 0; exp[i] != '\0'; i++)
    {
        e = exp[i];
        if (isdigit(e))
        {
            push(e - '0');
            display();
        }
        else
        {
            num1 = pop();
            num2 = pop();
            switch (e)
            {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            case '^':
                res = pow(num1, num2);
                break;
            }
            push(res);
            display();
        }
    }
    printf("The result is %d\n", res);
    return 0;
}