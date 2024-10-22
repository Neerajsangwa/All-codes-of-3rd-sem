#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
	struct Node *first=NULL;
void create(int A[],int n)
{
	int i;
	struct Node *t, *last;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first; 			//creation of first node done
	
	for(i=1;i<n;i++)		//create of next nodes 
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
void display(struct Node *p)		// Display of Nodes 
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void insertfirstnode(struct Node *p,int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	t->next=first;
	first=t;
}
void insertgivenposition(struct Node *p,int pos,int x)
{
	struct Node *t;
	int i;
	t=(struct Node*)malloc(sizeof(struct Node));
	p=first;
	
	for(i=0;i<pos-1&&pos;i++)
	{
		p=p->next;
	}
	if(pos)
	{
			
		t->data=x;
		t->next=p->next;
		p->next=t;
	}
	
}
void insertlast(int x)
{
	Node *last=first;
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=last=t;
	}
	else
	{
		while(last->next!=NULL)
		{
		last=last->next;
		}
		last->next=t;
	}
}


int main()
{
	struct Node;
	int n,i,a,b,c,d;
	int A[n];
	printf("Enter no of Nodes ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d Element = ",i+1);
		scanf("%d",&A[i]);
	}
	create (A,n);
	display(first);
	printf("Enter a value for Insertion Before first Node = ");
	scanf("%d",&a);
	insertfirstnode(first,a);
	printf("After Insertion Before first Node = ");
	display(first);
	printf("Enter a value and position for Insertion at given Node  = ");
	scanf("%d%d",&b,&c);
	printf("After Insertion on any Node = ");
	insertgivenposition(first,c,b);
	display(first);
	printf("Enter a value for Insertion from last = ");
	scanf("%d",&d);
	insertlast(d);
	printf("After Insertion on last Node = ");
	display(first);
	
	display(first);
	return 0;
}
