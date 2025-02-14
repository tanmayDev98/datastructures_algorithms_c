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

struct ListNode *KthNodeFromEnd(struct ListNode *head, int k) {
    struct ListNode *first = head;
    struct ListNode *second = head;
    int jumps=0;

    if(head == NULL) {
        printf("List is empty");
        return head;
    }

    int length = getLength(head);
    if(k > length) {
        printf("Position does not exist");
        return head;
    }

    for(jumps=0; jumps<k; jumps++) {
        first=first->next;
    }

    while(first!=NULL) {
        first = first->next;
        second = second->next;
    }

    printf("[%d]", second->data);
    return second;
}

int getLength(struct ListNode *head) {
    struct ListNode *curr = head;
    int count = 0;

    for(curr=head; curr!=NULL; curr=curr->next) {
        count++;
    }

    return count;
}

int main() {
    struct ListNode *head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 50);

    struct ListNode *KthNode = NULL;
    KthNode = KthNodeFromEnd(head, 4);

    return  0;
}