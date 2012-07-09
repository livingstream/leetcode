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
        ListNode *newHead = NULL, *curNode = NULL;
        while (head != NULL) {
            int count = 1;
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
                count++;
            }
            if (count == 1) {
                if (newHead == NULL) {
                    newHead = head;
                    curNode = head;
                }
                else {
                    curNode->next = head;
                    curNode = curNode->next;
                }
            }
            head = head->next;
        }
        if (curNode != NULL) curNode->next = NULL;
        return newHead;
    }
};

int main() {
    return 0;
}
