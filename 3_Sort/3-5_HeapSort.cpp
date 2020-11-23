//
// Created by dream on 2020/11/23.
//

#include <iostream>
using namespace std;


class Heap{
public:
    void heapSort(int arr[], int length){
        for (int i = 0; i < length; i++){
            heapInsert(arr, i);
        }

        int heapSize = length;
        swap( arr[0], arr[--heapSize]);
        while (heapSize > 0){
            heapify(arr, 0, heapSize);
            swap(arr[0], arr[--heapSize]);
        }

        for (int i = 0; i < length; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    /*
     * heapInsert: 在堆中插入新元素
     * 参数：
     *    arr : 数组
     *    index : 在位置 index 处插入
     *
     * 实现：
     *    从index 位置开始，当元素大于父节点时，交换两个节点
     */
    void heapInsert(int arr[], int index){
        while (arr[index] > arr[(index - 1) / 2]){
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    /*
     * heapify ：堆的调整
     *
     * 参数：
     *     arr : 数组
     *     index : 位置 index 的元素
     *     heapSize: 堆的大小
     *
     * 实现：
     *     当 左节点存在时，判断左右节点的大小与父节点大小，
     *          若父节点（该元素）小于左右节点，则交换
     *          否则直接返回。
     *     完全二叉树的性质，利用 heapSize 判断下一层是否存在。
     */
    void heapify(int arr[], int index, int heapSize){
        int left = (2 * index) + 1;
        while (left < heapSize){
            int largestIdx = left + 1 < heapSize && arr[left] < arr[left + 1]?
                             left + 1 : left;
            largestIdx = arr[index] > arr[largestIdx] ? index : largestIdx;

            if (largestIdx == index){
                break   ;
            }

            swap(arr[index], arr[largestIdx]);
            index = largestIdx;
            left = (2 * index) + 1;
        }
    }

    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
};


int main(){
    int arr[] = {1, 3, 2, 8, 5, 0, 9, 6};

    Heap heap;
    heap.heapSort(arr, 8);

    return 0;
}