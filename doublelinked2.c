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
	newnode=(struct node *)malloc(sizeof(struct node));
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
	struct node* ptr = header;
	if (position == 0) 
	{
		newnode->rlink = header;
		header = newnode;
		
	}
	
	
	
	for (int i = 0; i < position - 1 && ptr != NULL; i++) 
	{

        	ptr = ptr->rlink;
	}
	if (ptr == NULL) 
	{
		printf("Position out of bounds.\n");
		free(newnode);
	} 
	else 
	{
		newnode->rlink = ptr->rlink;
		ptr->rlink= newnode;
	}
	

}
void insertAtAny(int key,int value)
{
	printf("NOthing to say");
}
void deleteAtFront()
{
	if (header == NULL)
	{
		printf("The list is empty.\n");
		
	}
	
	struct node* ptr;
	ptr=header;
	header=header->rlink;
	free(ptr);
}
void deleteAtEnd()
{
	if (header == NULL) 
	{
		printf("The list is empty.\n");
		
	}
	
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
void deleteAtAny(int position)
{
	
	if (header == NULL) 
	{
		printf("The list is empty.\n");
		
	}
	struct node* ptr= header;
	struct node* ptr1= NULL;
	if (position == 0) 
	{
		header = header->rlink;
		free(ptr);
		printf("Node deleted from position 0.\n");
		
	}
	for (int i = 0; i < position && ptr != NULL; i++) 
	{
		ptr1 = ptr;
		ptr = ptr->rlink;
	}
	if (ptr == NULL)
	{
		printf("Position out of bounds.\n");
	} 
	else 
	{
		ptr1->rlink= ptr->rlink;
		free(ptr);
		printf("Node deleted from position %d.\n", position);
	}
}
void deleteAtAny(value)
{
	printf("Nothing more nothing less");
}
	
void traversal()
{
	struct node* ptr = header;
	if (header == NULL) 
	{
		printf("The list is empty.\n");
	}
	else 
	{
		printf("The linked list is: ");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->rlink;
		}
	}

}
void search(int value)
{
	if (header == NULL) 
	{
		printf("The list is empty.\n");
		
	}
	else
	{
		struct node* ptr = header;
		int position = 0;
		while (ptr != NULL) 
		{
			if (ptr->data == value) 
			{
				printf("Value %d found at position %d.\n", value, position);
				
			}
			ptr = ptr->rlink;
			position++;
		}
		printf("Value %d not found in the list.\n", value);
	}
}


int main ()
{
	int choice, data, position, value;
	while (1) 
	{
		printf("\nMenu:\n");
		printf("1. Insert at the Front\n");
		printf("2. Insert at the End\n");
		printf("3. Insert at a Specific Position\n");
		printf("4. Delete from the Front\n");
		printf("5. Delete from the End\n");
		printf("6. Delete from a Specific Position\n");
		printf("7. Search for a Value\n");
		printf("8. Display the List\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1:
			printf("Enter the data to insert at the front: ");
			scanf("%d", &data);
			insertAtFront(data);
			break;
		case 2:
			printf("Enter the data to insert at the end: ");
			scanf("%d", &data);
			insertAtEnd(data);
			break;
		case 3:
			printf("Enter the data to insert: ");
			scanf("%d", &data);
			printf("Enter the position to insert at: ");
			scanf("%d", &position);
			insertAtAny(key, value);
			break;
		case 4:
			deleteAtFront();
			break;
		case 5:
			deleteAtEnd();
			break;
		case 6:
			printf("Enter the position to delete from: ");
			scanf("%d", &position);
			deleteAtAny(value);
			break;
		case 7:
			printf("Enter the value to search for: ");
			scanf("%d", &value);
			search(value);
			break;
		case 8:
			
			traversal();
			break;
		case 9:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
	return(0);
}
 

