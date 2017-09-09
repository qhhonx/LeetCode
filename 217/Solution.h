//
// Created by xohozu on 2017/9/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique_nums;

        for (auto num: nums) {
            if (unique_nums.find(num) != unique_nums.end()) return true;
            unique_nums.insert(num);
        }

        return false;
    }
};

#endif //LEETCODE_SOLUTION_H
