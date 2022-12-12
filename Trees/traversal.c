#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

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
    struct node *p3 = newnode(4);
    struct node *p4 = newnode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder : ");
    preorder(p);
    printf("\nInorder : ");
    inorder(p);
    printf("\nPostorder : ");
    postorder(p);
    return 0;
}
