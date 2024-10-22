/*Solve Tower of Hanoi problem. Enter number of disk and find Steps for
 move disk in STACK.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 

int count=0;

typedef struct 
{
    int top;
    char moves[MAX][3];  
} Stack;


void initStack(Stack *s) 
{
    s->top = -1;
}


void push(Stack *s, char fromStart, char toEnd) 
{
    if (s->top < MAX - 1) 
	{
        s->top++;
        s->moves[s->top][0] = fromStart;
        s->moves[s->top][1] = '-';
        s->moves[s->top][2] = toEnd;
    } 
	else 
	{
        printf("Stack overflow\n");
    }
}


char* pop(Stack *s) 
{
    if (s->top >= 0) 
	{
        return s->moves[s->top--];
    } 
	else 
	{
        return NULL;
    }
}


void towerOfHanoi(int n, char start, char mid, char end, Stack *s) 
{
    if (n == 1) 
	{
        push(s, start, end);
        return;
    }
    towerOfHanoi(n - 1, start, end, mid, s);
    towerOfHanoi( 1, start, mid, end, s);
    towerOfHanoi(n - 1, mid, start, end, s);
}

int main() 
{
    int n;
    Stack s;
    
    initStack(&s);
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'x', 'y', 'z', &s);
    
    printf("Steps to solve the Tower of Hanoi with %d disks:\n", n);
    while (s.top >= 0) 
	{
        char *move = pop(&s);
        printf("Move disk %c from rod %c to rod %c\n", move[0], move[1], move[2]);
        count++;
    }
    printf("count=%d",count);
    return 0;
}
