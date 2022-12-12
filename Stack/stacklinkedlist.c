#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    
}

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


struct node * push(struct node *top, int x){
    if(isFull(top)){
        printf("Stack overflow");
    }
    else{
        struct node * n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node **top){
    if(isEmpty(*top)){
        printf("\nStack underflow");
    }
    else{
        struct node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main(){
    struct node *top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 90);
    int element = pop(&top);
    printlist(top);
    return 0;

}