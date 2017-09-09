//
// Created by xohozu on 2017/9/9.
//

#include "Solution.h"

class Test {
public:
    void check() {
        vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                    {'S', 'F', 'C', 'S'},
                                    {'A', 'D', 'E', 'E'}};

        Solution s;

        cout << s.exist(board, "ABCCED") << endl;
        cout << s.exist(board, "SEE") << endl;
        cout << s.exist(board, "ABCB") << endl;
        cout << s.exist(board, "ABFCCESEEDAS") << endl;

        vector<vector<char>> board1 = {{'a', 'a'}};
        cout << s.exist(board1, "aaa") << endl;
    }
};
