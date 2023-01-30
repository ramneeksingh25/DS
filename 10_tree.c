#include<stdio.h>
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}TREE;
TREE* createNode(int value){
    TREE* new=(TREE*)malloc(sizeof(TREE));
    new->data=value;
    new->lchild=NULL;
    new->rchild=NULL;
}
TREE* insertLeft(TREE* parent, int value){
    parent->lchild=createNode(value);
    return parent->lchild;
}
TREE* insertRight(TREE* parent, int value){
    parent->rchild=createNode(value);
    return parent->rchild;
}
int main(){
    TREE* root;
    int c1;
    while (true)
    {
        printf("Enter choice:\n 1.Insert\n 2.Delete\n 3.Exit\n");
        scanf("%d",&c1);
        if (c1==1)
        {
            int new;
            printf("Enter value to insert:");
            scanf("%d",&new);
            insert(new);     
        }        
    }
    return 0;
}