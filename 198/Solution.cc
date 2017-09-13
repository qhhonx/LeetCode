//
// Created by xohozu on 2017/9/13.
//

#include "Solution.h"

class Test {
public:
    void check() {
        Solution s;

        vector<int> nums = {1, 2, 3, 4, 5, 9, 2, 9, 10};
        vector<int> nums1 = {1, 2, 3, 4, 5, 9, 2, 9};
        vector<int> nums2 = {1, 2, 3, 4, 5, 9, 2};
        vector<int> nums3 = {1, 2, 3, 4, 5, 9};
        vector<int> nums4 = {1, 2, 3, 4, 5};
        vector<int> nums5 = {1, 2, 3, 4};

        cout << s.rob(nums) << endl;
        cout << s.rob(nums1) << endl;
        cout << s.rob(nums2) << endl;
        cout << s.rob(nums3) << endl;
        cout << s.rob(nums4) << endl;
        cout << s.rob(nums5) << endl;
    }
};
