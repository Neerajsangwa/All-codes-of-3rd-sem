//Queue using LL

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Queue
{
	struct Node* front;
	struct Node* rear;
};

void create(struct Queue *t)
{	// intialize the queue 
	t->front=NULL;
	t->rear= NULL;
}

void enqueue(struct Queue *t,int x)
{
	//t=newnode
	struct Node*n;//create node using temp pointer n
	n=(struct Node*)malloc(sizeof(struct Node));
	if(n==NULL)
	{
		printf("Queue is full");
		return;
	}
	else
	{
		n->data=x;
		n->next=NULL;
		
		if(t->rear==NULL)//means this is first node
		{
			t->front = t->rear=n;//then both front& rear point on new node n
		}
		else
		{
			t->rear->next=n;//if it is not a first node
			t->rear=n;//rear should point on n
			
		}	
	}
}

int dequeue(struct Queue *t)
{
	int x=-1;
	
	if(t->front==NULL)
	{
		printf("Queue is Empty\n");
		return x;
	}
	else
	{	
		struct Node *temp=t->front;
		t->front=t->front->next;
		x=temp->data;
		free(temp);
	}
	return x;
}

void display(struct Queue *t)
{
	struct Node *p=t->front;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}

	printf("\n");
}

int main()
{
	struct Queue q;
	create(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 60);
	
	printf("Queue elements=");
	display(&q);
	
	printf("Dequeued= %d\n",dequeue(&q));
	printf("Queue after dequeue=");
	
	display(&q);
	
	return 0;
}
