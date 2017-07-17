//
// Created by xohozu on 2017/7/12.
//
#include <iostream>
#include <string>

#include "Solution.h"

using namespace std;

class Test {
public:
    void check() {
        string a = "babad";
        string a1 = "badabab";
        string a2 = "babadabc";
        string a3 = "aaaab";

        Solution s;

        cout << s.longestPalindrome(a) << endl;
        cout << s.longestPalindrome(a1) << endl;
        cout << s.longestPalindrome(a2) << endl;
        cout << s.longestPalindrome(a3) << endl;
    }
};