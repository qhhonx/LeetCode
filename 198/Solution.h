//
// Created by xohozu on 2017/9/13.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> d(nums.size());

        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int amount = 0;
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            d[i] = max(d[i - 1], nums[i] + d[i - 2]);
            amount = max(amount, d[i]);
        }
        return amount;
    }
};

#endif //LEETCODE_SOLUTION_H
