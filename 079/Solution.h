//
// Created by xohozu on 2017/9/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i][j] = true;
                if (word[0] == board[i][j] && dfs(board, {i, j}, word, 1, visited)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, pair<int, int> start, string &word, int wb, vector<vector<bool>> &visited) {
        if (wb >= word.size()) return true;

        for (auto direction: directions) {
            auto next = make_pair(start.first + direction.first, start.second + direction.second);
            if (inBoard(board, next) && !visited[next.first][next.second] && board[next.first][next.second] == word[wb]) {
                visited[next.first][next.second] = true;
                if (dfs(board, next, word, wb + 1, visited)) {
                    return true;
                }
                visited[next.first][next.second] = false;
            }
        }

        return false;
    }

    bool inBoard(vector<vector<char>> &board, pair<int, int> pos) {
        if (pos.first >= 0 && pos.first < board.size() && pos.second >= 0 && pos.second < board[0].size()) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODE_SOLUTION_H
