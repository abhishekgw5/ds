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

struct node *inOrderPredecessor(struct node* root){
    root=root->left;

    while(root->right!=NULL){
        root=root->right;
    }

    return root;
}

struct node *deletenode(struct node *root, int value){
    struct node *iPre;

    if (root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value<root->data){
        root->left = deletenode(root->left,value);
    }

    else if(value>root->data){
        root->right = deletenode(root->right,value);
    }

    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletenode(root->left,iPre->data);
    }

    return root;
}

int main(){
    struct node *p = newnode(5);
    struct node *p1 = newnode(3);
    struct node *p2 = newnode(6);
    struct node *p3 = newnode(1);
    struct node *p4 = newnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preorder(p);
    // printf("\n");
    inorder(p);
    printf("\n");
    // postorder(p);

    deletenode(p,3);
    inorder(p);
    return 0;
}
