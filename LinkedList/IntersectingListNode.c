#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *intersectingListNode(struct ListNode *head1, struct ListNode *head2) {
    int m = getLength(head1);
    int n = getLength(head2);
    struct ListNode *mergePoint = NULL;
    struct ListNode *curr1 = head1;
    struct ListNode *curr2 = head2;
    int i = 0;

    int diff = 0;
    if(m>n) {
        diff = m-n;
        while(--diff) {
            curr1 = curr1->next;
        }
    }
    else {
        diff = n-m;
        while(-diff) {
            curr2 = curr2->next;
        }
    }

    while(curr1 && curr2) {
        if(curr1->next == curr2->next) {
            mergePoint = curr1->next;
            break;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return mergePoint;
} 

int getLength(struct ListNode *head) {
    struct ListNode *curr = head;
    int length = 0;

    for(curr=head; curr!=NULL; curr=curr->next) {
        length++;
        curr=curr->next;
    }

    return length;
}

void main() {
    return 0;
}