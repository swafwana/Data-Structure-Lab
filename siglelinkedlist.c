#include <stdio.h>
#include <stdlib.h>
//node structure
struct node
{
	int data;
	struct node*link;
};
struct node *header=NULL;
struct node *createnode(int data)
{
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	return(newnode);
}
void insertAtFront(int data)
{
	struct node *newnode;
	newnode=createnode(data);
	if (header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
	
}
void insertAtEnd(int data)
{
	struct node*newnode;
	newnode=createnode(data);
	if (header==NULL)
	{
		header=newnode;
	}
	else
	{
		struct node *temp = header;
       		while (temp->link != NULL) 
	{
            		temp = temp->link;
        }
        
        	temp->link = newnode;
		
		
	} 
}
void insertAtAny(int data,int position)
{
	
    	
    
    	struct node*newnode=createnode(data);
    	if (position == 0) 
	{
        newnode->link = header;  
        header = newnode;       
    	} 
	else 
	{
       		struct node *temp = header;
        	int currentPos = 0;
        	while (temp != NULL && currentPos < position - 1) 
		{
            	temp = temp->link;
            	currentPos++;
        	}
        	if (temp == NULL) 
		{
            	printf("Position is out of bounds!\n");
        	} 
		else 
		{
            
            	newnode->link = temp->link;
            	temp->link = newnode;
        	}
	}
    
}
	
	
void traversal()
{
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d \n",ptr->data);
		ptr=ptr->link;
	}
}


int main()
{
	struct node *node;
	struct node *node1;
	insertAtFront(5);
	insertAtFront(7);
	insertAtEnd(8);
	insertAtEnd(9);
	insertAtAny(4,2);
	traversal();
	return(0);
}
