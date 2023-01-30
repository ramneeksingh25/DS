#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *link;
};
struct stack *head = NULL;
void PUSH()
{
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    int x;
    printf("Enter element to be pushed:");
    scanf("%d", &x);
    new->data = x;
    if (head == NULL)
    {
        new->link = NULL;
    }
    else
    {
        new->link = head;
    }
    head = new;
}
void POP()
{
    int y;
    if (head == NULL)
    {
        printf("Underflow!!!\n");
        return;
    }
    else
    {
        struct stack *temp;
        temp = head;
        if (temp->link == NULL)
        {
            head = NULL;
            y = temp->data;
            free(temp);
        }
        else
        {
            head = temp->link;
            y = temp->data;
            free(temp);
        }
        printf("Element %d has been popped!!!\n", y);
    }
}
void PEEK()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The first element of stack is %d \n", head->data);
    }
}
void TRANSERVE()
{
    struct stack *temp;
    if (head == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("The Stack is:- ");
        temp = head;
        while (temp->link != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}
int main()
{
    int c;
    do
    {
        printf("Choices:\n 1.PUSH 2.POP 3.Peek 4.TRAVERSE 5.Exit\nEnter choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            PEEK();
            break;
        case 4:
            TRANSERVE();
            break;
        case 5:
            printf("Exiting!...\n");
            return 0;
            break;
        default:
            printf("Error! Enter a valid choice!\n");
            break;
        }
    } while (c != 5);
    return 0;
}