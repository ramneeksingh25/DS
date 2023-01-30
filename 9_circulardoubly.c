#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void insbeg(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->prev = NULL;
    n->data = data;
    n->next = NULL;
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    head->prev->next = n;
    n->prev = head->prev;
    n->next = head;
    head->prev = n;
    head = n;
}
void insend(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->prev = NULL;
    n->data = data;
    n->next = NULL;
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    head->prev->next = n;
    n->prev = head->prev;
    n->next = head;
    head->prev = n;
}
void insspec(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->prev = NULL;
    n->data = data;
    n->next = NULL;
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    int value = 0;
    printf("Enter position after which you want to insert element:");
    scanf("%d", &value);
    struct node *temp;
    if (head->data == value)
    {
        temp = head;
    }
    else
    {
        while (temp->data != value || temp != head)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid!!\n");
            return;
        }
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
    }
    return;
}
void delbeg()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    free(temp);
    temp = NULL;
}
void delend()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    head->prev->prev->next = head;
    head->prev = head->prev->prev;
    head->prev->prev = NULL;
    head->prev->next = NULL;
    return;
}
void delspec()
{
    int value;
    printf("Enter element to delete:");
    scanf("%d", &value);
    struct node *temp;
    struct node *temp1;
    temp = head;
    while (temp->data != value || temp != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid!!\n");
        return;
    }
    temp1->next = temp1->next->next;
    temp1->next->prev = temp1;
    return;
}
void display()
{
    if (head == NULL)
    {
        printf("Empty list!");
    }
    struct node *temp;
    printf("%d", head->data);
    temp = head->next;
    while (temp != head)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int c1 = 0;
    int c2 = 0;
    int data;
    while (c1 != 4)
    {
        printf("Enter the choice:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &c1);
        if (c1 == 1)
        {
            printf("Enter element to insert: ");
            scanf("%d", &data);
            printf("INSERT\n");
            printf("1. At Beginning\n");
            printf("2. At End\n");
            printf("3. At specific position\n");
            scanf("%d", &c2);
            if (c2 == 1)
            {
                insbeg(data);
            }
            else if (c2 == 2)
            {
                insend(data);
            }
            else if (c2 == 3)
            {
                insspec(data);
            }
            else
            {
                printf("Invalid Choice");
            }
        }
        else if (c1 == 2)
        {
            printf("DELETE\n");
            printf("1. At Beginning\n");
            printf("2. At End\n");
            printf("3. At specific position\n");
            scanf("%d", &c2);
            if (c2 == 1)
            {
                delbeg();
            }
            else if (c2 == 2)
            {
                delend();
            }
            else if (c2 == 3)
            {
                delspec();
            }
            else
            {
                printf("Invalid Choice!!\n");
            }
        }
        else if (c1 == 3)
        {
            display();
        }
        else if (c1 == 4)
        {
            return 0;
        }
    }
    return 0;
}