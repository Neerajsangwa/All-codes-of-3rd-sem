#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct node* getTail(struct node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

void swapData(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct node* partition(struct node* low, struct node* high) {
    int pivot = high->data; 
    struct node* i = low; 
    struct node* j = low;

    while (j != high) {
        if (j->data < pivot) {
            swapData(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swapData(i, high); 
    return i;
}

void quickSortRecur(struct node* low, struct node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        struct node* p = partition(low, high);
        quickSortRecur(low, p->next);  
        quickSortRecur(p->next, high); 
    }
}

void quickSort(struct node* head) {
    struct node* tail = getTail(head);
    quickSortRecur(head, tail);
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, num;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%d", &num);
        append(&head, num);
    }

    printf("Unsorted List: \n");
    printList(head);

    quickSort(head);

    printf("Sorted List: \n");
    printList(head);

    return 0;
}

