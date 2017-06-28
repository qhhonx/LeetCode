//
// Created by xohozu on 2017/6/20.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (sz1 > sz2) {
            return _findMedianSortedArrays(nums2, nums1);
        } else {
            return _findMedianSortedArrays(nums1, nums2);
        }
    }

    double _findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        double max_left, min_right;
        int i_min = 0, i_max = sz1, len_half = (sz1 + sz2 + 1) / 2;
        while (i_min <= i_max) {
            int i = (i_min + i_max) / 2;
            int j = len_half - i;

            if (i < sz1 && nums2[j - 1] > nums1[i]) {
                i_min = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                i_max = i - 1;
            } else {
                if (i == 0) {
                    max_left = nums2[j - 1];
                } else if (j == 0) {
                    max_left = nums1[i - 1];
                } else {
                    max_left = max(nums1[i - 1], nums2[j - 1]);
                }

                if ((sz1 + sz2) % 2 == 1) {
                    return max_left;
                }

                if (i == sz1) {
                    min_right = nums2[j];
                } else if (j == sz2) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }

                return (max_left + min_right) / 2;
            }
        }
    }
};

#endif //LEETCODE_SOLUTION_H
