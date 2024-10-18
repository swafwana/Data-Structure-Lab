#include<stdio.h>
#include<stdlib.h>
#define max 4
int queue[max];
void enqueue();
void dequeue();
void traversal();
int front=-1;
int rear=-1;
int item;
int main()
{
	int choice;
	do
	{
		printf("Enter your choice\n1 for Inserting an element\n2 for deleting an element\n3 for displaying all elements\n4 for exit");
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
}
void enqueue()
{
	
	if (rear==max-1)
		printf("The queue is full");
	else
	{
		if (front==-1)
			front=0;
		printf("Enter the item to be inserted");
		scanf("%d",&item);
		
		rear=rear+1;
		queue[rear]=item;
		
	}
}
void dequeue()
{
	int element;
	if (front==-1)
		printf("The queue is empty");
	else
	{
		element=queue[front];
		front=front-1;
		printf("The item deleted is %d",element); 
	}
}
void traversal()
{ 
	int i;
	if (front==-1)
		printf("The queue is empty");
	else
	{
		for(i=0;i<=rear;i++)
		{
			printf("%d",queue[i]);
		}
	}
}
 


		

