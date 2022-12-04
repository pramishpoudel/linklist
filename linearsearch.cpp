//linear search
#include<stdio.h>
#include<stdlib.h>

int linearsearch(int arr[],int size,int target)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==target)
		return i;
	}
	
	return -1;
}

int main()
{
	int num;
	int arr[10];
	int target;
	printf("enter the number of element in the array\n");
	scanf("%d",&num);
	
	printf("enter the element that is inserted\n");
	for(int i=0;i<num;i++)
	{
	 scanf("%d",&arr[i]);
	}
	
	printf("enter the desired element\n");
	scanf("%d",&target);
	
	int index = linearsearch(arr,num,target);
	
	if(index==-1)
	printf("element is not found in the list");
	else
	printf("targeted element is %d lies in %d",target,index); //indexing is started form 0
	return 0;
	
}
