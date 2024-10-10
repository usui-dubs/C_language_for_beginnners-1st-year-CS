#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

void push(Stack *s, char data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node *temp = s->top;
    char data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

char peek(Stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->top->data;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    Stack s = {NULL};
    int i, j;
    char c;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (c >= '0' && c <= '9')
            postfix[j++] = c;
        else if (is_operator(c)) {
            while (!is_empty(&s) && peek(&s) != '(' && precedence(peek(&s)) >= precedence(c))
                postfix[j++] = pop(&s);
            push(&s, c);
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!is_empty(&s) && peek(&s) != '(')
                postfix[j++] = pop(&s);
            if (!is_empty(&s) && peek(&s) == '(')
                pop(&s);
        }
    }
    while (!is_empty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int evaluate_postfix(char postfix[]) {
    Stack s = {NULL};
    int i, a, b, result;
    char c;
    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (c >= '0' && c <= '9')
            push(&s, c - '0');
        else if (is_operator(c)) {
            b = pop(&s);
            a = pop(&s);
            switch (c) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() 
{
    int res;
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    res = evaluate_postfix(postfix);
    printf("result = %d", res);
    
    return 0;
}
