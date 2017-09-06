//
// Created by xohozu on 2017/9/4.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * O(n*m*k) complexity, k is the average length of all squares.
 *
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> horizonSum, verticalSum;

        for (int i = 0; i < matrix.size(); ++i) {
            horizonSum.push_back(vector<int>(matrix[0].size()));
            verticalSum.push_back(vector<int>(matrix[0].size()));
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (j > 0) {
                    horizonSum[i][j] = horizonSum[i][j - 1] + matrix[i][j] - '0';
                } else {
                    horizonSum[i][j] = matrix[i][j] - '0';
                }

                if (i > 0) {
                    verticalSum[i][j] = verticalSum[i - 1][j] + matrix[i][j] - '0';
                } else {
                    verticalSum[i][j] = matrix[i][j] - '0';
                }
            }
        }

        int maxLengthOfSquare = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int square = 0;
                while (i + square < matrix.size() && j + square < matrix[i].size()
                       && matrix[i + square][j + square] == '1' && matrix[i + square][j] == '1' && matrix[i][j + square] == '1'
                       && horizonSum[i + square][j + square] - horizonSum[i + square][j] == square
                       && verticalSum[i + square][j + square] - verticalSum[i][j + square] == square) {
                    square++;
                }

                if (square > maxLengthOfSquare) {
                    maxLengthOfSquare = square;
                }
            }
        }

        return maxLengthOfSquare * maxLengthOfSquare;
    }
};
*/

/**
 * Dynamic Programming Solution with O(n*m) complexity.
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> d;  // d[i][j] indicates the largest length of square of which bottom-right position is in (i,j)

        for (int i = 0; i < matrix.size(); ++i) {
            d.push_back(vector<int>(matrix[0].size()));
        }

        int maxLengthOfSquare = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            d[i][0] = matrix[i][0] - '0';
            maxLengthOfSquare = max(maxLengthOfSquare, d[i][0]);
        }

        if (matrix.size() > 0) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                d[0][j] = matrix[0][j] - '0';
                maxLengthOfSquare = max(maxLengthOfSquare, d[0][j]);
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
                } else {
                    d[i][j] = matrix[i][j] - '0';
                }
                maxLengthOfSquare = max(maxLengthOfSquare, d[i][j]);
            }
        }

        return maxLengthOfSquare * maxLengthOfSquare;
    }
};

#endif //LEETCODE_SOLUTION_H
