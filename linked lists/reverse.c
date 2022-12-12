#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int val)
{
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    
    newnode->next = head;
   
    head = newnode;
}

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }    
}

struct node * reverse(struct node *head){
    struct node *temp = 0;
    while(head){
        struct node *temp2 = head->next;
        head->next = temp;
        temp = head;
        head = temp2;
        
    }
    return temp;
    
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
        create(a);
    }
    printlist(head);
    
    printf("\n");
    head = reverse(head);
    printlist(head);

    return 0;
}