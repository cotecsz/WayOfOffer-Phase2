//
// Created by dream on 2020/11/22.
//

#include <iostream>
using namespace std;

/*
 * 小和问题：数组中的每个数，左侧比他小的数的累加和。
 *
 *      1. 转换为右侧有几个数大于该数，则 arr[i] * N
 *      2. 利用归并排序，在每次比较时，当右侧数大于该数时，则累加 arr[p1] * (high - R2 +1)
 */
class Solution{
public:
    int littleSum(int arr[], int length){
        if (length < 2){
            return 0;
        }

        return process(arr, 0, length-1);
    }

private:
    int process(int arr[], int low, int high){
        if (low == high){
            return 0;
        }

        int mid = low + ((high - low) >> 1);
        return process(arr, low, mid)
             + process(arr, mid+1, high)
             + merge(arr, low, mid, high);
    }

    int merge(int arr[], int low, int mid, int high){
        int* helper = new int[high - low + 1];
        int res = 0;

        int i = 0;
        int p1 = low;
        int p2 = mid+1;
        while (p1 <= mid && p2 <= high){
            res += arr[p1] < arr[p2] ? (high - p2 + 1)* arr[p1] : 0;       // 右侧有几个数比左侧数大，则累加
            // 与归并排序不同，这里是严格小于，在arr[p1] = arr[p2] 时，
            // 优先将右侧的数，存放至额外空间中
            helper[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }

        while (p1 <= mid){
            helper[i++] = arr[p1++];
        }
        while (p2 <= high){
            helper[i++] = arr[p2++];
        }

        for (i = 0; i < high - low + 1; i++){
            arr[low+i] = helper[i];             // 将 helper [0, high-low+1) 的值赋给 arr[low, low + high -low+1)
        }

        for (int j = 0; j < high-low+1; j++) {
            cout << arr[low+ j] << " ";
        }
        cout << endl;

        delete [] helper;
        return res;
    }
};


int main(){
    int arr[] = {7, 2, 3, 6, 8, 3, 4, 7};

    Solution sol;
    int res = sol.littleSum(arr, 8);

    cout << res << endl;
    return 0;
}