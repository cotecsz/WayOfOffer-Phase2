//
// Created by dream on 2020/11/24.
//

#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int> &nums) {
        int less = -1;
        int more = nums.size();
        int index = 0;
        while (index < more){
            if (nums[index] == 0){
                swap(nums[index++], nums[++less]);
            }
            else if (nums[index] == 2){
                swap(nums[index], nums[--more]);
            }
            else{
                index++;
            }
        }
    }
};