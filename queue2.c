#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
  int size ;
  int front ;
  int rear ;
  int *Q; 	
};

void create ( struct Queue *q , int size )
{
	q->size = size ;
	q->front = q->rear = -1 ;
	q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue( struct Queue *q ,int x)
{
	if (((q->rear+1)%q->size == q->front))
	printf("Queue is full !");
	else 
	{
		q->rear = (q->rear+1) % q->size ;
		q->Q[q->rear] = x;
	}
}

int dequeue( struct Queue *q)
{
	int x= -1;
	if (( q->rear == q->front)|| (q->rear == q->front == -1))
	printf("Queue is empty !");
	else
	{
		q->front = (q->front+1)%q->size;
		x = q->Q[q->front]; 
	}
	return x;
}

void display( struct Queue q)
{
	int i;
	for (i = q.front+1 ; i<= q.rear ; i++)
	{
		printf("%d \n", q.Q[i]);
	}
}

int main ()
{
	struct Queue q;
	create(&q , 4);
	enqueue(&q , 10);
	enqueue(&q , 20);
	enqueue(&q , 30);
	enqueue(&q , 40);
	display(q);
	printf( " Dequeued elements : %d %d" , dequeue(&q), dequeue(&q) );
		enqueue(&q , 80);
	    enqueue(&q , 90);
	    display(q);
	return 0;
	
	
}
