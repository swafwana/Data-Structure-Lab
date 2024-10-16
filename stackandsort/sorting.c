#include<stdio.h>

void sort(int ary[],int lim);
void display(int ary[],int lim);
void merge(int ary1[],int lim1,int ary2[],int lim2); 
int ary1[10],ary2[10],mergeary[20],lim1,lim2;

		

	
		


int main ()
{

	int i,j,temp,lim3;
	printf("Enter the limit of first array");
	scanf("%d",&lim1);
	printf("Enter the elements of array");
	for (i=0;i<lim1;i++)
	{

		
		scanf("%d",&ary1[i]);
	}
	printf("Unsorted first array is\n");
	for(i=0;i<lim1;i++)
	{
		printf("%d ",ary1[i]);
	}
	
	printf("Enter the limit of second array");
	scanf("%d",&lim2);
	printf("Enter the elements of array");
	for (i=0;i<lim2;i++)
	{
		
		scanf("%d",&ary2[i]);
	}
	printf("Unsorted second array is\n");
	for(i=0;i<lim2;i++)
	{
		printf("%d ",ary2[i]);
	}

	
	printf("Sorted first array is\n");
	sort(ary1,lim1);
	display(ary1,lim1);
	printf("Sorted second array is\n");
	sort(ary2,lim2);
	display(ary2,lim2);
	lim3=lim1+lim2;

	printf("Merged array is\n");
	merge(ary1,lim1,ary2,lim2);
	display(mergeary,lim1+lim2);
	printf("Sorted merged array is");
	sort(mergeary,lim3);
	display(mergeary,lim3);

}
	
void sort(int ary[],int lim)
{	
int i,j,temp;

for(i=0;i<lim-1;i++)
{
	for(j=i+1;j<lim;j++)
	{
		if(ary[i]>ary[j])
		{
			temp=ary[i];
			ary[i]=ary[j];
			ary[j]=temp;
		}
	}
}
}
void merge(int ary1[],int lim1,int ary2[],int lim2)
{
	int i,j;
	
	for (i=0;i<lim1;i++)
	{
		mergeary[i]=ary1[i];
	}
	for (i=0;i<lim2;i++)
	{
		mergeary[lim1+i]=ary2[i];
	}
}
void display(int ary[],int lim)
{
int i;
for(i=0;i<lim;i++)
	printf("%d ",ary[i]);
}



	

	
	


	

