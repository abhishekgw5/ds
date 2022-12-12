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
	if(ptr->top == MAX-1){
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

int priority(char x){
	if(x=='('){
		return 0;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
	else if(x=='%'){
		return 3;
	}
	else if(x=='^'){
		return 4;
	}
	else{
		return -1;
	}
}

void infixToprefix(char infix[], char prefix[]){
    strrev(infix);
	struct stack s;
	char x, token;
	init(&s);
    int j = 0;
	
	for(int i=0; infix[i]!='\0'; i++){
		token = infix[i];
		
		if(isalnum(token)){
			prefix[j++] = token;
		}

		else if(token == '('){
			push(&s, token);
		}

		else if(token == ')'){
			while(pop(&s) != '('){
				prefix[j++]=pop(&s);
			}
		}
        
		else{
			while(priority(token)<=priority(top(&s)) && !isEmpty(&s))
				prefix[j++] = pop(&s);
			push(&s, token);
			
		}
	}
	while(!isEmpty(&s)){
		prefix[j] = pop(&s);
        j++;
	}
	prefix[j]='\0';
    printf(" Prefix Expression = %s", strrev(prefix));
}

int main(){
	char infix[10];
    printf("Enter infix expression  ");
    scanf("%s",&infix);
    // printf("%s \n", strrev(infix));
	char prefix[10];
	
	infixToprefix(infix, prefix);
	
}