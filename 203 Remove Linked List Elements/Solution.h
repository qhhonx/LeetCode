//
// Created by xohozu on 15-4-24.
//

#ifndef LEECODE_SOLUTION_H
#define LEECODE_SOLUTION_H

#include <stddef.h>

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
//        // the value of head node equals `val`
//        // loop check
//        while (head && head->val == val) {
//            ListNode *t = head;
//            head = head->next;
//            delete t;
//        }
//        if (!head) return head;
//        ListNode *next = head->next, *prev = head;
//        while (next) {
//            if (next->val == val) {
//                // remove intermediate element
//                prev->next = next->next;
//                delete next;
//                next = prev;
//            }
//            prev = next;
//            next = next->next;
//        }
//        return head;
        ListNode *dummy = new ListNode(-1), *prev;
        dummy->next = head;
        prev = dummy;
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
                delete head;
                head = prev;
            }
            prev = head;
            head = prev->next;
        }
        return dummy->next;
    }
};

#endif //LEECODE_SOLUTION_H
