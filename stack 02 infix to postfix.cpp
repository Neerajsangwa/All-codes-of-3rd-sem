
//Infix to Postfix Notation
#include <stdio.h>
#include <ctype.h>  // for isalnum()
#include <string.h> // for strlen()

#define MAX 100  // Max stack size

// Stack structure for operators
struct Stack 
{
    int top;
    char arr[MAX];
} stack;

// Function to initialize the stack
void initStack()
{
    stack.top = -1;
}

// Function to push an element to the stack
void push(char x) 
{
    if (stack.top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack.arr[++stack.top] = x;
    }
}

// Function to pop an element from the stack
char pop()
 {
    if (stack.top == -1) {
        return -1;  // Stack is empty
    } else {
        return stack.arr[stack.top--];
    }
}

// Function to return the precedence of the operator
int precedence(char op)
 {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to check if the character is a left parenthesis
int isLeftParenthesis(char ch)
{
    return ch == '(';
}

// Function to check if the character is a right parenthesis
int isRightParenthesis(char ch)
{
    return ch == ')';
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) 
{
    initStack();//initializes an empty stack
    int i, j = 0;
    char x;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If operand, add it to the postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        // If left parenthesis, push to stack
        else if (isLeftParenthesis(ch)) {
            push(ch);
        }
        // If right parenthesis, pop from stack until left parenthesis
        else if (isRightParenthesis(ch)) {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        // If operator, handle precedence and push to stack
        else if (isOperator(ch)) {
            while (stack.top != -1 && precedence(stack.arr[stack.top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    
    // Pop all remaining operators from the stack
    while (stack.top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  // Terminate the postfix expression
}

int main()
{
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);  // Read infix expression
    
    infix[strlen(infix) - 1] = '\0';  // Remove the newline character from fgets
    
    infixToPostfix(infix, postfix);  // Convert infix to postfix
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
