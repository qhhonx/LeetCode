//
// Created by xohozu on 2017/9/9.
//

#include "Solution.h"

class Test {
public:
    void check() {
        Solution s;

        vector<int> nums = {2147483647, -2147483647};
        cout << s.containsNearbyDuplicate(nums, 1) << endl;

        vector<int> nums1 = {10, 15, 18, 15};
        cout << s.containsNearbyDuplicate(nums1, 3) << endl;

        vector<int> nums2 = {1, 3, 1};
        cout << s.containsNearbyDuplicate(nums2, 1) << endl;
    }
};
