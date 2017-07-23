//
// Created by xohozu on 8/14/15.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
         * 设当前剩余油量值为cur(初始为0)，当到达某个加油站k，意味着cur >= gas[k] - cost[k]时才能到达k+1加油站。
         * a 考虑从环上第i个加油站开始出发，当到达第j个加油站时cur小于0，说明从[i,j]加油站出发均无法满足条件。
         * b 此时，我们从第j+1个加油站出发，同时将[i,j]区间的cur值累加到tot中，同时记录j+1位置作为潜在满足条件的起始index值。
         * c 不断重复a,b直到到达最后一个加油站。
         * d 当到达最后一个加油站后，如果cur + tot < 0，很容易推出此时无法满足条件；否则，从index出发便可满足情况。
         * 举例说明：
         * 记s[0, a1], s[a1+1, a2], s[a2+1, a3], ..., s[ak+1, n-1]，
         * 除s[ak+1, n-1]外，其余区间的和均为负数。
         * 如果s[ak+1, n-1]大于0，只要满足s[ak+1, n-1] + s[0, a1] + s[a1+1, a2] + ... 大于等于0，则从ak+1出发，则能满足条件。
         */
        int tot = 0, cur = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                tot += cur;
                cur = 0;
                index = i + 1;
            }
        }
        if (cur + tot < 0)
            return -1;
        else
            return index;
    }
};

#endif //LEETCODE_SOLUTION_H
