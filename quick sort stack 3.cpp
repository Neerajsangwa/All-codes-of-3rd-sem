#include<stdio.h>
void swap(int *c,int *b)
{
	int temp=*c;
	*c=*b;
	*b=temp;
}
int partition(int a[],int lb,int ub) //for partition of array into 2 parts
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
			swap(&a[start],&a[end]);
	}
	swap(&a[lb],&a[end]);
	return end;		//for further sorting,now we have 2 partition,weneed to sort both of them one from lb to end and another from end to ub...
}
void quicksort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int loc=partition(a,lb,ub);	
		quicksort(a,lb,loc-1);//for lb to end,perform quicksort
		quicksort(a,loc+1,ub);//for end to ub,perform quicksort
	}
}

int main()
{
	int n ,i;
	printf("Enter the size of array :");
	scanf("%d",&n);
	
	int a[n];
	
	for (  i=0; i<n ; i++)
	{
		printf("Enter the %d element of array : ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf(" Your entered array : ");
	for (  i=0 ; i<n ; i++)
	{
		printf("\t");
		printf("%d",a[i]);
	}
	
	quicksort ( a , 0 , n-1);
	
	printf("\n Sorted array : ");
	for (  i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	
	return 0;
}

