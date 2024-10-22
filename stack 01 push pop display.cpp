#include<stdio.h>
#include<stdlib.h>

struct Stack 
{
	int size;
	int top;
	int *S;
};

void create(struct Stack *st)
{	
	printf("Enter size=");
	scanf("%d",&st->size);
	st->top=-1;
	st->S=(int*)malloc(st->size*sizeof(int));	
}

void push(struct Stack *st,int x)
{
	if(st->top==st->size-1)
	printf("Stack is full\n");
	else
	{
		st->top++;
		st->S[st->top]=x;
	}
}

int pop(struct Stack *st)
{
	int x=-1;
	if(st->top==-1)
	printf("Stack is empty\n");
	else
	{
		x=st->S[st->top--];
	}
	return x;
}

void display(struct Stack st)
{
	int i;
	if(st.top==-1)
	{
	   printf("Stack is empty");
	   return;
	}
	for(i=st.top;i>=0;i--)
	{
	  printf("% d ",st.S[i]);
	} 
	
}

int main()
{	
	int size,i,x;
	struct Stack st;
	create(&st);
	
	for(i=0;i<st.size;i++)
	{   
		int n;
		printf("Enter the elements of stack=");
		scanf("%d",&n);
		push(&st,n);
	}

	
	printf("Enter no. of elements you want to delete=");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
	  pop(&st);
    }
	printf("\n");
	
	printf("Elements after pop=");
	display(st);
	
	return 0;
}
