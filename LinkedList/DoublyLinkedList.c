#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode *previous;
    struct DLLNode *next;
};

//inserting at head in the list
struct DLLNode *insertAtHead(struct DLLNode *head, int data) {
    struct DLLNode *current = head;

    //allocate memory for the new node
    struct DLLNode *newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if(!newNode) {
        printf("Memory allocation failed");
    }

    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL;

    if(current == NULL) {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head->previous = newNode;
    head = newNode;

    return head;
}

//inserting at tail in the list
struct DLLNode *insertAtEnd(struct DLLNode *head, int data) {
    struct DLLNode *curr = head;
    struct DLLNode *newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if(!newNode) {
        printf("Memory allocation failed!");
        return head;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(head == NULL) {
        head = newNode;
        return head;
    }

    while(curr->next!=NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->previous = curr;

    return head;
}

//inserting at a position
struct DLLNode *insertAtPosition(struct DLLNode *head, int position, int data) {
    struct DLLNode *curr = head;
    struct DLLNode *temp = NULL;
    int i = 1;

    struct DLLNode *newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if(!newNode) {
        printf("Memory allocation failed");
    }

    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL; 

    if(head == NULL || position == 1) {
        head = newNode;
        return head;
    }

    while(curr->next != NULL && i<(position-1)) {
        i++;
        temp = curr;
        curr = curr->next;
    }

    if(i<(position-1)) {
        printf("Position %d does not exist\n", position);
        return head;
    }

    temp->next = newNode;
    newNode->previous = temp;

    newNode->next = curr;
    curr->previous = newNode;

    return head;
}

//delete a head
struct DLLNode *deleteAtHead(struct DLLNode *head) {
    struct DLLNode *temp = head;

    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    
    head = head->next;
    head->previous = NULL;
    free(temp);
    return head;
}

//delete tail
struct DLLNode *deleteAtEnd(struct DLLNode *head) {
    struct DLLNode *curr = head;
    struct DLLNode *temp = NULL;

    if(head == NULL) {
        printf("list is empty");
    }

    while(curr->next != NULL) {
        temp = curr;
        curr = curr->next;
    }

    temp->next = NULL;
    free(curr);
    return head;
}

//delete at position
struct DLLNode *deleteAtPosition(struct DLLNode *head, int position) {
    struct DLLNode *curr  = head;
    struct DLLNode *temp = NULL;
    int i = 1;

    if(head == NULL) {
        printf("The list is empty");
        return head;
    }

    if(position==1) {
        head = head->next;
        if(head!=NULL) {
            head->previous = NULL;
            free(temp);
            return head;
        }
    }

    while(curr->next != NULL && i < position) {
        i++;
        curr = curr->next;
    }

    if(i<(position-1)) {
        printf("Position %d does not exist\n", position);
        return head;
    }

    temp = curr->previous;
    temp->next = curr->next;
    free(curr);
    return head;
}

void printList(struct DLLNode *head) {
    struct DLLNode *current = head;
    while (current != NULL) {
        printf("[%d] <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void main() {
    struct DLLNode *head = NULL;
    
    //Insert at head
    head = insertAtHead(head, 10);  
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    
    // //Insert at tail
    head = insertAtEnd(head, 40);

    //Insert at a position
    head = insertAtPosition(head, 3, 80);
    head = insertAtPosition(head, 7, 80);
    printList(head);

    //delete head
    head = deleteAtHead(head);
    printList(head);

    //delete at end
    head = deleteAtEnd(head);
    printList(head);

    //delete at a position
    head = deleteAtPosition(head, 2);
    printList(head);
}

