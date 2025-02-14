#include <stdio.h>
#include <stdlib.h>

struct CLLNode {
    int data;
    struct CLLNode *next;
};

int length(struct CLLNode *head) {
    struct CLLNode *current = head;
    int count = 0;
    if(head==NULL) {
        return 0;
    }

    do {
        current = current->next;
        count++;
    } while(current!=head);

    return count;
}

// Function to insert at the head of the circular linked list
struct CLLNode* insertAtHead(struct CLLNode *head, int data) {
    struct CLLNode *newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = data;
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct CLLNode *curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = head;

    return newNode;
}

//deleting the end of the circular list
struct CLLNode *deleteAtEnd(struct CLLNode *head) {
    
    struct CLLNode *curr = head;
    struct CLLNode *temp = head; 

    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    
    while(curr->next != head) {
        temp = curr;
        curr = curr->next;
    }

    temp->next = curr->next;
    free(curr);

    return head;
}

//delete the first node of circular list
struct CLLNode *deleteAtFront(struct CLLNode *head) {
    struct CLLNode *curr = head;
    struct CLLNode *temp = head;

    if(head == NULL) {
        printf("List is empty");
        return head;
    }

    while(curr->next != head) {
        curr = curr->next;
    }

    curr->next = head->next;
    head = head->next;

    free(temp);
    return;
}

//insert at end of the circular list
struct CLLNode* insertAtEnd(struct CLLNode *head, int data) {
    struct CLLNode *newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct CLLNode *curr = head;
    while(curr->next != head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = head;

    return head;
}

// Function to print the circular linked list
void printList(struct CLLNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CLLNode *current = head;
    do {
        printf("[%d]--> ", current->data);
        current = current->next; 
    } while (current != head); 

    printf("(head)\n");
}

void main() {
    struct CLLNode *head = NULL;

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    printList(head);

    head = insertAtEnd(head, 45);
    head = insertAtEnd(head, 100);
    printList(head);

    head = deleteAtEnd(head);
    printList(head);
}