#include <stdio.h>
#include <ctype.h>  
#include <string.h> 

#define MAX 100  


struct Stack {
    int top;
    char arr[MAX];
} stack;

void initStack() {
    stack.top = -1;
}

void push(char x) 
{
    if (stack.top == MAX - 1) 
	{
        printf("Stack overflow!\n");
    } 
	else 
	{
        stack.arr[++stack.top] = x;
    }
}

char pop() 
{
    if (stack.top == -1) 
	{
        return -1;  
    } 
	else 
	{
        return stack.arr[stack.top--];
    }
}


int precedence(char op) 
{
    if (op == '+' || op == '-') 
	{
        return 1;
    }
	else if (op == '*' || op == '/') 
	{
        return 2;
    } 
	else if (op == '^') 
	{
        return 3;
    }
    return 0;
}


int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


int isLeftParenthesis(char ch) 
{
    return ch == '(';
}

int isRightParenthesis(char ch) 
{
    return ch == ')';
}

void infixToPostfix(char* infix, char* postfix) 
{
    initStack();
    int i, j = 0;
    char x;
    
    for (i = 0; infix[i] != '\0'; i++) 
	{
        char ch = infix[i];
        
       
        if (isalnum(ch)) 
		{
            postfix[j++] = ch;
        } 
      
        else if (isLeftParenthesis(ch)) 
		{
            push(ch);
        } 
        
        else if (isRightParenthesis(ch)) 
		{
            while ((x = pop()) != '(') 
			{
                postfix[j++] = x;
            }
        } 
        
        else if (isOperator(ch)) 
		{
            while (stack.top != -1 && precedence(stack.arr[stack.top]) >= precedence(ch)) 
			{
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    
   
    while (stack.top != -1) 
	{
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  
}

int main() 
{
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);  
    
    infix[strlen(infix) - 1] = '\0';  
    
    infixToPostfix(infix, postfix);  
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
