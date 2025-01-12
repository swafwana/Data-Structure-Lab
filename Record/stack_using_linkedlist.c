#include <stdio.h>
#include <stdlib.h>
int size=0;
int maxsize=6; 
struct node
{
	int data;
	struct node* link;
};
struct node* top=NULL;
int isEmpty()
{
	return size==0;
}
int isFull()
{
	return size==maxsize;
}
struct node* create_node(int data)
{
	struct node *newnode;
    	newnode = (struct node*)malloc(sizeof(struct node));
   	newnode->data = data;
   	newnode->link = NULL;
  	return newnode;
}
void push(int data)
{
	if (isFull())
	{
		printf("Stack Overflow cannot push %d\n",data);
		return;
	}
	struct node* newnode = create_node(data);
	newnode->data = data;
	newnode->link = top;
	top = newnode;
	size=size+1;
	printf("Pushed %d onto stack\n",data);

}
int pop ()
{
	if (isEmpty())
	{
		printf("Stack Underflow\n");
		return 0;
	}
	int poppedValue = top->data;
    	struct node* temp = top;
    	top = top->link;
    	free(temp);
	size=size-1;
    	return poppedValue;
	
}
void traversal() 
{
	if (top == NULL) 
	{
       		printf("Stack is empty\n");
        	return;
    	}
    	struct node* current = top;
   	printf("Stack elements: ");
    	while (current != NULL) 
	{
        	printf("%d ", current->data);
        	current = current->link;
    	}
	printf("\n");
}
int main() 
{
    	int choice, value;
	while (1) 
	{
        	printf("\n*** Stack Menu ***\n");
       	 	printf("1. Push\n");
        	printf("2. Pop\n");
        	printf("3. Display\n");
        	printf("4. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);

        	switch (choice) 
		{
            	case 1:
                	printf("Enter value to push: ");
                	scanf("%d", &value);
                	push(value);
                	break;

            	case 2:
                	value = pop();
                	if (value != -1) 
			{
                    	printf("Popped value: %d\n", value);
                	}
                	break;

            	case 3:
                	traversal();
                	break;
		case 4:
                	printf("Exiting program.\n");
                	return 0;
		default:
                	printf("Invalid choice! Please try again.\n");
        	}
    	}
	return 0;
}