/*Description:Implementation of Hashing
 * Learner:poonawala mohd ayan ishtiaque
 * Roll no:16co44
 */

#include<stdio.h>
#include<math.h>
#define MAX_SIZE 15
int hash(int k)
{
	return k%MAX_SIZE;
}

int linear_probe(int h)
{
	return ++h%MAX_SIZE;
}

int quadratic_probe(int h,int i)
{
	return (h+(i*i))%MAX_SIZE;
}

int double_hash(int h,int i)
{
	return (h+i*linear_probe(h))%MAX_SIZE;
}


void display(int a[])
{
	int i;
	printf("\n----Elements of array are----\n");
	for(i=0;i<MAX_SIZE;i++)
		printf("%d\t",a[i]);
}

int main()
{
	int a[MAX_SIZE],i,h,e,count,choice;
	for(i=0;i<MAX_SIZE;i++)
		a[i]=-1;
	do{
		count=0;
		printf("\nEnter the number to be stored: ");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1)
		{
			a[h]=e;
			display(a);
		}
		else
		{
			while(count<MAX_SIZE)
			{
				count++;
				printf("\nCollision occured at %d\n",h);
				printf("\nEnter\n1.Linear probe\t2.Quadratic probe\t3.Double Hashing\n");
				printf("\nEnter your choice for resolution: ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:h=linear_probe(h);
						break;
					case 2:h=quadratic_probe(h,count);
						break;
					case 3:h=double_hash(h,count);
						break;
					default:printf("\nInvalid choice");
							count--;
						break;
				}
				if(a[h]==-1)
				{
					a[h]=e;
					display(a);
					break;
				}
			}
		}
         if(count==MAX_SIZE)
		{
			printf("\nArray is full/resolution not successful...Could not store more elements\n");
			return 0;
		}
	}while(1);
}
