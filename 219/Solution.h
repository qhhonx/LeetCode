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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uniqueNearestK;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) uniqueNearestK.erase(nums[i - (k + 1)]);

            if (uniqueNearestK.find(nums[i]) != uniqueNearestK.end())
                return true;

            uniqueNearestK.insert(nums[i]);
        }

        return false;
    }
};

#endif //LEETCODE_SOLUTION_H
