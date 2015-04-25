//
// Created by xohozu on 15-4-24.
//

#include "Solution.h"
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
class reverse_adapter {
public:
    reverse_adapter(T &c) : c(c) { }

    typename T::reverse_iterator begin() { return c.rbegin(); }

    typename T::reverse_iterator end() { return c.rend(); }

private:
    T &c;
};

template<typename T>
reverse_adapter<T> reverse_adapt_container(T &c) { return reverse_adapter<T>(c); }


class Test {
private:
    Solution solution;

public:
    // build a link list with given head pointer
    void build(ListNode* &head, vector<int> v) {
        ListNode *prev = NULL, *next = NULL;
        for (auto i : reverse_adapt_container(v)) {
            prev = new ListNode(i);
            prev->next = next;
            next = prev;
        }
        head = prev;
    }

    void test_case(vector<int> v) {
        ListNode *head;
        build(head, v);

        cout << __func__ << " : ";
        print(head);

        cout << "after_del : ";
        print(solution.removeElements(head, 6));
    }

    // print linked list with head pointer
    void print(ListNode *head) {
        if (!head) {
            cout << "Empty linked list!" << endl;
            return;
        }
        cout << head->val;
        head = head->next;
        while (head) {
            cout << " -> " << head->val;
            head = head->next;
        }
        cout << endl;
    }

    void check() {
        test_case(vector<int> {1, 2, 6, 3, 4, 5, 6});
        test_case(vector<int> {1, 2, 6, 6});
        test_case(vector<int> {6, 6, 3, 4, 6, 5, 6, 6});
        test_case(vector<int> {1});
        test_case(vector<int> {6, 6});
        test_case(vector<int> {});
    }
};