/*Description:Implementation of Quick Sort
 * Learner:poonawala mohd ayan ishtiaque
 * Roll no:16co44
 */

#include<stdio.h>
#define MAX 100


int split(int c[],int lower,int upper)
{
	int temp,pivot=lower,a=lower+1,b=upper;
	while(b>=a)
	{
		while(c[a]<c[pivot])
		a++;
		while(c[b]>c[pivot])
		b--;
		if(b>a)
		{
			temp=c[a];
			c[a]=c[b];
			c[b]=temp;
		}
	}
	temp=c[b];
	c[b]=c[pivot];
	c[pivot]=temp;
	return b;
}

void quick_sort(int a[],int lower,int upper)
{
	int i;
	if(lower<upper)
	{
		i=split(a,lower,upper);
		quick_sort(a,lower,i-1);
		quick_sort(a,i+1,upper);
	} 

}
	

int main()
{
	int a[MAX],i,n;
	printf("\nEnter the size of array: ");
	scanf("%d",&n);
	if(n<0||n>100)
    { 
	 printf("ARRAY INDEX OUT OF BOND");
	 return 0;
		}
	printf("\nEnter the elements of array\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the no: ");
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nThe sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}


