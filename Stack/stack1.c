#include<stdio.h>
int stack[100],choice,n,top,x,i;

void push()
{
    if(top>=n-1)
    {
        printf("\nStack is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("\n Stack is under flow");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\n Stack \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The Stack is empty");
    }
   
}

int main()
{
    top=-1;
    printf("\n Enter size of Stack:");
    scanf("%d",&n);
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
    while(choice!=4);
    return 0;
}