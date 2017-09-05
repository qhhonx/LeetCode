//
// Created by xohozu on 2017/9/4.
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
        Solution s;

        cout << s.maximalSquare(mat) << endl;
        cout << s.maximalSquare(mat1) << endl;
        cout << s.maximalSquare(mat2) << endl;
    }
};
