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

struct node *deletionAtFirst(struct node *head)
{
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deletionAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for(int i=0; i<index-1; i++)
    {
        p=p->next;
        q=q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct node *deletionAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
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
    printf("Linked list before deletion\n");
    printlist(head);
    
    // head = deletionAtFirst(head);
    head = deletionAtEnd(head);
    //head = deletionAtIndex(head,2);
    printf("\nLinked list after deletion\n");
    printlist(head);

    return 0;
}


