//
// Created by dream on 2020/11/18.
//

#include <vector>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();

        backtraing(nums, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;

    void backtraing(vector<int>& nums, int startIndex){
        res.push_back(path);
        if (startIndex >= nums.size()){
            return ;
        }

        for (int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtraing(nums, i+1);
            path.pop_back();
        }
    }
};


int main(){
    vector<int> nums {1, 2, 3};

    vector<vector<int>> res = {{},
                               {1},
                               {1, 2},
                               {1, 2, 3},
                               {1, 3},
                               {2},
                               {2, 3},
                               {3}
                               };
    Solution sol;
    assert(sol.subsets(nums) == res);
    return 0;
}