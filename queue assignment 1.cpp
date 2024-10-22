//Queue operations

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

void create(struct Queue *q, int size)
{
   q->size=size;
   q->front=q->rear=-1;	
   q->Q=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue*q,int x)
{
	if(q->rear==q->size-1)
	printf("Queue is full\n");
	else 
	{
		q->rear++;
		q->Q[q->rear]=x;
	}
}

int dequeue(struct Queue *q)
{   
    int x=-1;
	if(q->rear==q->front)
	printf("Queue is Empty");
	else
	{
		q->front++;
		x=q->Q[q->front];

	}
	return x;
}

void display(struct Queue q)
{  
	int i;
	for(i=q.front+1;i<=q.rear;i++)
	{
		printf("\t");
		printf("%d",q.Q[i]);
	}
	
}

int main()

{	int size,i,x;
	struct Queue q;
	printf("Enter size of queue:");
	scanf("%d",&size);
	
	create(&q,size);
	
	for(i=0;i<size;i++)
	{
		int n;
		printf("Enter the elements of Queue=");
		scanf("%d",&n);
		enqueue(&q,n);
	}
	printf("Enter no. of elements you want to delete=");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		dequeue(&q);
	
	}
	
	printf("Elements in queue are=");
	display(q);
	
	return 0;
}

