//
// Created by xohozu on 8/14/15.
//
#include <iostream>
#include <vector>

using namespace std;

#include "Solution.h"


class Test {
public:
    void check() {
        vector<int> nums1a = {2, 3, 4, 13, 21};
        vector<int> nums2a = {2, 3, 9, 12, 13, 20};

        vector<int> nums1b = {1, 2, 3, 4, 5, 6};
        vector<int> nums2b = {7, 8, 9};

        vector<int> nums1c = {6, 9, 12, 13};
        vector<int> nums2c = {2, 3, 4, 5, 8, 9};

        Solution s;

        cout << s.findMedianSortedArrays(nums1a, nums2a) << endl;
        cout << s.findMedianSortedArrays(nums1b, nums2b) << endl;
        cout << s.findMedianSortedArrays(nums1c, nums2c) << endl;
    }
};