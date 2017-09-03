//
// Created by xohozu on 2017/7/31.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Assume that there are n unique words, and the average length of all words is k.
// The Brute-Force algorithm will get O(k*n*n) complexity.
// Below introduced solution obtains average O(k*k*n) complexity.
// Solution: Observed that a palindrome concatenated by two words indicates that
// one word must be prefix/suffix of reversed of other word and its left part substring
// also is palindrome.
// Algorithm: First build a map to record pair of index of each word and its reversed word.
// Then iterate all given unique words {O(n)} and for each word enumerate its all prefix/suffix
// substrings {O(k)} to check whether prefix/suffix substring exists in reversed-words-index-map {O(1)}
// and its corresponding left part substring is palindrome {O(k)}. Noticed that empty string "" also is
// prefix/suffix of any word.

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordsIndexMap;

        for (int i = 0; i < words.size(); i++) {
            wordsIndexMap[words[i]] = i;
            reverse(words[i].begin(), words[i].end());
        }

        vector<vector<int>> pairs;

        for (int j = 0; j < words.size(); j++) {
            for (int i = 0; i < words[j].size(); i++) {
                string left = words[j].substr(0, i);
                string right = words[j].substr(i, words[j].size() - i);

                if (isPalindrome(left) && wordsIndexMap.find(right) != wordsIndexMap.end() && j != wordsIndexMap[right]) {
                    pairs.push_back({j, wordsIndexMap[right]});
                }

                if (isPalindrome(right) && wordsIndexMap.find(left) != wordsIndexMap.end() && j != wordsIndexMap[left]) {
                    pairs.push_back({wordsIndexMap[left], j});
                }
            }
            if (isPalindrome(words[j])&& wordsIndexMap.find("") != wordsIndexMap.end() && j != wordsIndexMap[""]) {
                pairs.push_back({j, wordsIndexMap[""]});
            }
        }

        return pairs;
    }

    bool isPalindrome(const string &s) {
        int sz = s.size(), i = 0;
        while (i < sz / 2 && s[i] == s[sz - 1 - i])
            i++;
        return i == sz / 2;
    }
};

#endif //LEETCODE_SOLUTION_H
