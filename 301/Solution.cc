//
// Created by xohozu on 2017/11/10.
//

#include "Solution.h"

class Test {
public:
    void check() {
        Solution s;

        auto r = s.removeInvalidParentheses("()()()");

        for (auto e : r) {
            cout << e << endl;
        }
    }
};
