#include <stdio.h>
int main()
{
	int array[10],i,sum=0,n;
	printf("Enter the no of elements");
	scanf("%d",&n);
	printf("Enter the elements of array");
	for (i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	for(i=0;i<n;i++)
	{
		sum=sum+array[i];
	}
	printf("%d",sum);
	return(0);
}

