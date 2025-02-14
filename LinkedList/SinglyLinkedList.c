#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *insertAtHead(struct ListNode *head, int data) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = head;
        head=newNode;
    }

    return head;
}

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *previousPtr = NULL;
    struct ListNode *curr = head;
    struct ListNode *next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = previousPtr;
        previousPtr = curr;
        curr = next;
    }

    return previousPtr;
}

struct ListNode *reverseRecursive(struct ListNode *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *secondElem = head->next;
    head->next = NULL;

    struct ListNode *reverseRest = reverseRecursive(secondElem);
    secondElem->next = head;
    return reverseRest;
}

int getLength(struct ListNode *head) {
    struct ListNode *curr = head;
    int count = 0;

    for(curr=head; curr!=NULL; curr=curr->next) {
        count++;
        curr=curr->next;
    }

    return count;
}


int main() {
    return  0;
}
