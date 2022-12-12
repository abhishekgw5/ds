#include<stdio.h>
#include<stdlib.h>

struct circularQuene{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularQuene *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQuene *q){
    if((q->r + 1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enquene(struct circularQuene *q, int val){
    if(isFull(q)){
        printf("This quene is full");
    }
    else{
        q->r = (q->r + 1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued element = %d\n", val);
    }
}

int dequene(struct circularQuene *q){
    int a = -1;
    if(isEmpty(q)){
        printf("empty quene");
    }
    else{
        q->f = (q->f + 1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct circularQuene q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enquene(&q, 12);
    enquene(&q, 1223);
    enquene(&q, 121);
    printf("Dequeuing element %d\n", dequene(&q));
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }

    return 0;
}