#include<stdio.h>
#include<malloc.h>

struct stack{
    int data;
    struct stack *next;
};


void push(struct stack **top){
    int val;
    printf("Enter value to be pushed");
    scanf("%d",&val);

    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = val;
    temp->next = *top;
    *top = temp;

}

int pop(struct stack **top){
    int val;
    struct stack *temp;
    if(*top==NULL){
        printf("Stack is empty");
        return 0;
    }
    else{
        temp = *top;
        *top = (*top)->next;
        val = temp->data;      
        free(temp);
        return(val);
        printf("Pop value is %d",val);
    }
    
}

void display(struct stack **top)
{
    struct stack *temp;
    temp = *top;
    while (temp != NULL)
    {
        printf(" \n %d ", temp->data);
        temp = temp->next;
    }
    
}

void init(struct stack **top)
{
    *top=NULL;
}


void main(){
    int choice,n;
    struct stack *top;
    init(&top);
    printf("\n Enter size of Stack:");
    scanf("%d",&n);
    printf("\n operations");
    while(choice!=4){
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push(&top);
                break;
            }
            case 2:
            {
                pop(&top);
                break;
            }
            case 3:
            {
                display(&top);
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
}

