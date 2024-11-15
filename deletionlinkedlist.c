#include <stdio.h>
#include <stdlib.h>
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
void deleteAtFront(){
	struct node *ptr;
	
	if (header==NULL){
		printf("The linked list is empty");
	}
	else
	{
		ptr=header;
		header=header->link;
		free (ptr);
	}
}
void deleteAtEnd(){
	struct node *ptr,*ptr1;
	if (header==NULL){
		printf("The linked list is empty");
	}
	else
	{
		ptr=header;
		while(ptr->link!=NULL)
		{
		ptr1=ptr;
		ptr=ptr->link;
		}
		ptr1->link=NULL;
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
int main(){
	printf("Enter your choice\n1 for Inserting an element at front\n2 for deleting an element at end\n3 for inserting element at any\n4 for deleting element at front \n5 deleting an element at front \n6 deleting an element at end \n7 deleting an element at any \n8 Exit");
	int choice;
	do
	{
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				traversal();
				break;
			case 4:
				printf("You have exited the programme");
				break;

			default:
				printf("Wrong Choice");
				
		}
	}
	while (choice!=4);
	return(0);
	
	insertAtFront(8);
	insertAtFront(5);
	insertAtFront(7);
	printf("Inserted elements are:");
	traversal();
	deleteAtFront();
	printf("Elements after deletion at front:");
	traversal();
	deleteAtEnd();
	printf("Elements after deletion at End:");
	traversal();
}
	


































