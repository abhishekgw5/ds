#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct stack{
    int top;
    char data[MAX];
};

void init(struct stack *s){
	s->top = -1;
}

int top(struct stack *s){
	return s->data[s->top];
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
    if(ptr->top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->data[ptr->top] = val;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow");
        return -1;
    }
    else{
        char val = ptr->data[ptr->top];
        ptr->top--;
        return val;
    }
}

int pmatch(char infix[]){

    struct stack s;
    init(&s);

    for(int i = 0; infix[i]!='\0'; i++){
        if(infix[i]=='('){
            push(&s, '(');
        }
        else if(infix[i]==')'){
            if(isEmpty(&s)){
                return 0;
            }
            pop(&s);
        }
    }

    if(isEmpty(&s)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char infix[MAX];
    printf("Enter infix expression  ");
    scanf("%s",&infix);
   

    if(pmatch(infix)){
        printf("Parenthesis matches");
    }
    else{
        printf("Parenthesis not matches");
    }
    return 0;
}