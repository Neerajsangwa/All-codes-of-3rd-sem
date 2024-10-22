#include<stdio.h>
void swap(int *c ,int *b)
{
	int temp = *c;
	*c = *b;
	*b = temp;
}
int partition(int a[] ,int lb ,int ub)
{
	int pivot = a[lb];
	int start = lb;
	int end = ub;
	
	while ( start < end)
	{
		while (a[start]<= pivot && start < ub)
		{
			start ++;
		}
		while (a[end]>pivot)
		{
			end--;
		}
		if (start < end)
		{
		swap (&a[start],&a[end]);
	    }
		
	}
	swap ( &a[lb] , &a[end]);
	return end;
}
	void quicksort(int a[] , int lb , int ub)
	{
		
		if ( lb<ub)
		
		{
			int loc  = partition ( a, lb , ub);
			quicksort ( a , lb , loc-1);
			quicksort( a , loc+1 , ub);
			
		}
}


int main()
{
	int n ,i;
	printf("Enter the size of array :");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array : ");
	for (  i=0; i<n ; i++)
	{
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
		printf("\t");
		printf("%d",a[i]);
	}
	return 0;
}
