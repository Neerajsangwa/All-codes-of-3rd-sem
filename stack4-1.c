#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;         
    char from_rod; 
    char to_rod;   
    char aux_rod;  
    int state;     
} StackFrame;

typedef struct {
    StackFrame *frames;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->frames = (StackFrame *)malloc(stack->capacity * sizeof(StackFrame));
    return stack;
}

void push(Stack *stack, StackFrame frame) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->frames = (StackFrame *)realloc(stack->frames, stack->capacity * sizeof(StackFrame));
    }
    stack->frames[++stack->top] = frame;
}

StackFrame pop(Stack *stack) {
    return stack->frames[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void towerOfHanoiIterative(int n, char from_rod, char to_rod, char aux_rod) {
    Stack *stack = createStack(100);

    StackFrame initial_frame = {n, from_rod, to_rod, aux_rod, 0};
    push(stack, initial_frame);

    while (!isEmpty(stack)) {
        StackFrame frame = pop(stack);

        if (frame.n == 1) {
            printf("Move disk 1 from rod %c to rod %c\n", frame.from_rod, frame.to_rod);
        } else {
            if (frame.state == 0) {
                frame.state = 1;
                push(stack, frame); 

                StackFrame first = {frame.n - 1, frame.from_rod, frame.aux_rod, frame.to_rod, 0};
                push(stack, first);
            } else {
                printf("Move disk %d from rod %c to rod %c\n", frame.n, frame.from_rod, frame.to_rod);

                StackFrame second = {frame.n - 1, frame.aux_rod, frame.to_rod, frame.from_rod, 0};
                push(stack, second); 
            }
        }
    }

    free(stack->frames);
    free(stack);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoiIterative(n, 'A', 'C', 'B'); 

    return 0;
}

