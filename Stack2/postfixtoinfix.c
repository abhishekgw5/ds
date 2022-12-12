# include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50


struct stack{
	char data[MAX];
	int top;
};

void init(struct stack *s){
	s->top = -1;
}

int top(struct stack *s){
	return s->data[s->top];
}

int isEmpty(struct stack *s){
	if(s->top == -1){
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
		printf("The stack is already full.");
	}
	else{
		ptr->top++;
		ptr->data[ptr->top] = val;
	}
}

char pop(struct stack *ptr){
	if(isEmpty(ptr)){
		printf("Stack is already empty.");
		return -1;
	}
	else{
		char val = ptr->data[ptr->top];
		ptr->top--;
		return val;
	}
};


void postfixtoinfix( char postfix[], char infix[]){
    strrev(postfix);
    struct stack s;
    char token;
    int j = 0;
    init(&s);

    for(int i =0; postfix[i]!='\0';i++){
        token = postfix[i];

        if(isalnum(token)){
    		infix[j++] = token;
			if(!isEmpty(&s)){
				infix[j++] = pop(&s);
			}
            
        }
        else{
            push(&s,token);
        }
    }

    while(!isEmpty(&s)){
        infix[j] = pop(&s);
        j++;
    }
    
    infix[j] = '\0';
    strrev(infix);
    printf(" Infix = %s", infix);
}

int main(){
    char postfix[MAX];
    printf("Enter postfix expression  ");
    scanf("%s",&postfix);
	
	char infix[MAX];
	
	postfixtoinfix(postfix,infix);
	
}
