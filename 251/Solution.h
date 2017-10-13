//
// Created by xohozu on 2017/10/13.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_iter = vec2d.begin();
        row_iter_end = vec2d.end();
        if (row_iter != row_iter_end) {
            col_iter = row_iter->begin();
        }
    }

    int next() {
        return *col_iter++;
    }

    bool hasNext() {
        adjust();
        return row_iter != row_iter_end && col_iter != row_iter->end();
    }
private:
    vector<vector<int>>::iterator row_iter, row_iter_end;
    vector<int>::iterator col_iter;

    void adjust() {
        if (row_iter != row_iter_end) {
            while (col_iter == row_iter->end()) {
                row_iter++;
                if (row_iter == row_iter_end) break;
                col_iter = row_iter->begin();
            }
        }
    }
};

#endif //LEETCODE_SOLUTION_H
