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


    printf("Level Order Traversal of Tree is \n");	
    int i;
    int height = heightoftree(p);
    printf(" Height of the tree is %d \n",height);
    for(i = 1; i <= height; i++)      
    {
        currentlevel(p,i);
        printf("\n");
    }
    heightoftree(p);
}
