#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct NodeChar {
    char data;
    struct NodeChar* next;
};

struct NodeInt {
    int data;
    struct NodeInt* next;
};

struct StackChar {
    struct NodeChar* top;
};

struct StackInt {
    struct NodeInt* top;
};

struct StackChar* createStackChar() {
    struct StackChar* stack = (struct StackChar*)malloc(sizeof(struct StackChar));
    stack->top = NULL;
    return stack;
}

struct StackInt* createStackInt() {
    struct StackInt* stack = (struct StackInt*)malloc(sizeof(struct StackInt));
    stack->top = NULL;
    return stack;
}

int isEmptyChar(struct StackChar* stack) {
    return stack->top == NULL;
}

int isEmptyInt(struct StackInt* stack) {
    return stack->top == NULL;
}

void pushChar(struct StackChar* stack, char item) {
    struct NodeChar* newNode = (struct NodeChar*)malloc(sizeof(struct NodeChar));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

char popChar(struct StackChar* stack) {
    if (isEmptyChar(stack)) {
        return '$';  
    } else {
        struct NodeChar* temp = stack->top;
        char popped = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return popped;
    }
}

char peekChar(struct StackChar* stack) {
    if (isEmptyChar(stack)) {
        return '$';
    } else {
        return stack->top->data;
    }
}

void pushInt(struct StackInt* stack, int item) {
    struct NodeInt* newNode = (struct NodeInt*)malloc(sizeof(struct NodeInt));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int popInt(struct StackInt* stack) {
    if (isEmptyInt(stack)) {
        return -1;  
    } else {
        struct NodeInt* temp = stack->top;
        int popped = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return popped;
    }
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
        default: return 0;
    }
}

int infixToPostfix(char* exp, char* result) {
    struct StackChar* stack = createStackChar();
    int k = 0;
    int i;
    for (i = 0; exp[i]; i++) {
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
    struct StackInt* stack = createStackInt();
    int i;
    for (i = 0; exp[i]; i++) {
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

