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
		printf("\n Stack is full.");
	}
	else{
		ptr->top++;
		ptr->data[ptr->top] = val;
	}
}

char pop(struct stack *ptr){
	if(isEmpty(ptr)){
		printf("\n Stack is empty.");
		return -1;
	}
	else{
		char val = ptr->data[ptr->top];
		ptr->top--;
		return val;
	}
};


void postfixToInfix(char postfix[], char infix[]){
	struct stack s;
	char token,s1,s2,exp;
	init(&s);
	int j = 0;

	for(int i = 0; postfix[i]!='\0'; i++){
		token = postfix[i];

		if(isalnum(token)){
			push(&s, token);
		}
		else{
			s1 = pop(&s);
			s2 = pop(&s);
			exp = s2 + token + s1 ;
			push(&s, exp);
		}
	}        

	while(!isEmpty(&s)){
		infix[j] = pop(&s);
		j++;
	}
	infix[j] = '\0';
	printf("Infix = %s", infix);
}

int main(){
	// char postfix[MAX];
	// printf("Enter postfix expression  ");
    // scanf("%s",&postfix);

	char postfix[MAX] = "ab+";
	char infix[MAX];

	postfixToInfix(postfix, infix);
}