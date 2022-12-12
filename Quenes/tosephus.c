#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct circularQuene{
    int size;
    int f;
    int r;
    int data[MAX];
};

int isEmpty(struct circularQuene *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQuene *q){
    if((q->r + 1)%MAX == q->f){
        return 1;
    }
    return 0;
}

void enquene(struct circularQuene *q, int val){
    if(isFull(q)){
        printf("This quene is full");
    }
    else{
        q->r = (q->r + 1)%MAX;
        q->data[q->r] = val;
        // printf("Enqued element = %d\n", val);
    }
}

int dequene(struct circularQuene *q){
    // int a = -1;
    int a;
    if(isEmpty(q)){
        printf("empty quene");
    }
    else{
        q->f = (q->f + 1)%MAX;
        a=q->data[q->f];
    }
    return a;
}



int main(){
    int m,n,i,x,j;
    struct circularQuene q;
    q.f = q.r = -1;

    printf("\n Enter number of peoples: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        enquene(&q,i);
    }
    
    // q->data = (int*)malloc(MAX*sizeof(int));

    printf("\nEnter number: ");
    scanf("%d",&m);

    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            x = dequene(&q);
            enquene(&q,x);
        }
        x=dequene(&q);         
    }

    printf("\n %d is winner",q.data[q.r]);

    // enquene(&q, 12);
    // enquene(&q, 1223);
    // enquene(&q, 121);
    // printf("Dequeuing element %d\n", dequene(&q));
    // if(isEmpty(&q)){
    //     printf("Queue is empty\n");
    // }
    // if(isFull(&q)){
    //     printf("Queue is full\n");
    // }

    return 0;
}