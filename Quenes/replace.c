// not running

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Q
{
    int data[MAX];
    int R, F;
} Q;

typedef struct node
{
    int key;
    int next;
} node;

void init(Q *P)
{
    P->R = -1;
    P->F = -1;
}

int isEmpty(Q *P)
{
    if (P->R == -1)
        return 1;
    return 0;
}

int isFull(Q *P)
{
    if (P->R == MAX - 1)
        return 1;
    return 0;
}

void enquene(Q *P, int x)
{
    if (isFull(P))
    {
        printf("This quene is full");
    }
    else
    {
        // int x;
        // printf(" Enter number to be inserted: ");
        // scanf("%d", &x);
        if (P->R == -1)
        {
            P->R = P->F = 0;
            P->data[P->R] = x;
        }
        else
        {
            P->R = P->R + 1;
            P->data[P->R] = x;
        }
    }
}

int dequene(Q *P)
{
    if (isEmpty(P))
    {
        printf("empty quene");
    }
    else
    {
        int x;
        x = P->data[P->F];
        if (P->F == P->R)
        {
            P->F = -1;
            P->R = -1;
        }
        else
            P->F = P->F + 1;
        return (x);
    }
}

void print(Q *P)
{
    int i;
    if (!isEmpty(P))
    {
        for (i = P->F; i <= P->R; i++)
        {
            printf(" %d", P->data[i]);
        }
        printf("\n");
    }
}

int search(Q *P)
{
    int n1, n2;

    printf("\nEnter two numbers:");
    scanf("%d", &n1);
    // scanf("%d", &n2);
    
    node *tmp = P->F;
    while (tmp != NULL)
    {
        if (tmp->key == n1)
        {
            if (tmp == P->F)
            {
                P->F = tmp->next;
                if (P->F == NULL)
                {
                    P->R = NULL;
                }
                free(tmp);
            }
            else if (tmp == P->R)
            {
            }
            return 0; // found
        }
        tmp = tmp->next;
    }
    return -1; // not found
    printf("\n");
}

int main()
{
    Q q;
    int x, i, choice;
    init(&q);
    enquene(&q, 1);
    enquene(&q, 2);
    enquene(&q, 3);
    enquene(&q, 4);
    enquene(&q, 5);

    print(&q);
    search(&q);
    print(&q);

    return 0;
}

