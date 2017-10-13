//
// Created by xohozu on 2017/10/13.
//

#include "Solution.h"

class Test {
public:
    void check() {
//        vector<vector<int>> vec2d = {{1,2}, {3}, {4,5,6}};
        vector<vector<int>> vec2d = {{}, {3}, {}};
//        vector<vector<int>> vec2d = {{}, {3}, {4,5,6}};

        Vector2D i(vec2d);
        while (i.hasNext()) cout << i.next();
    }
};
