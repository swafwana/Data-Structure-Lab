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
		struct node *ptr = header;
       		while (ptr->link != NULL) 
	{
            		ptr = ptr->link;
        }
        
        	ptr->link = newnode;
		
		
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
				insertAtFront(int data);
				break;
			case 2:
				insertAtEnd(int data);
				break;
			case 3:
				void insertAtAny(int data,int position);
				break;
			case 4:
				deleteAtFront();
				break;
			case 5:
				void deleteAtEnd();
				break;
			case 6:
				traversal();
				break;
			case 7:
				exit;
				break;
			oid deleteAtEnd()
			default:
				printf("Wrong Choice");
				
		}
	}
	while (choice!=4);
	return(0);
	
	insertAtFront(8);
	insertAtFront(5);
	insertAtFront(7);
	insertAtEnd(2);
	insertAtAny(1);
	printf("Inserted elements are:");
	traversal();
	deleteAtFront();
	printf("Elements after deletion at front:");
	traversal();
	deleteAtEnd();
	printf("Elements after deletion at End:");
	traversal();
}
	


































