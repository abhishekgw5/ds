#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    struct node *p = newnode(1);
    struct node *p1 = newnode(2);
    struct node *p2 = newnode(3);

    p->left = p1;
    p->right = p2;

    return 0;
}