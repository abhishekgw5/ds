#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct node * push(struct node *top, int x){
    if(isFull(top)){
        printf("\nStack is over flow");
    }
    else{

        struct node * n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;

        // return top;

    }
}

struct node *pop(struct node *top){
    if(isEmpty(top)){
        printf("\n underfloww");
    }
    else{
        struct node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        // return x;
    }
}

void display(struct node *temp){
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int i, a, n, x, choice ;
    struct node *top = NULL;

    printf("\n Enter size of Stack:");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("enter element");
        scanf("%d",&a);
        push(top, a);
    }

    printf("\n operations");
    
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf(" Enter a value to be pushed:");
                scanf("%d",&x);
                push(top, x);
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
    }
    while(choice!=4);
    return 0;
}