//Enter n numbers and sort them by using Quick Sort through LINK LIST.

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get the last node of the list
Node* getLastNode(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

// Function to partition the list
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;
    if (low == high) return low; // No need to partition

    while (j != high) {
        if (j->data < pivot) {
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
            i = i->next;
        }
        j = j->next;
    }
    int temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

// Function to sort the linked list using quicksort
void quickSort(Node* low, Node* high) {
    if (low && high && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        if (low != pivot) {
            Node* temp = low;
            while (temp != NULL && temp->next != pivot) {
                temp = temp->next;
            }
            if (temp != NULL) {
                quickSort(low, temp);
            }
        }
        quickSort(pivot->next, high);
    }
}

// Function to sort the list
void sortList(Node** head) {
    Node* high = getLastNode(*head);
    quickSort(*head, high);
}

// Main function
int main() {
    Node* head = NULL;

    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&head, data);
    }

    printf("Original list:\n");
    printList(head);

    sortList(&head);

    printf("Sorted list:\n");
    printList(head);

    return 0;
}
