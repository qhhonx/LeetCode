//
// Created by xohozu on 15-5-11.
//

#include "Solution.h"
#include <iostream>

using namespace std;

class Test {
public:
    void check() {
        Trie trie;
        trie.insert("abc");
        cout << "insert: abc" << endl;
        cout << "search: abc -> " << trie.search("abc") << endl;
        cout << "search: ab -> " << trie.search("ab") << endl;
        trie.insert("ab");
        cout << "insert: ab" << endl;
        cout << "search: ab -> " << trie.search("ab") << endl;
        trie.insert("ab");
        cout << "insert: ab" << endl;
        cout << "search: ab -> " << trie.search("ab") << endl;
    }
};