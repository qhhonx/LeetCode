//
// Created by xohozu on 2017/9/6.
//

#include "Solution.h"

class Test {
public:
    void check() {
        vector<vector<char>> mat = {{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}};

        vector<vector<char>> mat1 = {{'1', '1', '1', '1'},
                                     {'1', '1', '1', '1'},
                                     {'1', '1', '1', '1'}};

        vector<vector<char>> mat2 = {{'1', '1', '1', '1'},
                                     {'1', '0', '1', '1'},
                                     {'1', '1', '1', '1'}};

        vector<vector<char>> mat3 = {{'0', '1', '1', '0', '1'},
                                     {'1', '1', '0', '1', '0'},
                                     {'0', '1', '1', '1', '0'},
                                     {'1', '1', '1', '1', '0'},
                                     {'1', '1', '1', '1', '1'},
                                     {'0', '0', '0', '0', '0'}};

        Solution s;

        cout << s.maximalRectangle(mat) << endl;
        cout << s.maximalRectangle(mat1) << endl;
        cout << s.maximalRectangle(mat2) << endl;
        cout << s.maximalRectangle(mat3) << endl;
    }
};

