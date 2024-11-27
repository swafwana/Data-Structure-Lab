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
		{
			ptr=ptr->rlink;
		}
	
		ptr->rlink=newnode;
		newnode->llink=ptr;
	}
}
void insertAtAny(int data,int position)
{
	struct node* newnode;
	newnode=create_node(data);
	struct node* temp = header;
	for (int i = 0; i < position - 1 && temp != NULL; i++) 
	{

        	temp = temp->rlink;
	}
	
	newnode->rlink = temp->rlink;
	temp->rlink= newnode;

	

}
void deleteAtFront()
{
	struct node* ptr;
	ptr=header;
	header=header->rlink;
	free(ptr);
}
void deleteAtEnd()
{
	struct node* ptr;
	struct node* ptr1;
	ptr=header;
	while(ptr->rlink!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->rlink;
	}
	ptr1->rlink=NULL;
	free(ptr);
}
	
void traversal()
{
	struct node* ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->rlink;
	}
}
int main (){
	insertAtFront(8);
	insertAtFront(5);
	insertAtFront(4);
	insertAtEnd(9);
	insertAtAny(7,3);
	insertAtEnd(6);
	deleteAtFront();
	deleteAtEnd();
	traversal();
	return(0);
}


