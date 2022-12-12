#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf("stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int isoperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

char *infixtopostfix(char *infix){
    // char s[10];
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(struct stack));
    // char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0;
    int j = 0;

    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            push(sp,infix[i]);
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                pop(sp);
            }
        }
    }
    while(!isEmpty(sp)){
        printf("%c", pop(sp));
    }
    
    
}

int main(){
    char * infix = "x+y-z";
    infixtopostfix(infix);
    return 0;
}