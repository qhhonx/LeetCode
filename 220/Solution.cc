//
// Created by xohozu on 2017/9/9.
//

#include "Solution.h"

class Test {
public:
    void check() {
        Solution s;

        vector<int> nums = {2147483647, -2147483647};
        cout << s.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;

        vector<int> nums1 = {10, 15, 18, 24};
        cout << s.containsNearbyAlmostDuplicate(nums1, 3, 3) << endl;
    }
};
