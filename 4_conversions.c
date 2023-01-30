#include<stdio.h>
#include<ctype.h>
int top =-1, stack[100];
void push(int n){
    top++;
    stack[top]=n;
}
int pop(){
    return stack[top--];
}
int main(){
    char exp[100], *e;
    int num,num1,num2,r;
    printf("Enter postfix expression: \n");
    scanf("%s",exp);
    e=exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e-48;
            push(num);
        }
        else
        {
            num1=pop();
            num2=pop();
            if (*e=='+')
            {
                r=num1+num2;
            }
            else if (*e=='-')
            {
                r=num1-num2;
            }
            else if (*e=='*')
            {
                r=num1*num2;
            }
            else if (*e=='/')
            {
                r=num1/num2;
            }
            push(r);
        }
        e++;
    }
}