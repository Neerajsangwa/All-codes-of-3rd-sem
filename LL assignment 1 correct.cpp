//LL Operations

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data ; 
    struct node *next ;
}*first = NULL;

void create ( int A[] , int n )
{
	int  i;
	struct node *t , *last;
	first = (struct node *)malloc(sizeof(struct node));
	first->data = A[0];
	first->next = NULL;
	last=first ;
	
	for ( i=1 ; i<n ; i++)
	{
		t= (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last =t;
	}	
}

void display(struct node *p)
{
	while ( p!= NULL)
	{
		printf("%d \t", p->data);
		p = p->next;
	}
}


int main ()
{
	struct node *t;
	
	int A[]={ 3,4,5,6,7,8};
	create (A , 6);
	
	display(first);
	
	return 0;
	
}
