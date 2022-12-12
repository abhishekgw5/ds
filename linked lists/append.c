#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void create1(int val)
{
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    
    newnode->next = head1;
   
    head1 = newnode;
}

void create2(int val)
{
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    
    newnode->next = head2;
   
    head2 = newnode;
}

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }    
}

void append(struct node *head1, struct node *head2){
    struct node *temp;

    if(head1 == NULL){
        head1 = head2;
    }
    else{
        temp = head1;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head2;
    }
    head2=NULL;
}


int main()
{
    int n, i, a;
    printf("Enter no. of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter element: ");
        scanf("%d", &a);
        create1(a);
    }
    printlist(head1);

    printf("\nEnter no. of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter element: ");
        scanf("%d", &a);
        create2(a);
    }
    printlist(head2);
    
    printf("\n");

    append(head1,head2);
    
    printlist(head1);

    return 0;
}