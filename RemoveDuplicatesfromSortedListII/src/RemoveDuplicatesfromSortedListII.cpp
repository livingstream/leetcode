//============================================================================
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
//============================================================================

#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *frontNode = head;
        ListNode *backHead = NULL, *backNode = NULL;
        while (frontNode != NULL) {
            bool found = true;
            while (frontNode->next != NULL && frontNode->val == frontNode->next->val) {
                ListNode *nextNode = frontNode->next;
                delete frontNode;
                frontNode = nextNode;
                found = false;
            }
            if (found) {
                if (backHead == NULL) {
                    backHead = frontNode;
                    backNode = frontNode;
                }
                else {
                    backNode->next = frontNode;
                    backNode = backNode->next;
                }
            }
            frontNode = frontNode->next;
        }
        if (backNode != NULL) backNode->next = NULL;
        return backHead;
    }
};

int main() {
    return 0;
}
