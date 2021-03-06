//
// Created by dream on 2020/11/22.
//

#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;


class Solution{
public:
    int reversePairs(vector<int> nums){
        if (nums.size() < 2){
            return 0;
        }

        return process(nums, 0, nums.size()-1);
    }

private:
    int process(vector<int>& nums, int low, int high){
        if (low == high){
            return 0;
        }

        int mid = low + ((high - low) >> 1);
        return process(nums, low, mid)
            +  process(nums, mid+1, high)
            +  merge(nums, low, mid, high);
    }

    int merge(vector<int>& nums, int low, int mid, int high){
        int* helper = new int[high - low + 1];
        int res = 0;

        int i = 0;
        int p1 = low;
        int p2 = mid + 1;
        while (p1 <= mid && p2 <= high){
            // 当左侧数大于右侧数时，逆序对个数为 mid - p1 + 1 个
            res += nums[p1] > nums[p2] ? (mid - p1 + 1) : 0;
            // 当左右两侧数相等时，将右侧数先放入额外空间中，看左侧数是否比右侧数构成逆序对
            helper[i++] = nums[p1] <= nums[p2] ? nums[p1++] :nums[p2++];
        }

        while (p1 <= mid){
            helper[i++] = nums[p1++];
        }
        while (p2 <= high){
            helper[i++] = nums[p2++];
        }

        for (i=0; i < high-low+1; i++){
            nums[low+i] = helper[i];
        }

        for (int j = 0; j < high-low+1; j++) {
            cout << nums[low + j] << " ";
        }
        cout << "res = " <<res << " ";

        cout << endl;
        delete [] helper;
        return res;
    }
};

int main(){
    vector<int> nums {7, 5, 6, 4};
    vector<int> nums1 {1, 3, 2, 3, 1};


    Solution sol;
    assert(sol.reversePairs(nums) == 5);

    int res = sol.reversePairs(nums1);
    return 0;
}
