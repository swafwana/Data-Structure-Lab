


#include<stdio.h>
#include<stdlib.h>
#define max 4
int cqueue[max];
void enqueue();
void dequeue();
void traversal();
int front=-1;
int rear=-1;


int main()
{
	printf("Enter your choice\n1 for Inserting an element\n2 for deleting an element\n3 for displaying all elements\n4 for exit");
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
}
void enqueue()
{ 
	int item;
	int next;
	if (front==-1)
	{
		printf("Enter item to be inserted");
		scanf("%d",&item);
		front=0;
		rear=0;
		cqueue[rear]=item;
	}
	else
	{
		next=(rear+1)%max;
		
		if (next!=front)
		{
			printf("Enter item to be inserted");
			scanf("%d",&item);
			rear=next;
			cqueue[rear]=item;
			
		}
		else
			printf("circular queue is full");
	}
}
void dequeue()
{
	int item;
	if (front==-1)
		printf("The queue is empty");
	else
	{	
		item=cqueue[front];
		if(front==0&&rear==0)
		{
			front=-1;
			rear=-1;
			printf("The item deleted is %d",item);
		}
		else
		{
			front=(front+1)%max;
			printf("The item deleted is %d",item);
		}
	}
}
void traversal()
{ 
	int i;
	if (front==-1)
		printf("The queue is empty");
	else
	{
		for (i=front;i<=rear;i++)   
			printf(" %d\n",cqueue[i]); 
	}
}
		/*if(rear>=front)
			{
				printf("\nElements in Queue :");
				for (i=front;i<=rear;i++)   
					printf(" %d\n",cqueue[i]);  
			}
		else
	  		{
				printf("\nElements in Queue :\n");
				for (i=front;i<=max-1;i++)   
					printf(" %d\n",cqueue[i]); 
				for (i=0;i<=rear;i++)   
					printf(" %d\n",cqueue[i]); 
			}
	}*/
		
	
//}

