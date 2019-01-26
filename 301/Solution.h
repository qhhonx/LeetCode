//
// Created by xohozu on 2017/11/10.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;

        dfs(s, 0, 0, {'(', ')'}, res);

        return res;
    }

    void dfs(const string &s, int find_start, int del_start, pair<char, char> paren, vector<string> &res) {
        for (int cnt = 0, j = find_start; j < s.size(); j++) {
            if (s[j] == paren.first) {
                cnt++;
            } else if (s[j] == paren.second) {
                cnt--;
            }
            if (cnt >= 0) {
                continue;
            }
            for (int i = del_start; i <= j; i++) {
                if (s[i] == paren.second && (i == del_start || s[i - 1] != s[i])) {
                    string ts(s);
                    dfs(ts.erase(i, 1), j, i, paren, res);
                }
            }
            return;
        }
        string rs(s);
        reverse(rs.begin(), rs.end());
        if (paren.first == '(') {
            dfs(rs, 0, 0, {')', '('}, res);
        } else {
            res.push_back(rs);
        }
    }
};


#endif //LEETCODE_SOLUTION_H
