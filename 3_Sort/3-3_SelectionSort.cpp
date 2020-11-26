//
// Created by dream on 2020/11/22.
//

#include <iostream>
using namespace std;

/*
 * 选择排序：
 *     基本思想：将数组分为有序区（[0, i]）和无序区([i+1, length -1 ])，每次迭代遍历无序区的每一个元素，
 *              找出最小的元素，存放至有序区。
 *
 */
class SelectionSort{
public:
    void selectionSort(int arr[], int length){
        int i, j, min_idx;

        for (i = 0; i < length; i++){
            min_idx = i;
            for (j = i + 1; j < length; j++){
                if (arr[j] < arr[min_idx]){
                    min_idx = j;
                }
            }
            swap(arr[i], arr[min_idx]);
        }
    }
};

void printArray(int arr[], int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 3, 2, 8, 5, 0, 9, 6};

    SelectionSort selSort;
    selSort.selectionSort(arr, 8);
    printArray(arr, 8);


    return 0;
}