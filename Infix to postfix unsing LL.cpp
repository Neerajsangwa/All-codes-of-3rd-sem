//Convert Infix Arithmetic Expressions into PostFix Arithmetic Expressions and evaluate them using link list.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;


void initStack(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}


char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; // Stack is empty
    }
    Node* temp = stack->top;
    char value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    return value;
}


char peek(Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; // Stack is empty
    }
    return stack->top->value;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '('
        } else { // Operator
            while (precedence(c) <= precedence(peek(&stack)) && peek(&stack) != '\0') {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (peek(&stack) != '\0') {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int evaluatePostfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&stack, c - '0'); // Convert char to int
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (c) {
                case '+':
                    push(&stack, val1 + val2);
                    break;
                case '-':
                    push(&stack, val1 - val2);
                    break;
                case '*':
                    push(&stack, val1 * val2);
                    break;
                case '/':
                    push(&stack, val1 / val2);
                    break;
                case '^':
                    // Simple implementation of power (not for large numbers)
                    int result = 1;
                    for (int j = 0; j < val2; j++) {
                        result *= val1;
                    }
                    push(&stack, result);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluation result: %d\n", evaluatePostfix(postfix));

    return 0;
}
