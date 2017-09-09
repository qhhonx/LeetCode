//
// Created by xohozu on 2017/9/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

#define BUCKET_SORT

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
#if defined(BUCKET_SORT)
        if (k < 1 || t < 0) return false;

        // inspired by bucket sort
        // buckets: i-1,             i,               i+1
        //          [(i-1)*w, i*w),  [i*w, (i+1)*w),  [(i+1)*w, (i+2)*w)  where w = t + 1
        // if two numbers' difference is at most t,
        // then they are either in same bucket or two adjacent buckets.

        long long bucket_width = (long long)t + 1;
        unordered_map<long long, long long> buckets;
        vector<long long> adjustedNums(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) buckets.erase(adjustedNums[i - (k + 1)] / bucket_width);

            adjustedNums[i] = (long long)nums[i] + (long long)INT_MAX;

            long long bucket_i = adjustedNums[i] / bucket_width;

            if (buckets.find(bucket_i) != buckets.end()) {
                return true;
            }
            if (buckets.find(bucket_i - 1) != buckets.end() && abs(adjustedNums[i] - buckets[bucket_i - 1]) < bucket_width) {
                return true;
            }
            if (buckets.find(bucket_i + 1) != buckets.end() && abs(adjustedNums[i] - buckets[bucket_i + 1]) < bucket_width) {
                return true;
            }

            buckets[bucket_i] = adjustedNums[i];
        }

        return false;
#else
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
#endif
    }
};

#endif //LEETCODE_SOLUTION_H
