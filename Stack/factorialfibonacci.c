# include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
int s[50];
int top = -1;


// struct stack{
// 	char data[MAX];
// 	int top;
// };

// void init(struct stack *s){
// 	s->top = -1;
// }

int top1(){
	return s[top];
}

int isEmpty(){
	if(top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){
	if(top == MAX - 1){
		return 1;
	}
	else{
		return 0;
	}
}

void push( char val){
	if(isFull()){
		printf("The stack is already full.");
	}
	else{
		top++;
		s[top] = val;
	}
}

char pop(){
	if(isEmpty()){
		printf("Stack is already empty.");
		return -1;
	}
	else{
		char val = s[top];
		top--;
		return val;
	}
};

int factorial(int n){
    int i;
    push(1);
    for(i=2;i<=n;i++){
        push(top1() * i);
    }

    printf("\nFactorial: %d", top1());
}

int fibonacci(int n){
    int i;
    push(1);
    push(1);
    for(i=3;i<=n;i++){
        push(top1() + i);
    }
    printf("\nFibonacci: %d", top1());
}

int main(){
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    factorial(n);
    fibonacci(n);

    return 0;
}