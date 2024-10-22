//Stack operations using LL 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int top;
	int data;
	struct Node*next;
	
};
struct Node* top=NULL;

void push()
{	
	int x;
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	
	if(t==NULL)
	printf("Stack is full\n");
	else
	{
		printf("Enter value to push=");
		scanf("%d",&x);
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop()
{
	struct Node*t;
	int x=-1;
	if(top==NULL)
	printf("Stack is empty\n");
	else
	{
		t=top;
		top=top->next;
		x=t->data;
		
	}
	return x;
}

void display()
{
	struct Node*p=top;
	if(p==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	push();
	push();
	push();
	
	display();
	
	printf("Poppeed: %d ",pop());
	
	return 0;
}

