#include<stdio.h>
#include<stdlib.h>
 
typedef struct linked_list 
{
	int data;
	struct linked_list *next;
}node;

void print(node *q)
{
	node *ptr;
	ptr=q;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

void insbeg(node **q,int no)
{
node *temp,*ptr;
temp=*q;
ptr=(node*)malloc(sizeof(node));
ptr->next=NULL;
if(temp==NULL)
else
ptr->next=temp;
*q=ptr;
printf("\n ELEMENT OF LINKLIST AFTER INSERTION\n");
printf(*q);
}

void insend(node **q,int no)
{
	node *ptr,*temp;
	ptr=(node*)malloc(sixeof(node));
	ptr->data=no;
	ptr->next=NULL;
	temp=*q;
	if(temp==NULL)
	*q=ptr;
	else
	{
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=ptr;
	}
	printf("\nELEMENT OF LINKLIST AFTER INSERTION\n");
	printf(*q);
}

void insafter(node *q,int no)
{
	int loc,k;
	node *temp,*ptr,*old;
	temp=q;
	ptr=(node*)malloc(sizeof(node*));
	ptr->data=no;
	printf("ENTER LOCATION WHERE THE NO IS TO BE INSERTED-> ");
	scanf("%d",&loc);
	for(k=1;k<loc;k++)
	{
		if(temp==NULL)
		printf("\nELEMENT ARE LESS THAN PROVIDED LOCATION\n");
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	ptr->next=temp;
	old->next=ptr;
	printf("\nELEMENTS OF LINKEDLIST AFTER INSERTION\n");
	printf(q);
}
void del(node **q,int no)
{
	int f=0;
	node *old,*temp;
	temp=*q;
	
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			f=1;
			if(temp==*q)
			*q=temp->next;
			else
			old->next=temp->next;
			free(temp);
			break;
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	
	if(f==0)
	printf("\nENTER THE GIVEN NUMBER IS NOT FOUND\n");
	printf("\nELEMENT OF LINKLIST AFTER DELETION\n");
	print(*q);
}

void traverse(node *q)
{
	printf("\nTRAVERSING LINKLIST\n\n");
	printf(q);
	printf("\n\nE#ND OF LINKLIST\n");
}

int main()
{
	node *start ,*ptr,*temp;
	int i,n,j,no,c;
	printf("ENTER THE NUMBER OF NODES->");
	scanf("%d",&n);
	printf("\nENTER NODE NUMBER 1->");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\nENTER NODE NUMBER %d->",i+1);
		scanf("%d",&ptr->data);
		temp->next=ptr;
		temp=ptr;
		temp=temp->next;
	}
	temp->next=NULL;
	do{
		printf("\nENTER YOUR CHOICE\n");
		printf("\n1-INSERTION");
		printf("\n2-DELETION");
		printf("\n3-TRAVERSE");
		printf("\n4-EXIT\n\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
					printf("\nENTER THE NUMBER TO BE INSE#RTED-> ");
					scanf("%d",&no);
					printf("\n ENTER 1 TO INSERT AT THE BEGINNING\nENTER 2 TO INSERT AT THE END\nENTER 3 TO INSERT AT THE SPECIFIED LOACTION\n");
					scanf("%d",&c);
					switch(c)
					{
						case 1:
						insbeg(&start,no);
						break;
						case 2:
						insend(&start,no);
						break;
						case 3:
						insafter(start,no);
						break;
						default:
						printf("\nINVALID CHOICE.");
						break;
					}
					break;
					case 2:
					printf("\nENTER THE NUMBEWR TO BE DELETED->");
					scanf("%d",&no);
					del(&start,no);
					break;
					case 3:
					traverse(start);
					break;
					case 4:
					exit(0);
					default:
					print("\nINVALID INPUT.");
					break;
				}
			}while(1);
			return 0;
		}
		
	}
			
