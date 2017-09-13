//
// Created by xohozu on 2017/9/13.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uniqueSums;
        while (true) {
            n = sumOfDigits(n);
            if (n == 1) {
                return true;
            } else if (uniqueSums.find(n) != uniqueSums.end()) {
                return false;
            }
            uniqueSums.insert(n);
        }
    }

    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int m = n % 10;
            sum += m * m;
            n = n / 10;
        }
        return sum;
    }
};

#endif //LEETCODE_SOLUTION_H
