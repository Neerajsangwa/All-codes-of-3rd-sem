#include<stdio.h>
#include<stdlib.h>

struct queue 
{
	int size ;
	int front ; 
	int rear ;
	int *Q;
};

void create ( struct queue *q , int size )
{
	q->size = size ;
	q-> front = q->rear = -1;
	q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue( struct queue *q , int x)
{
	if (q->rear == q->size -1)
	printf("Queue is full ! ");
	else 
	{
		q->rear ++;
		q->Q[q->rear] = x;
	}
}

int dequeue ( struct queue *q)
{
	int x= -1;
	if (( q->front == q->rear)||(q->front == q->rear == -1))
	printf("Queue is empty ! ");
	else 
	{
		q->front ++;
		x = q->Q[q->front];
	}
	return x;
}

void display ( struct queue q)
{
	int i;
	for ( i= q.front+1 ; i<= q.rear ; i++)
	{
		printf("%d \n", q.Q[i]);
	}
}

int main()
{
	struct queue q;
	create ( &q , 5);
	enqueue( &q , 10);
	enqueue( &q , 20);
	enqueue( &q , 30);
	enqueue( &q , 40);
	enqueue( &q , 50);
	display(q);
	printf(" Dequeud no. = %d %d %d  ", dequeue(&q) , dequeue(&q) , dequeue(&q)) ;
	return 0;
	
	
}
