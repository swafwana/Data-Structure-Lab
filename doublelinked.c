#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* llink;
	struct node* rlink;
};
struct node* header=NULL;
struct node *newnode;
struct node* create_node(int data)

{
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->llink=NULL;
	newnode->rlink=NULL;
	return(newnode);
}
void insertAtFront(int data)
{
	
	if (header==NULL)
	{
		newnode=create_node(data);
		header=newnode;
	}
	else
	{
		newnode=create_node(data);
		newnode->rlink=header;
		header->llink=newnode;
		
		header=newnode;
	}
}
void insertAtEnd(int data)
{
	struct node* ptr;
	ptr=header;
	if (header==NULL)
	{
		newnode=create_node(data);
		header=newnode;
	}
	else
	{
		newnode=create_node(data);
		while(ptr->rlink!=NULL)
	
		ptr->rlink=newnode;
		header->llink=ptr;
	}
}
	
void traversal()
{
	struct node* ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->rlink;
	}
}
int main (){
	insertAtFront(8);
	insertAtFront(5);
	insertAtFront(4);
	insertAtEnd(9);
	insertAtEnd(6);
	traversal();
	return(0);
}


