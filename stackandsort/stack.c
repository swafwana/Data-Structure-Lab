#include<stdio.h>
#define max 4
int stack[max];
int top=-1;
void push();
void pop();
void traversal();
int main()
{
	int choice;
	do
	{
		printf("Enter your choice\n1 for push\n2 for pop\n3 for traversal\n4 for exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
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
void push()
{
	int element;
	if (top==max-1)
	{
		printf("stack overflow");
	}
	else
	{
		
		printf("Enter a element");
		scanf("%d",&element);
		top++;
		stack[top]=element;
	}
		
	
}


void pop()
{
		int element;
	if(top==-1)
	{
		printf("stack is empty");

	}
	else
	{
		element=stack[top];
		top--;
		printf("Element deleted is %d",element);
	}
}

	
void traversal()
{
	int i;
	for(i=0;i<=top;i++)
{
		printf("%d\n",stack[i]);		
}	
}

	


		
		

