#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void create(int val){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next =  head;
    newnode->prev = NULL;
    head = newnode;
}

struct node *insertAtFirst(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    return ptr;
}

struct node *insertAtEnd(struct node * head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
    return head;

}

struct node *deletionAtFirst(struct node *head){
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node *deletionAtEnd(struct node *head){
    struct node *ptr = head;
    struct node *q = head->next;

    while(q->next!=NULL){
        ptr = ptr->next;
        q=q->next;
    }
    ptr->next = NULL;
    free(q);

    return head;
}

struct node *deletionAtIndex(struct node *head, int index){
    struct node *p = head;

    for(int i=0; i<index-1; i++)
    {
        p=p->next;
    }

    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);

    return head;
}

void printlist(struct node *head)
{
    struct node *p=head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }    
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
    // head = insertAtFirst(head, 56);
    // head = insertAtEnd(head, 48);
    //head = deletionAtIndex(head,2);
    printf("\nLinked list after deletion\n");
    printlist(head);

    return 0;
}