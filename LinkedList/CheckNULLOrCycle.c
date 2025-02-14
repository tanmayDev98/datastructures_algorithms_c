//Floydd's detection algorithm
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

int checkLoop(struct ListNode *head) {
    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;

    while(fastPtr && fastPtr!=NULL) {
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;

        if(slowPtr == fastPtr) {
            printf("LinkedList contains a loop");
            return 1;
        }
    }

    printf("no Loop in LinkedList");
    return 0;
}

// Function to create a loop in the linked list (for testing)
void createLoop(struct ListNode* head, int position) {
    struct ListNode* temp = head;
    struct ListNode* loopNode = NULL;

    int index = 1;
    while (temp->next != NULL) {
        if (index == position) {
            loopNode = temp;
        }
        temp = temp->next;
        index++;
    }
    
    if (loopNode != NULL) {
        temp->next = loopNode;
    }
}

struct ListNode *findLoopBegining(struct ListNode *head) {
    struct ListNode *slowPtr = head;
    struct ListNode *fastptr = head;
    int loopExists = 0;

    while(fastptr && fastptr->next) {
        slowPtr = slowPtr->next;
        fastptr = fastptr->next->next;

        if(slowPtr == fastptr)
        {
            loopExists = 1;
            break;
        }
    }

    if(loopExists) {
        slowPtr = head;
        while(slowPtr != fastptr) {
            slowPtr = slowPtr->next;
            fastptr = fastptr->next;
        }
        printf("%d", slowPtr->data);
        return slowPtr;
    }
    return NULL;
}

int lengthOfLoop(struct ListNode *head) {
    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;

    int loopExists = 0;
    int count = 0;
        

    while(fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr) {
            loopExists = 1;
            break;
        }
    }

    if(loopExists) {
        count = 1;
        while(slowPtr != fastPtr) {
            fastPtr =fastPtr->next;
            count++;
        }
        return count;
    }

    return 0;
}

// Helper function to create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a loop at node 3 (Position 3)
    createLoop(head, 3);

    // Check for loop in the linked list
    checkLoop(head);

    head = findLoopBegining(head);
    int length = lengthOfLoop(head);
    printf("%d", length);

    return  0;
}