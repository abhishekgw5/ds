#include<stdio.h>
#include<stdlib.h>

struct quene {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct quene *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct quene *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enquene(struct quene *q, int val){
    if(isFull(q)){
        printf("This quene is full");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequene(struct quene *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Quene is full");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct quene q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    
    enquene(&q, 12);
    enquene(&q, 15);

    printf("Dequene element %d", dequene(&q));
    printf("Dequene element %d", dequene(&q));

    if(isEmpty(&q)){
        printf("empty quene");
    }
    return 0;
}