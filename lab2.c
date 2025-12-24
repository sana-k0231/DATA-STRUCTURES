#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;


void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

       
        else if (ch == '(') {
            push(ch);
        }

       
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            push(ch);
        }

       
        else if (ch == ')') {
            postfix[k++] = pop(); 
            pop();               
        }
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
