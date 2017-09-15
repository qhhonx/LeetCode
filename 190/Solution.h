//
// Created by xohozu on 2017/9/15.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t one = 0xFFFFFFFF;
        uint32_t l1 = 0x80000000, r1 = 0x00000001;
        for (int i = 0; i < 16; ++i) {
            n = ((n & l1) >> (((15 - i) << 1) + 1)) | (n & (one ^ l1) & (one ^ r1)) | ((n & r1) << (((15 - i) << 1) + 1));
            l1 >>= 1;
            r1 <<= 1;
        }
        return n;
    }
};

#endif //LEETCODE_SOLUTION_H
