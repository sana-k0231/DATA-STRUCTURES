#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertLeft(struct Node** head, int value, int target) {
    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target node %d not found!\n", target);
        free(newNode);
        return;
    }

    if (temp->prev == NULL) {
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteValue(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head) (*head)->prev = NULL;
        free(temp);
        return;
    }

    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create (Insert at End)\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 2:
                printf("Enter new value: ");
                scanf("%d", &value);
                printf("Insert to LEFT of which value? ");
                scanf("%d", &target);
                insertLeft(&head, value, target);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(&head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
