#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTravesal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("\n Elemnt is %d", ptr->data);
        ptr= ptr->next;
    }while(ptr!=head);
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head){
        p=p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node * insertAtLast(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *insertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    int i = 0 ;
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
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = head;

    printf("\n Before = ");
    linkedListTravesal(head);
    //head = insertAtFirst(head, 66);
    //head = insertAtLast(head, 60);
    head = insertAtIndex(head, 88, 2);
    printf("\n after = ");
    linkedListTravesal(head);

    return 0;
}