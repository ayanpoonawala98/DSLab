#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull()
{
	if(top==MAX_SIZE-1)
		return 1;
	else 
		return -1;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return -1;
}

int peek()
{
	return stack[top];
}

void  push(int e)
{
	if(!isFull)
	{
		top++;
		stack[top]=e;
		printf("Element e is successfully inserted\n");
	}
	else
	{
		printf("Stack overflow\n");
	}
//inserts an element into stack
}

void pop()
{
	int d;
	if(!isEmpty)
	{
		d=stack[top];
		top--;
		printf("Element d is successively deleted\n");
	}
	else{
		printf("Stack underflow\n");
	}
}

int main(){
	int choice,e;
	do
	{
		printf("Menu\n1.peek\t2.push\t3.pop\t4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:peek();
			break;
			case 2:push();
			break;
			case 3:pop();
			break;
			default 0:"Wrong choice");
		}
	}
}
			
		
