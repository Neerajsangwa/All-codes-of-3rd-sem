#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int size ;
	int front ;
	int rear ;
	int *Q ;
};

void create( struct Queue *q , int size )
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (int *)malloc(q->size*sizeof(int));
}

int enqueue(struct Queue *q , int x)
{
	if ( q->rear == q->front == q->size-1)
	{
		printf("Queue is full !");
	}
	else
	{
		q-> rear ++ ;
		q->Q[q->rear] = x ;
	}
}
int dequeue(struct Queue *q )
{
	int x = -1;
	if ((q->rear == q->front == -1)||(q->rear == q->front))
	{
		printf("Queue is already empty !");
	}
	else 
	{
		q->front ++;
		x= q->Q[q->front];
	}
	return x;
}

void display ( struct Queue q)
{
	int i;
	for ( i=q.front+1 ; i<=q.rear ; i++)
	{
		printf("%d \n",q.Q[i]);
	}
}
int main()
{
	struct Queue q ;
	

	create ( &q ,5);
    enqueue(&q , 50);
    enqueue(&q , 75);
    enqueue(&q , 80);
    enqueue(&q , 60);
    enqueue(&q , 40);
    enqueue(&q , 10);
    display(q);
    printf("dequeued : %d",dequeue(&q));
	
	return 0;
}
