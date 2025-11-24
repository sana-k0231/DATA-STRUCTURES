#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node *i, *j;
    int temp;

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Linked list sorted successfully!\n");
}


void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    printf("Linked list reversed successfully!\n");
}

void concatenate(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
        return;
    }

    struct Node* temp = *list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *list2;

    printf("Lists concatenated successfully!\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n-----operation on linked lists-----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 into List 1\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&list2, value);
                break;

            case 3:
                displayList(list1);
                break;

            case 4:
                displayList(list2);
                break;

            case 5:
                sortList(&list1);
                break;

            case 6:
                reverseList(&list1);
                break;

            case 7:
                concatenate(&list1, &list2);
                break;

            default:
                printf("invalid choice");
        }
    }
}
