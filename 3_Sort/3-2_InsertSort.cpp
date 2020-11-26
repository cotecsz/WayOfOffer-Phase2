//
// Created by dream on 2020/11/21.
//

#include <vector>

void insertSort(int arr[], int n ){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];           // 进行排序的记录key
        j = i - 1;              // key 要插入的位置，初始为key前一个位置 i-1


        // 在 [0, i-1] 依次向前查找，如果 key 大于前一个元素，则将前一个元素arr[j]后移，直到 key >= 前一个元素arr[j]
        while (j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];      // 后移
            j--;
        }

        arr[j+1] = key;             // 后移完成，j + 1 位置即为 key 的位置，直接赋值
    }
}


int main(){
    int arr[5] = {3, 2, 4, 1, 5};
    insertSort(arr, 5);
    return 0;
}