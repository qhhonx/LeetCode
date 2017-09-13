//
// Created by xohozu on 2017/9/11.
//

#include "Solution.h"

class Test {
public:
    void check() {
        vector<vector<char>> board =
                {{'o','a','a','n'},
                 {'e','t','a','e'},
                 {'i','h','k','r'},
                 {'i','f','l','v'}};

        Solution s;

        vector<string> words = {"oath","pea","eat","rain"};
        auto foundWords = s.findWords(board, words);

        copy(foundWords.begin(), foundWords.end(), ostream_iterator<string>(cout, " "));
        cout << endl;

        vector<vector<char>> board1 = {{'a'}};
        vector<string> words1 = {"a", "a"};

//        vector<vector<char>> board1 = {{'a', 'a'}};
//        vector<string> words1 = {"a"};

//        vector<vector<char>> board1 = {{'a', 'b', 'c'}, {'a', 'e', 'd'}, {'a', 'f', 'g'}};
//        vector<string> words1 = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};

        foundWords = s.findWords(board1, words1);
        copy(foundWords.begin(), foundWords.end(), ostream_iterator<string>(cout, " "));
    }
};
