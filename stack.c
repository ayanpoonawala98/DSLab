#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull()
{
	return top==MAX_SIZE-1;
}

int isEmpty()
{
	return top==-1;
}

int peek()
{
	return stack[top];
}

void  push(int e)
{
	if(!isFull())
	{
		top++;
		stack[top]=e;
		printf("Element %d is successfully inserted\n",e);
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
	if(!isEmpty())
	{
		d=stack[top];
		top--;
		printf("Element %d is successively deleted\n",d);
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
			case 2:printf("\nEnter the element to be inserted: ");
				scanf("%d",&e);
			    push(e);
			break;
			case 3:pop();
			break;
			default:printf("\nWrong choice\n");
				break;
		}
	}while(1);
	return 0;

}
			
		
