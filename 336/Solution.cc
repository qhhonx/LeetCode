//
// Created by xohozu on 2017/7/31.
//

#include "Solution.h"

class Test {
public:
    void check() {

        // string s1[] = {"bat", "tab", "cat"};
        string s1[] = {"a", ""};

        vector<string> vs1(s1, s1 + 2);

        vector<string> vs2 = {"abcd", "dcba", "lls", "s", "sssll"};

        Solution solution;

        vector<vector<int> > a1 = solution.palindromePairs(vs1);

        for(auto r: a1)
            cout << "[" << r[0] << "," << r[1] << "]" << endl;

        cout << endl;

        auto a2 = solution.palindromePairs(vs2);

        for(auto r: a2)
            cout << "[" << r[0] << "," << r[1] << "]" << endl;
    }
};
