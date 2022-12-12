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

int isBST(struct node *root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }

        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node *newnode(int data){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data){
            printf("cant insert");
        }
        else if(key<root->data){ 
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    struct node* new = newnode(key);
    if(key< prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
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

    preorder(p);
    printf("\n");
    // inorder(p);
    // printf("\n");
    // postorder(p);

    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }

    insert(p,10);

    inorder(p);
    return 0;
}