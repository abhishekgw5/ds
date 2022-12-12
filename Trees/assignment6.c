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

int heightoftree(struct node *root)
{
    int max;
    if (root!=NULL)
    {
        
        int leftsubtree = heightoftree(root->left);
        
        int rightsubtree = heightoftree(root->right);

        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}

void currentlevel(struct node *root, int level)
{
    if (root != NULL) 
    {
        if (level == 1)
        {
            printf("%d ", root->data);
            
        }
        
        else if (level > 1) 
        { 
            currentlevel(root->left, level-1); 
            currentlevel(root->right, level-1);

        }
        			
    }
    
}

void mirror(struct node* node)
{
    if (node == NULL)
        return;
    else {
        struct node* temp;
 
        mirror(node->left);
        mirror(node->right);
 
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int search(struct node* node){
    int val;
    printf("\nEnter value to be searched : ");
    scanf("%d",&val);

    while(node!=NULL){
        if(val > node->data)
        node=node->right;

        else if(val<node->data)
            node=node->left;
        
        else
        return 1;
    }
    return 0;
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


    printf("\nInorder traversal : ");
    inorder(p);

    printf("\n\nInorder traversal after Insertion : ");

    insert(p,10);

    inorder(p);

    deletenode(p,3);
    printf("\n\nInorder traversal after Deletion : ");
    inorder(p);
	
    int i;
    int height = heightoftree(p);
    printf("\n\nHeight of the tree is %d \n",height);
    printf("\nLevel wise display: \n");
    for(i = 1; i <= height; i++)      
    {
        currentlevel(p,i);
        printf("\n");
    }
    heightoftree(p);

    mirror(p);
    printf("\nLevel wise display of mirror tree: \n");
    for(i = 1; i <= height; i++)      
    {
        currentlevel(p,i);
        printf("\n");
    }
    printf("\nInorder traversal of mirror tree : ");
    inorder(p);

    if(search(p)){
        printf("\n found");
    }
    else{
        printf("\n not found");
    }
    return 0;
}