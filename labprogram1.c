#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed to stack\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        int item = stack[top];
        top--;
        printf("Popped item: %d\n", item);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
