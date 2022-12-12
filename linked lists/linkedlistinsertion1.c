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

struct node *insertAtFirst(struct node *head, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertAtEnd(struct node * head, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertAtIndex(struct node * head, int data, int index)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }   

    ptr->next = p->next;
    p->next = ptr;
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
    printf("Linked list before insertion\n");
    printlist(head);
    
    // head = insertAtFirst(head, 56);
    //head = insertAtEnd(head, 48);
    head = insertAtIndex(head, 10, 3);
    printf("\nLinked list after insertion\n");
    printlist(head);

    return 0;
}


