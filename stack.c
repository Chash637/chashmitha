#include <stdio.h>
#include <stdlib.h>

// Define the maximum size for the stack
#define MAX 100

// Stack structure
struct Stack {
    int data[MAX];
    int top;
};

// Function to initialize a stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 if the stack is empty
    }
    return s->data[(s->top)--];
}

// Function to peek the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  // Return -1 if the stack is empty
    }
    return s->data[s->top];
}

// Function to sort the stack using a temporary stack
void sortStack(struct Stack* s) {
    struct Stack tempStack;
    initStack(&tempStack);
    
    // Sort the stack
    while (!isEmpty(s)) {
        int current = pop(s);
        
        // Move elements from tempStack to s while they are greater than current
        while (!isEmpty(&tempStack) && peek(&tempStack) > current) {
            push(s, pop(&tempStack));
        }
        
        // Push current to tempStack
        push(&tempStack, current);
    }
    
    // Move elements back to the original stack from tempStack (sorted order)
    while (!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
    }
}

// Function to print the stack elements
void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Driver function to test the sortStack function
int main() {
    struct Stack s;
    initStack(&s);

    int n, value;

    // Take user input for the stack size
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    // Take user input for the stack elements
    printf("Enter %d elements to push onto the stack: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&s, value);
    }

    printf("Original Stack: ");
    printStack(&s);

    // Sort the stack
    sortStack(&s);

    printf("Sorted Stack: ");
    printStack(&s);

    return 0;
}
