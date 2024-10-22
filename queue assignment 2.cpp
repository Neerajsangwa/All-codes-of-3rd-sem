
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

void create(struct Queue *q,int size)
{
   q->size=size;
   q->front=q->rear=0;	
   q->Q=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue*q,int x)
{
	if((q->rear+1)% q->size==q->front)
	printf("Queue is full\n");
	else 
	{
		q->Q[q->rear]=x;
		q->rear=(q->rear+1)% q->size;
		
	}
}

int dequeue(struct Queue *q)
{   
    int x=-1;
	if(q->front==q->rear)
	printf("Queue is Empty\n");
	else
	{
		q->front=(q->front+1)% q->size;
		x=q->Q[q->front];

	}
	return x;
}

void display(struct Queue q)
{   int i=q.front;
	if(q.front==q.rear)
	{
	   printf("Queue is empty\n");
	   return;
	}
	do
	{
		printf("\t");
		printf("%d",q.Q[i]);
		i=(i+1)%q.size;
		
	}
	while(i!=(q.rear));
	printf("\n");
}

int main()

{	int size,i,x;
	struct Queue q;
	printf("Enter size of queue:");
	scanf("%d",&size);
	
	create(&q,size+1);
	
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
