#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Q{
    int data[MAX];
    int R,F;
}Q;

void init(Q*P){
    P->R = -1;
    P->F = -1;
}

int isEmpty(Q*P){
    if(P->R == -1)
    return 1;
    return 0;
}

int isFull(Q*P){
    if(P->R == MAX - 1)
    return 1;
    return 0;
}

void enquene(Q*P){
    int x;
    printf("\n Enter number to be inserted: ");
    scanf("%d",&x);
    if(P->R == -1){
        P->R = P->F = 0;
        P->data[P->R] = x;
    }
    else{
        P->R = P->R + 1;
        P->data[P->R] = x;
    }
}

int dequene(Q*P){
    int x;
    x = P->data[P->F];
    if(P->F == P->R){
        P->F = -1;
        P->R = -1;
    }
    else
    P->F = P->F + 1;
    return(x);
}

void print(Q*P){
    int i;
    if(!isEmpty(P)){
        for(i=P->F; i<=P->R; i++){
            printf(" %d", P->data[i]);
        }
        
    }
}

int main(){
    Q q;
    int x,i,choice;
    init(&q);
    printf("Enter 5 elements");
    for(i=0;i<5;i++){
        if(!isFull(&q)){
            enquene(&q);
        }
        else{
            printf("quene is full");
            exit(0);
        }
    }
    while(choice!=4){
    printf("\n\n 1.Insert \n 2.Delete\n 3.Display \n 4.Exit");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enquene(&q);
                break;
            }
            case 2:
            {
                dequene(&q);
                break;
            }
            case 3:
            {
                print(&q);
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