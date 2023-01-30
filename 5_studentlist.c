#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        printf("The Student List is\n");
        struct node *temp;
        temp = head;
        while (temp->link != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("%d->", temp->data);
        printf("\n");
    }
}
void insfront(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    if (head == NULL)
    {
        new->link = NULL;
    }
    else
    {
        new->link = head;
    }
    head = new;
    display();
}
void insend(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
    display();
}
void inssp(int data)
{
    int value;
    printf("Enter the rollno. after which you want to insert element: ");
    scanf("%d", &value);
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    if (head == NULL)
    {
        head = new;
        new->link = NULL;
        return;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        while (ptr->data != value && ptr != NULL)
        {
            ptr = ptr->link;
        }
        if (ptr == NULL)
        {
            printf("Value not found!\n");
            return;
        }
        else
        {
            new->link = ptr->link;
            ptr->link = new;
        }
        display();
    }
}
int delfront()
{
    int value;
    if (head == NULL)
    {
        printf("Underflow! the list is empty!\n");
        return 0;
    }
    else
    {
        struct node *temp;
        temp = head;
        if (temp->link == NULL)
        {
            head = NULL;
            value = temp->data;
            free(temp);
        }
        else
        {
            head = temp->link;
            value = temp->data;
            free(temp);
        }
        return value;
    }
}
int delend()
{
    if (head == NULL)
    {
        printf("Underflow! No Student present in list\n");
        return 0;
    }
    else
    {
        int item;
        struct node *temp, *p;
        temp = head;
        if (head->link == NULL)
        {
            item = head->data;
            temp = head;
            free(temp);
            return item;
        }
        else
        {
            while (temp->link != NULL)
            {
                p = temp;
                temp = temp->link;
            }
            item = p->data;
            p->link = NULL;
            free(temp);
            return item;
        }
    }
}
int delsp()
{
    struct node *temp;
    struct node *p;
    int value;
    printf("Enter Roll No. to be deleted: ");
    scanf("%d", &value);
    if (head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        if (head->link == NULL && head->data == value)
        {
            temp = head;
            free(temp);
            head = NULL;
        }
        else
        {
            while (temp->data != value && temp != NULL)
            {
                p = temp;
                temp = temp->link;
                if (temp == NULL)
                {
                    printf("Student not found in list!");
                }
                else
                {
                    p->link = temp->link;
                    free(temp);
                }
            }
        }
    }
    return value;
}
void reverse()
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *forw = NULL;
    while (curr != NULL)
    {
        forw = curr->link;
        curr->link = prev;
        prev = curr;
        curr = forw;
    }
    head = prev;
}

int main()
{
    int opt = 0;
    while (opt != 3)
    {
        printf("Enter choice\n  1.Insert \n  2.Delete\n  3.Exit\n  4.Reverse\n");
        scanf("%d", &opt);
        int c;
        switch (opt)
        {
        case 1:
            printf("Enter choice:\n  5.Insert at Beginning\n  6.Insert at end\n  7.Insert at a specified position\n");
            scanf("%d", &c);
            int y;
            switch (c)
            {
            case 5:
                printf("Enter Roll No. to be inserted: ");
                scanf("%d", &y);
                insfront(y);
                break;
            case 6:
                printf("Enter Roll No. to be inserted: ");
                scanf("%d", &y);
                insend(y);
                break;
            case 7:
                printf("Enter Roll No. to be inserted: ");
                scanf("%d", &y);
                inssp(y);
                break;
            default:
                printf("Error in choice! Enter Valid Number!\n");
                break;
            }
            break;
        case 2:
            printf("Enter choice:\n  8.Delete at Beginning\n  9.Delete at end\n  10.Delete at a specified position\n");
            scanf("%d", &c);
            switch (c)
            {
            case 8:
            {
                printf("Roll No. %d has been deleted from the list.\n", delfront());
                break;
            }
            case 9:
            {
                printf("Roll No. %d has been deleted from the list.\n", delend());
                break;
            }
            case 10:
            {
                printf("Roll No. %d has been deleted from the list.\n", delsp());
                break;
            }
            default:
            {
                printf("Error in choice! Enter valid number!\n");
                break;
            }
            }
            break;
        case 3:
            display();
            printf("Exiting!...\n");
            break;
            return 0;
        case 4:
            reverse();
            display();
            break;
        default:
            printf("Error in choice! Enter valid number!\n");
            break;
        }
    }
    return 0;
}