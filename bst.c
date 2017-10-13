/*Description:Implementation of Binary Search Tree
 * Learner:poonawala mohd ayan ishtiaque
 * Roll no:16co44
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct bst 
{	int data;
	struct bst *left,*right;
}node;

void insert (node **r,int num)
{
	node *temp,*ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	ptr->left=NULL;
	ptr->right=NULL;
	temp=*r;
	if(temp==NULL)
	{
		*r=ptr;
	}
	else
	{
		if(num>temp->data)
		{
			if(temp->right!=NULL)
				insert(&temp->right,num);
			else
		{	
			temp->right=ptr;
		}
		}
		else
			{
			 if(temp->right!=NULL)
				insert(&temp->left,num);
			 else
				temp->left=ptr;
			}
	
	}
}	

void traverse_inorder(node *r)
{	if(r!=NULL)
	{
	traverse_inorder(r->left);
	printf("%d\t",r->data);
	traverse_inorder(r->right);
	}
}
	
int search_bst(node *r,int num)
{ 
	if(r==NULL)
		return 0;
	else
	{
		if(num==r->data)
			return 1;
		else
		{
			if(num>r->data)
			{	
				return search_bst(r->right,num);
			}
			else
			{
				return search_bst(r->left,num);
			}
		}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
	return;
	while(temp!=NULL)
	{
	    if(temp->data==num)
	   {
		*f=1;
	    *x=temp;
	    return;
	   }
	   *parent=temp;
	   if(num > temp->data)
	      temp=temp->right;
	   else
	      temp=temp->left;
	}
}
void delete(node **r,int num)
{ 
	node *temp,*parent,*x,*xsucc; //x is node top be deleted
	int f=0;
	temp=*r;
	if(temp==NULL)
	return;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{
		printf("/n the node %d is not found",num);
	 	return;
	}
	//xhas no child
	if(x->left==NULL && x->right==NULL)
	{
	    if(x->data>parent->data)
		    parent->right=NULL;
	    else
  		   parent->left=NULL;
	      

	}
	//x has left child
	else
		if(x->left!=NULL && x->right==NULL)
		{
			if(x->data>parent->data)
		    parent->right=x->left;
	        else
  		    parent->left=x->left;

		}   
	
	//x has right child
	
	else if(x->right!=NULL && x->left==NULL)
		{
			if(x->data>parent->data)
		    parent->right=x->right;
	        else
  		    parent->left=x->right;
	        
		} 
		//x has both left and right child
		else if(x->left!=NULL && x->right!=NULL)
		{
			xsucc=x->right;
			parent=x;
			while(xsucc->left!=NULL)
			{
				parent=xsucc;
				xsucc=xsucc->left;
				
			}
			x->data=xsucc->data;
			x=xsucc;
			if(x->data > parent->data)
			    parent->right=NULL;
			else 
			    parent->left=NULL;
			   
		} 
		free(x);
}		    
int main()
{
	node *root;
	root=NULL;
	int j,no;
	do
	{
		printf("\nEnter your choice\n");
		printf("\n1-Insertion\n2-Deletion\n3-Traverse\n4-searching\n5-exit\n\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				printf("\nEnter the number to be inserted: ");
				scanf("%d",&no);
				insert(&root,no);
				break;
			case 2:
				printf("\nEnter the number to be deleted: ");
				scanf("%d",&no);
				delete(&root,no);
				break;
			case 3:
				traverse_inorder(root);
				break;
			case 4:
			
				printf("\nEnter the number to be search: ");
				scanf("%d",&no);
				if(search_bst(root,no)==0)
				  printf("\nthe number is found");
				else
				printf("\nthe number is not found");
				break;
			case 5:
			exit(0);	
			default:
				printf("\nInvalid input.");
				break;
			}
		}while(1);
	return 0;
}


