//
// Created by xohozu on 15-5-11.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        type = UNCOMPLETED;
    }
    enum Type {UNCOMPLETED, COMPLETED} type;
    TrieNode *child[26] = {nullptr};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        int idx;
        for (int i = 0; i < s.length(); i++) {
            idx = s[i] - 'a';
            if (!p->child[idx]) {
                p->child[idx] = new TrieNode();
            }
            p = p->child[idx];
        }
        p->type = TrieNode::COMPLETED;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        int i, idx;
        for (i = 0; i < key.length(); i++) {
            idx = key[i] - 'a';
            if (p->child[idx]) {
                p = p->child[idx];
            } else break;
        }
        return i == key.length() && p->type == TrieNode::COMPLETED;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        int i, idx;
        for (i = 0; i < prefix.length(); i++) {
            idx = prefix[i] - 'a';
            if (p->child[idx]) {
                p = p->child[idx];
            } else break;
        }
        return i == prefix.length();
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif //LEETCODE_SOLUTION_H
