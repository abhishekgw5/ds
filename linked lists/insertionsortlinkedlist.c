// C program to sort linkedlist using insertionsort

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *sorted = NULL;

void create(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    
    newnode->next = head;
   
    head = newnode;
}

void sortedInsert(struct node *newnode)
{
    if (sorted == NULL || sorted->data >= newnode->data)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        struct node *current = sorted;

        while (current->next != NULL && current->next->data < newnode->data)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionsort()
{

    struct node *current = head;

    while (current != NULL){

        struct node *next = current->next;

        sortedInsert(current);

        current = next;
    }

    head = sorted;
}


void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    
}

int main()
{
    int n, i, a;
    printf("Enter no. of nodes to be: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter element no. %d: ",i+1);
        scanf("%d", &a);
        create(a);
    }

    printf("\n Linked List before sorting:\n\t");
    printlist(head);
    printf("\n");

    insertionsort(head);

    printf("\n Linked List after sorting:\n\t");
    printlist(head);
}
