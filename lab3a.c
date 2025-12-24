#include <stdio.h>
#define MAX 5   // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

/* Insert element into queue */
void insert() {
    int item;

    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1)  // First insertion
        front = 0;

    rear++;
    queue[rear] = item;
    printf("Inserted %d into queue.\n", item);
}

/* Delete element from queue */
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty! Cannot delete element.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) {  // Reset queue after last deletion
        front = rear = -1;
    }
}

/* Display queue elements */
void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
