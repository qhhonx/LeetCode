//
// Created by xohozu on 8/14/15.
//
#include <vector>
using namespace std;

#include "Solution.h"


class Test {
public:
    void check() {
        vector<int> gas = {3, 5, 1, 4, 3, 2};
        vector<int> cost = {5, 1, 4, 2, 3, 1};

        vector<int> gas1 = {3, 1, 5, 1, 4, 3};
        vector<int> cost1 = {2, 3, 1, 5, 1, 4};

        vector<int> gas2 = {3, 2, 2, 1, 4, 6};
        vector<int> cost2 = {6, 3, 1, 5, 1, 2};
        Solution s;
        cout << s.canCompleteCircuit(gas, cost) << endl;
        cout << s.canCompleteCircuit(gas1, cost1) << endl;
        cout << s.canCompleteCircuit(gas2, cost2) << endl;
    }
};