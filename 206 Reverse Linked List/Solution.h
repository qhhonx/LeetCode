//
// Created by xohozu on 15-5-6.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *prev = head, *next = head->next;
        prev->next = nullptr;
        while (next) {
            head = next;
            next = head->next;
            head->next = prev;

            prev = head;
        }
        return head;
    }
};

#endif //LEETCODE_SOLUTION_H
