//
// Created by xohozu on 2017/7/12.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length();
        if (sz <= 1) return s;

        vector<vector<int>> palindromes;
        palindromes.resize(sz);

        palindromes[0].push_back(1);
        palindromes[0].push_back(0);

        int longest = 1;
        int longest_tail_index = 0;

        for (int j = 1; j < sz; ++j) {
            int i = j - 1;
            for (int k = 0; k < palindromes[i].size(); ++k) {
                int t = i - palindromes[i][k];
                if (t >= 0 && s[t] == s[j]) {
                    palindromes[j].push_back(palindromes[i][k] + 2);
                    if (palindromes[j].back() > longest) {
                        longest = palindromes[j].back();
                        longest_tail_index = j;
                    }
                }
            }
            palindromes[j].push_back(1);
            palindromes[j].push_back(0);
        }

        return s.substr(longest_tail_index - longest + 1, longest);
    }
};

#endif //LEETCODE_SOLUTION_H
