#include<stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE],front=-1,rear=-1;
int isFull()
{
	if((rear==MAX_SIZE-1&&front==0)||rear+1==front)
		return 1;
	else 
		return 0;
}

int isEmpty()
{
	if(front==-1&&rear==-1)
		return 1;
	else
		return 0;
}

void display()
{int i=front;
	printf("the	element of queue are");
			
	while(i!=rear)																												
	{	
		printf("%d\n",queue[i]);
		i=(i+1)%MAX_SIZE;	
	}
	printf("%d",queue[i]);
}
	
void insert(int d)
{
	if(!isFull())
	{	
		if(isEmpty())
		{
			front++;
		}
		rear++;
		queue[rear]=d;
		printf("%d elememt is successfully inserted\n",d);
	}
	else
	printf("the queue is full,%d element cannot be inserted",d);
}
void delete()
{ int d;
	if(!isEmpty())
	{ d=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX_SIZE;
		}
		printf("the element deleted is %d",d);
	}
	else
	printf("the queue is empty");
}
	
		







int main()
{
		int choice,e;
	do
	{
		printf("Menu\n1.display\t2.insert\t3.delete\t4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			if(!isEmpty())
			display();
			else
			printf("the queue is empty\n ");
			break;
			case 2:printf("enter the element to be inserted");
			scanf("%d",&e);
			insert(e);
			break;
			case 3:delete();
			break;
			default :printf("Wrong choice");
			break;
		}
	}while(1);
	return 0;
}
			
		

