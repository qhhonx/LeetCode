//
// Created by xohozu on 2017/9/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> nearestK;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) nearestK.erase(nums[i - (k + 1)]);

            // |x - nums[i]| <= t => -t <= x - nums[i] <= t ...(1), where x in nearestK set
            // => nums[i] - t <= x && x - nums[i] <= t ...(2)
            // Obviously, we just need to check whether the minimal x value in nearestK set satisfies inequation (2).
            // If the minimal x value satisfies nums[i] - t <= x but breaks x - nums[i] <= t, and all other values
            // in nearestK set satisfying nums[i] - t <= x will break x - nums[i] <= t.
            auto pos = nearestK.lower_bound((long long)nums[i] - (long long)t);
            if (pos != nearestK.end() && *pos - (long long)nums[i] <= (long long)t) {
                return true;
            }

            nearestK.insert(nums[i]);
        }

        return false;
    }
};

#endif //LEETCODE_SOLUTION_H
