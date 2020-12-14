//
// Created by dream on 2020/12/14.
//

#include <vector>
#include "assert.h"

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++){
            res += max(prices[i] - prices[i-1], 0);
        }

        return res;
    }
};


int main(){

    vector<int> prices {7,1,5,3,6,4};

    Solution sol;
    assert(sol.maxProfit(prices) == 7);
    return 0;
}