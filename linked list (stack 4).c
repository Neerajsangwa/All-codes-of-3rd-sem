#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct StackFrame {
    int disk;          
    char from;         
    char to;          
    char aux;         
    int phase;        
    struct StackFrame* next;
};


struct StackFrame* createFrame(int disk, char from, char to, char aux, int phase) {
    struct StackFrame* newFrame = (struct StackFrame*)malloc(sizeof(struct StackFrame));
    newFrame->disk = disk;
    newFrame->from = from;
    newFrame->to = to;
    newFrame->aux = aux;
    newFrame->phase = phase;
    newFrame->next = NULL;
    return newFrame;
}

void push(struct StackFrame** top, int disk, char from, char to, char aux, int phase) {
    struct StackFrame* newFrame = createFrame(disk, from, to, aux, phase);
    newFrame->next = *top;
    *top = newFrame;
}

struct StackFrame* pop(struct StackFrame** top) {
    if (*top == NULL) return NULL;
    struct StackFrame* temp = *top;
    *top = (*top)->next;
    return temp;
}

void towerOfHanoi(int n, char from, char to, char aux) {
    struct StackFrame* stack = NULL;
    push(&stack, n, from, to, aux, 0);  

    while (stack != NULL) {
        struct StackFrame* frame = pop(&stack);

        if (frame->disk == 1) {
            printf("Move disk 1 from %c to %c.\n", frame->from, frame->to);
            free(frame);
        } else if (frame->phase == 0) {
            push(&stack, frame->disk, frame->from, frame->to, frame->aux, 1);   
            push(&stack, frame->disk - 1, frame->from, frame->aux, frame->to, 0); 
        } else if (frame->phase == 1) {
            printf("Move disk %d from %c to %c.\n", frame->disk, frame->from, frame->to);

            push(&stack, frame->disk - 1, frame->aux, frame->to, frame->from, 0);
            free(frame);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    int totalMoves = pow(2, n) - 1;
    printf("Total number of moves: %d\n", totalMoves);

    return 0;
}

