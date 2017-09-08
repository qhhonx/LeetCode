//
// Created by xohozu on 2017/9/6.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;

        if (rows == 0 || cols == 0) return 0;

        vector<int> height(cols, 0);
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);

        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            int l = 0, r = cols;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] = height[j] + 1;
                } else {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], l);
                } else {
                    left[j] = 0;
                    l = j + 1;
                }
            }
            for (int j = cols - 1; j >= 0 ; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], r);
                } else {
                    right[j] = cols;
                    r = j;
                }
            }

            for (int j = 0; j < cols; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};

#endif //LEETCODE_SOLUTION_H
