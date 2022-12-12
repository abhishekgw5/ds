#include<stdio.h>
#define SIZE 20
int stack[100],choice,n,top,x,i;
int top1 = -1;
int top2 = SIZE;

void push1()
{
    if(top1>top2-1)
    {
        printf("\nStack1 is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top1++;
        stack[top1]=x;
    }
}

void push2()
{
    if(top1>top2-1)
    {
        printf("\nStack2 is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top2--;
        stack[top2]=x;
    }
}

void pop1()
{
    if(top1<=-1)
    {
        printf("\n Stack1 is under flow");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top1]);
        top1--;
    }
}

void pop2()
{
    if(top2>SIZE)
    {
        printf("\n Stack2 is under flow");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top2]);
        top2++;
    }
}

void display1()
{
    if(top1<=-1)
    {
        printf("\n The Stack1 is empty");
    }
    else
    {
        printf("\n Stack1 \n");
        for(i=top1; i>=0; i--)
            printf("%d ",stack[i]);
        printf("\n Press Next Choice");
    }
   
}

void display2()
{
    if(top2>SIZE)
    {
        printf("\n The Stack2 is empty");
        
    }
    else
    {
        printf("\n Stack2 \n");
        for(i=top2; i<=SIZE; i++)
            printf("%d ",stack[i]);
        printf("\n Press Next Choice");
    }
   
}

int main()
{
    // printf("\n Enter size of Stack:");
    // scanf("%d",&SIZE);
    printf("\n operations");
    
    printf("\n 1.PUSH1\n 2.POP1\n 3.DISPLAY1\n 4.PUSH2\n 5.POP2\n 6.DISPLAY2\n7.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push1();
                break;
            }
            case 2:
            {
                pop1();
                break;
            }
            case 3:
            {
                display1();
                break;
            }
            case 4:
            {
                push2();
                break;
            }
            case 5:
            {
                pop2();
                break;
            }
            case 6:
            {
                display2();
                break;
            }
            case 7:
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
    while(choice!=7);
    return 0;
}