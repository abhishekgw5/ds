#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head)
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
    int choice, a,n;
    struct node *top = NULL;

    printf("\n Enter size of Stack:");
    scanf("%d",&n);
    printf("\n operations");
    
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter element to be pushed :");
                scanf("%d", &a);
                push(top,a);
                break;
            }
            case 2:
            {
                pop(top);
                break;
            }
            case 3:
            {
                display(top);
                break;
            }
            case 4:
            {
                printf("\n exit");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice");
            }
                
        }
    
    return 0;
}