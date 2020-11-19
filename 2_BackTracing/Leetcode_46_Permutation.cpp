//
// Created by dream on 2020/11/19.
//

#include <vector>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();

        vector<bool> used(nums.size(), false);
        backtracing(nums, used);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracing(vector<int>& nums, vector<bool>& used){
        if (path.size() == nums.size()){
            res.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++){
            if (used[i] == true)    continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracing(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};


int main(){
    vector<int> nums {1, 2, 3};
    vector<vector<int>> res = {{1, 2, 3},
                               {1, 3, 2},
                               {2, 1, 3},
                               {2, 3, 1},
                               {3, 1, 2},
                               {3, 2, 1}};

    Solution sol;
    assert(sol.permute(nums) == res);
    return 0;
}