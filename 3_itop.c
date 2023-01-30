#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push(char c)
{
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
        return -1;
    else
    {
        char ch=stack[top];
        top--;
        return ch;
    }
}
int preference(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[100];
    char *c, x;
    printf("Enter the infix expression : ");
    scanf("%s", exp);
    printf("\n");
    c = exp;
    printf("The postfix expression for the given infix is: \n");
    while (*c != '\0')
    {
        if (isalnum(*c))
            printf("%c ", *c);
        else if (*c == '(')
            push(*c);
        else if (*c == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (preference(stack[top]) >= preference(*c))
                printf("%c ", pop());
            push(*c);
        }
        c++;
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}