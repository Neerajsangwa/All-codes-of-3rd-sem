#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Stack 
{
    struct Node* top; 
};

void create(struct Stack* st) 
{
    st->top = NULL;  
}

void display(struct Stack st) {
    struct Node* temp = st.top;
    while (temp != NULL) {
        printf("%d\n", temp->data);  
        temp = temp->next;  
    }
}

void push(struct Stack* st, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = st->top;  
    st->top = newNode;  
}

int pop(struct Stack* st) {
    int x = -1;  
    if (st->top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct Node* temp = st->top; 
        x = temp->data;  
        st->top = st->top->next; 
        free(temp); 
    }
    return x;
}

int main() {
    struct Stack st;
    create(&st);  

    push(&st, 10);
    push(&st, 20);
    push(&st, 70);
    push(&st, 90);

    printf("Stack elements:\n");
    display(st);

    printf("\nPopped elements: %d\n", pop(&st));
    printf("Popped elements: %d\n", pop(&st));

    printf("\nStack after popping:\n");
    display(st);

    return 0;
}

