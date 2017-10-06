/*Description:Implementation of Binary Search
 * Learner:poonawala mohd ayan ishtiaque
 * Roll no:16co44
 */

#include<stdio.h>
#define MAX 100

int binary_search(int a[],int num,int n)
{
	int mid,low=0,high=n-1;
	while(low<=high)
	{  
		mid=(low+high)/2;
		if(a[mid]==num)
		return mid;
		else
		{
			if(num>a[mid])
			low=mid+1;
			else
			high=mid-1;
		}
	}
	return -1;
}

int main()
{
	int a[MAX],num,n,i,index;
	printf("enter the size of an array");
	scanf("%d",&n);
    if(n<0||n>100)
    { 
		 printf("ARRAY INDEX OUT OF BOND");
		 return 0;
	}
		printf("enter the no of array");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the no: ");
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched: ");
	scanf("%d",&num);
	index=binary_search(a,num,n);
	if(index==-1)
		printf("\nElement %d is not found\n",num);
	else
		printf("The element %d is at index %d",num,index);
	return 0;
}
