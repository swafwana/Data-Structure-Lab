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


int main()
{
	struct node *node;
	struct node *node1;
	insertAtFront(5);
	insertAtFront(7);
	return(0);
}
