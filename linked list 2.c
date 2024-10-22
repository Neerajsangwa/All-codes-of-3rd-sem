#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data ;
	struct node *next;
} *first = NULL;

void create ( int A[] , int n)
{
	int i;
	struct node *t , *last ;
	first = (struct node *)malloc(sizeof(struct node));
	first->data = A[0];
	first->next = NULL;
	last= first;
	
	for ( i=1 ; i<n ; i++)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
	
}

void display (struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n\n");
}

int count(struct node *p)
{
  int l=0;
  while(p)
  {
  	l++;
  	p=p->next;
  }
  return l;
	
}

void insert ( struct node *p , int index , int x)
{
	struct node *t ;
	int i;
	if(index <0 || index >count(p))
		return;
	t=(struct node*)malloc(sizeof(struct node));
	t->data = x;
	
	if(index == 0)
	{
		t->next = first;
		first = t;
	}
	else 
	{
		for (i=0 ; i<index-1 ; i++)
	    p = p->next ;
	    t->next = p->next ;
	    p->next =t;
	}
}

int main()
{
	struct node *temp;
	int A[]={1,3,4,5,6,7};
	create(A,6);
	display(first);
	insert(first,0,50);
	insert(first,4,40);
	insert(first,count(first),80);
	display(first);
	printf("\n Count : %d .",count(first));
	return 0;
	
}
