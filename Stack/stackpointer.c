#include<stdio.h>
#include<malloc.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top = NULL;

void push(){
    int val;
    printf("Enter value to be pushed");
    scanf("%d",&val);

    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = val;
    temp->next = top;
    top = temp;

}

void pop(){
    int val;
    struct stack *temp;
    if(top!=NULL){
        temp = top;
        val = temp->data;
        top = top->next;
        free(temp);
        printf("Pop value is %d",val);
    }
}

void display()
{
    struct stack *temp;
    temp =top;
    while (temp != NULL)
    {
        printf(" \n %d ", temp->data);
        temp = temp->next;
    }
    
}


void main(){
    int choice,i,n,a;
    printf("\n Enter size of Stack:");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        push();
    }
    printf("\n operations");
    while(choice!=4){
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
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

