//
// Created by xohozu on 2017/9/9.
//

#include "Solution.h"

class Test {
public:
    void check() {
        Solution s;

        vector<int> nums = {2147483647, -2147483647};
        cout << s.containsDuplicate(nums) << endl;

        vector<int> nums1 = {10, 15, 18, 24};
        cout << s.containsDuplicate(nums1) << endl;

        vector<int> nums2 = {1, 3, 1};
        cout << s.containsDuplicate(nums2) << endl;
    }
};
