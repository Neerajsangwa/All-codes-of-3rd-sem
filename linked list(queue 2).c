#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void create(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;  
    } else {
        q->rear->next = temp;  
        q->rear = temp;       
    }
}

int dequeue(struct Queue* q) {
    int x = -1;
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return x;
    } else {
        struct Node* temp = q->front;
        x = temp->data;
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL; 
        }
        free(temp);  
    }
    return x;
}

void display(struct Queue q) {
    struct Node* temp = q.front;
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue q;
    create(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    
    printf("Queue after enqueuing elements:\n");
    display(q);
    
    printf("Dequeued elements: %d %d\n", dequeue(&q), dequeue(&q));
    
    enqueue(&q, 80);
    enqueue(&q, 90);
    
    printf("Queue after more enqueues:\n");
    display(q);
    
    return 0;
}

