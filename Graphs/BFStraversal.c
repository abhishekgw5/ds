#include<stdio.h>
#include<stdlib.h>

int visited[7];
int a [7][7];

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void BFS(int s,int n){
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    enqueue(&q, s); // Enqueue i for exploration
    visited[s] = 1;
    
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < n; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

void DFS(int i,int n){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < n; j++)
    {
        if(a[i][j]==1 && !visited[j]){
            DFS(j,n);
        }
    }
}
 
int main(){
    // Initializing Queue (Array Implementation)
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    
    // BFS Implementation 
    // int node;
    // int i = 1;

    // BFS(0,7);

    printf("ans\n\n");

    DFS(0,7);
    
    return 0;
}

