#include<stdio.h>
#include<stdlib.h>
struct list
{
    int info;
    struct list *link;
};
struct list *head;
struct list *node;
int size(struct list* node){
    int size=0;
    while (node!=NULL)
    {
        node=node->link;
        size++;
    }
    return size;
}
void display(){
    struct list *ptr=head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->link;
    }
}
void frontins(int data){
    struct list *new = (struct list*)malloc(sizeof(struct list));
    new->info=data;
    new->link=head;
    head=new;
}
void endins(int data){
    struct list *temp;
    struct list *new= (struct list*)malloc(sizeof(struct list));
    if (new==NULL)
    {
        printf("Unable to locate!");
    }
    else{
    new->info=data;
    new->link=NULL;
    temp=head;
    while (temp !=NULL &&temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
    }
}
void spins(int data){
    int n;
    int s=size(head);
    struct list *new=(struct list*)malloc(sizeof(struct list));
    new->info=data;
    new->link=NULL;
    printf("Enter the position to enter the node:");
    scanf("%d",&n);
    if (n<0||n>s)
    {
        printf("Invalid position!");
    }
    else if(n==0){
        frontins(data);
    }
    else
    {
        struct list* temp= head;
        while(--n){
            temp=temp->link;
        }
        new->link=temp->link;
        temp->link=new;
    }
}
void frontdel(){
    struct list *temp;
    if (head==NULL)
    {
        printf("Underflow! no element found in the list!\n");
        return;
    }
    temp=head;
    head=head->link;
    free(temp);    
}
void enddel(){
    struct list *ptr,*ptr1;
    if (head==NULL)
    {
        printf("Underflow! no element found in the list!\n");
    }
    else if(head->link==NULL)
    {
        head=NULL;
        free(head);
        printf("Only Node deleted! List is now empty!\n");
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        free(ptr1);
        printf("Node from end has been deleted!\n");
    }
}
void spdel(){
    int n;
    if (head==NULL)
    {
    printf("Underflow! no element found in the list!\n");
    return;
    }
    printf("Enter position of element to be deleted: ");
    scanf("%d",&n);
    if (n==0)
    {
        frontdel();
    }
    struct list *temp=head;
    for (int i = 0; temp!=NULL && i<n-1; i++)
    {
        temp=temp->link;
    }
    if (temp==NULL||temp->link==NULL)
    {
        printf("Underflow! no elemnt found!\n");
        return;
    }
    struct list *next=temp->link->link;
    free(temp->link);
    temp->link=next;  
}
int main()
{
    int opt=0;
    while(opt!=3)
    {
    printf("Enter choice\n  1.Insert \n  2.Delete\n  3.Exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:{
            int data;
            printf("Enter data to be entered: ");
            scanf("%d",&data);
            int o2;
            printf("Enter choice:\n  1.Insert at Beginning\n  2.Insert at end\n  3.Insert at a specified position\n");
            scanf("%d",&o2);
            switch (o2)
            {
            case 1:
                frontins(data);
                display();
                break;
            case 2:
                endins(data);
                display();
                break;
            case 3:
                spins(data);
                display();
            default:
                printf("Error in choice! Enter Valid Number!\n");
                break;
            }
        break;
        }
        case 2:{
            int o2;
            printf("Enter choice:\n  1.Delete at Beginning\n  2.Delete at end\n  3.Delete at a specified position\n");
            scanf("%d",&o2);
            switch (o2)
            {
            case 1:
                frontdel();
                display();
                break;
            case 2:
                enddel();
                display();
                break;
            case 3:
                spdel();
                display();
            default:
                printf("Error in choice! Enter Valid Number!\n");
                break;
            }
        break;
        }
        case 3:
            display();
            printf("Exiting...\n");
            break;
        default:
            printf("Error in choice! Enter a Valid Number!\n");
            break;
    }
    return 0;
}
}