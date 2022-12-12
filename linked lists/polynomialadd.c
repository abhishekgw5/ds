#include <stdio.h>
#include <stdlib.h>

struct node{
    int power;
    int coeff;
    struct node *next;
};

void create(struct node **poly){
    int flag; 
    int coeff, power;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    *poly = temp;
    do{
        printf("\n Enter coefficient");
        scanf("%d", &coeff);
        temp->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &power);
        temp->power = power;

        temp->next = NULL;

        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);

        if(flag){
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }while(flag);
}

void show(struct node * poly){
    printf("\nThe polynomial expression is:\n");
    while(poly!=NULL){
        printf("%dx^%d", poly->coeff, poly->power);
        poly=poly->next;
        if(poly!=NULL){
            printf(" + ");
        }
    }
}

void add(struct node **result, struct node *poly1, struct node *poly2){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    *result = temp;

    while(poly1 && poly2){
        if(poly1->power > poly2->power){
            temp->power = poly1->power;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if(poly2->power > poly1->power){
            temp->power = poly2->power;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else{
            temp->power = poly1->power;
            temp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if(poly1 && poly2){
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main(){

    struct node *poly1, *poly2, *poly3;

    printf("\nCreate 1st expression\n");
    create(&poly1);
    show(poly1);

    printf("\nCreate 2nd expression\n");
    create(&poly2);
    show(poly2);

    add(&poly3, poly1, poly2);
    show(poly3);

    return 0;
}