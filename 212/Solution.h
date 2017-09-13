//
// Created by xohozu on 2017/9/11.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/**
 * Trie + Backtracking(DFS)
 */
class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        int value;

        TrieNode() : value(-1) { }
        ~TrieNode() { for (auto item: next) delete item.second; }
    };

    void buildTrie(TrieNode &root, int index, const string &word, int wb) {
        if (wb < word.size()) {
            char ch = word[wb];
            if (root.next.find(ch) == root.next.end()) {
                root.next[ch] = new TrieNode();
            }
            if (wb == word.size() - 1) {
                root.next[ch]->value = index;
            } else {
                buildTrie(*root.next[ch], index, word, wb + 1);
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty()) return {};

        TrieNode root;
        for (int i = 0; i < words.size(); ++i) {
            buildTrie(root, i, words[i], 0);
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        unordered_set<int> foundIndices;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i][j] = true;
                char ch = board[i][j];
                if (root.next.find(ch) != root.next.end()) {
                    traverseTrie(*root.next[ch], board, make_pair(i, j), visited, foundIndices);
                }
                visited[i][j] = false;
            }
        }

        vector<string> matchWords;
        for (auto index: foundIndices) {
            matchWords.push_back(words[index]);
        }

        return matchWords;
    }

    void traverseTrie(TrieNode &root, vector<vector<char>>& board, pair<int, int> start, vector<vector<bool>> &visited, unordered_set<int> &indices) {
        if (root.value != -1) indices.insert(root.value);  // found one word

        if (root.next.empty()) return;

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (root.next.find(ch) == root.next.end()) continue;

            for (auto direction: directions) {
                auto next = make_pair(start.first + direction.first, start.second + direction.second);
                if (inBoard(board, next) && !visited[next.first][next.second] && board[next.first][next.second] == ch) {
                    visited[next.first][next.second] = true;
                    traverseTrie(*root.next[ch], board, next, visited, indices);
                    visited[next.first][next.second] = false;
                }
            }
        }
    }

    bool inBoard(vector<vector<char>> &board, pair<int, int> pos) {
        if (pos.first >= 0 && pos.first < board.size() && pos.second >= 0 && pos.second < board[0].size()) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODE_SOLUTION_H
