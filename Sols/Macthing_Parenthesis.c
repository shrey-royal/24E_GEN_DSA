/*
1. Matching Parentheses: One classic use case for a stack is to check whether parentheses in a given string are balanced or not. This problem is solved using a stack where each opening bracket is pushed into the stack and each closing bracket is popped out of the stack. If the stack is empty at the end of the string, then the parentheses are balanced. If there are any remaining brackets in the stack, then the parentheses are not balanced.

Input: "((2 + 3) * 5)"
Output: Balanced

Input: "((2 + 3) * 5))"
Output: Not balanced

Input: "{[()()]}"
Output: Balanced

Input: "{[(])}"
Output: Not balanced

Input: "{[()[]]{}()}"
Output: Balanced

Input: "}"
Output: Not balanced
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || 
        (opening == '{' && closing == '}') || 
        (opening == '[' && closing == ']');
}

int isBalanced(char *expr) {
    top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
                return 0;   // Not Balanced
            }
        }
    }
    return top == -1;
}

int main() {
    char *inputs[] = {
        "((2 + 3) * 5)",
        "((2 + 3) * 5))",
        "{[()()]}",
        "{[(])}",
        "{[()[]]{}()}",
        "}"
    };

    for (int i = 0; i < 6; i++) {
        if (isBalanced(inputs[i])) {
            printf("Input: \"%s\" => Balanced\n", inputs[i]);
        } else {
            printf("Input: \"%s\" => Not balanced\n", inputs[i]);
        }
    }
    
}