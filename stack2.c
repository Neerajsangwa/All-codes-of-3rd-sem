#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct StackChar {
    int top;
    unsigned capacity;
    char* array;
};

struct StackInt {
    int top;
    unsigned capacity;
    int* array;
};

struct StackChar* createStackChar(unsigned capacity) {
    struct StackChar* stack = (struct StackChar*)malloc(sizeof(struct StackChar));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

struct StackInt* createStackInt(unsigned capacity) {
    struct StackInt* stack = (struct StackInt*)malloc(sizeof(struct StackInt));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFullChar(struct StackChar* stack) { return stack->top == stack->capacity - 1; }
int isEmptyChar(struct StackChar* stack) { return stack->top == -1; }
void pushChar(struct StackChar* stack, char item) {
    if (!isFullChar(stack)) stack->array[++stack->top] = item;
}
char popChar(struct StackChar* stack) {
    return isEmptyChar(stack) ? '$' : stack->array[stack->top--];
}
char peekChar(struct StackChar* stack) {
    return isEmptyChar(stack) ? '$' : stack->array[stack->top];
}

int isFullInt(struct StackInt* stack) { return stack->top == stack->capacity - 1; }
int isEmptyInt(struct StackInt* stack) { return stack->top == -1; }
void pushInt(struct StackInt* stack, int item) {
    if (!isFullInt(stack)) stack->array[++stack->top] = item;
}
int popInt(struct StackInt* stack) {
    return isEmptyInt(stack) ? '$' : stack->array[stack->top--];
}

int isOperand(char ch) {
    return isdigit(ch);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int infixToPostfix(char* exp, char* result) {
    struct StackChar* stack = createStackChar(strlen(exp));
    int k = 0;
    int i;
    for ( i = 0; exp[i]; i++) {
        if (isOperand(exp[i])) {
            result[k++] = exp[i];
        } else if (exp[i] == '(') {
            pushChar(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmptyChar(stack) && peekChar(stack) != '(') {
                result[k++] = popChar(stack);
            }
            popChar(stack); 
        } else {
            while (!isEmptyChar(stack) && precedence(peekChar(stack)) >= precedence(exp[i])) {
                result[k++] = popChar(stack);
            }
            pushChar(stack, exp[i]);
        }
    }
    while (!isEmptyChar(stack)) {
        result[k++] = popChar(stack);
    }
    result[k] = '\0'; 
    return k;
}

int evaluatePostfix(char* exp) {
    struct StackInt* stack = createStackInt(strlen(exp));
    int i;
    for ( i = 0; exp[i]; i++) {
        if (isOperand(exp[i])) {
            pushInt(stack, exp[i] - '0'); 
        } else {
            int val2 = popInt(stack);
            int val1 = popInt(stack);
            int result = applyOp(val1, val2, exp[i]);
            pushInt(stack, result);
        }
    }
    return popInt(stack);
}

int main() {
    char infixExp[100];
    char postfixExp[100];

    printf("Enter an infix expression: ");
    scanf("%s", infixExp);

    infixToPostfix(infixExp, postfixExp);
    printf("Postfix expression: %s\n", postfixExp);

    int result = evaluatePostfix(postfixExp);
    printf("Evaluation result: %d\n", result);

    return 0;
}

