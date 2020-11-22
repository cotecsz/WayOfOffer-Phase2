//
// Created by dream on 2020/11/22.
//

#include <vector>
#include <iostream>
using namespace std;

/*
 * 归并排序：
 *    1. 排序左侧数组 [low, mid]
 *    2. 排序右侧数组 [mid + 1， high]
 *    3. 合并
 *
 */
class Solution{
public:
    void mergeSort(int arr[], int length){
        if ( length < 2){
            return ;
        }

        return process(arr, 0, length-1);
    }
private:
    void process (int arr[], int low, int high){
        if (low == high){
            return ;
        }

        int mid = low + ((high - low) >> 1);
        process(arr, low, mid);
        process(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    void merge (int arr[], int low, int mid, int high){
        int* helper = new int[high - low + 1];

        int i = 0;
        int p1 = low;
        int p2 = mid + 1;
        while (p1 <= mid && p2 <= high){
            helper[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        }

        while (p1 <= mid){
            helper[i++] = arr[p1++];
        }
        while (p2 <= high){
            helper[i++] = arr[p2++];
        }

        for (int j = 0; j < high-low+1; j++){
            arr[low + j] = helper[j];
        }

        for (int j = 0; j < high-low+1; j++) {
            cout << arr[low + j] << " ";
        }
        cout << endl;
        delete[] helper;
    }

};


int main(){
    int arr[] = {1, 3, 2, 8, 5, 0, 9, 6};

    Solution sol;
    sol.mergeSort(arr, 8);
    return 0;
}