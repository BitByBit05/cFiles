#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node {
    int data;
    struct node *link;
};

// Function prototypes
void printNode(struct node *ptr);
void nodeInsertAtFirst(struct node **ptr);
void insertAtMiddle(struct node **head, int position);
void nodeDeleteAtEnd(struct node **head);
void freeList(struct node **head);

// Function to print all nodes
void printNode(struct node *ptr) {
    printf("\nList: ");
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

// Function to insert a node at the beginning
void nodeInsertAtFirst(struct node **ptr) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter the data of the new node: ");
    scanf("%d", &newNode->data);
    newNode->link = *ptr;
    *ptr = newNode;

    printf("\nList after inserting at the beginning:\n");
    printNode(*ptr);
}

// Function to insert a node after a given position
void insertAtMiddle(struct node **head, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *temp = *head;
    int count = 1;

    // Traverse to (position)-th node
    while (temp != NULL && count < position) {
        temp = temp->link;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);

    newNode->link = temp->link;
    temp->link = newNode;
}

// Function to delete a node from the end
void nodeDeleteAtEnd(struct node **head) {
    if (*head == NULL) {
        // List is already empty
        return;
    }

    struct node *temp = *head;

    // If there is only one node
    if (temp->link == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    // temp now points to the second last node
    free(temp->link);      // free the last node
    temp->link = NULL;     // set second last node's link to NULL
}

// Function to free the entire list
void freeList(struct node **head) {
    struct node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    struct node *temp = NULL;
    int n, i, value;

    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List will be empty.\n");
        return 0;
    }

    // Creating the linked list dynamically
    for (i = 0; i < n; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            freeList(&head);
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->link = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->link = newNode;
            temp = temp->link;
        }
    }

    printf("\nOriginal List:\n");
    printNode(head);

    int pos;
    printf("\nEnter the position after which you want to insert the new node: ");
    scanf("%d", &pos);

    insertAtMiddle(&head, pos);

    printf("\nList after insertion:\n");
    printNode(head);

    printf("Deleting end node: \n");
    nodeDeleteAtEnd(&head);
    printNode(head);

    printf("\nList after deleting the last node:\n");
    printNode(head);

    // Optionally insert at first
    char choice;
    printf("\nDo you want to insert a node at the beginning? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        nodeInsertAtFirst(&head);
    }

    // Free all allocated memory
    freeList(&head);

    return 0;
}
