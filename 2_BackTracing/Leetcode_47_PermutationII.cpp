//
// Created by dream on 2020/11/19.
//

#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();

        sort(nums.begin(), nums.end());
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
            if (used[i] == true)    continue;           // 同一树枝的数被使用，则搜索下一个
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;  // 同一树层的数，已被使用，则直接剪枝

            used[i] = true;
            path.push_back(nums[i]);
            backtracing(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};


int main(){
    vector<int> nums {1, 1, 2};
    vector<vector<int>> res = {{1, 1, 2},
                               {1, 2, 1},
                               {2, 1, 1}};

    Solution sol;
    assert(sol.permuteUnique(nums) == res);
    return 0;
}
