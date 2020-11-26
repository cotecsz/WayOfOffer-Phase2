//
// Created by dream on 2020/11/24.
//

#include <iostream>
#include <cstdlib>          // rand
using namespace std;

/*
 * 快速排序Version1：
 *     1. 取数组最后一个数作为主元pivot
 *     2. 将小于等于主元的数划分到数组左侧，大于主元的数划分到数组右侧
 *     3. 交换 主元与 数组右侧的第一个数
 *     4. 递归将左侧数组 与 数组右侧继续进行partition
 *
 *
 *     效果：每次仅将最后一位数排好顺序。
 */
class QuickSort_1_0{
public:
    void quickSort(int arr[], int length){
        return partition(arr, 0, length-1);
    }

private:
    void partition(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        int less = low - 1;
        int more = high;
        int index = low;        // index 是从区间最左侧开始
        while (index < more){
            if (arr[index] > arr[high]){
                swap(arr[index], arr[--more]);
            }
            else{
                swap(arr[index++], arr[++less]);
            }
        }

        swap (arr[high], arr[more]);        // 分组有序后，交换最后一个数与右侧的第一个数
        partition(arr, low, index - 1);
        partition(arr, index + 1, high);
    }
};


class QuickSort_1_0_Rewriting{
public:
    void quickSort(int arr[], int length){
        return quickSort(arr, 0, length-1);
    }

private:
    void quickSort(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

    int partition(int arr[], int low, int high){
        int less = low - 1;
        int more = high;
        int index = low;        // index 是从区间最左侧开始
        while (index < more){
            if (arr[index] > arr[high]){
                swap(arr[index], arr[--more]);
            }
            else{
                swap(arr[index++], arr[++less]);
            }
        }

        swap (arr[high], arr[more]);        // 分组有序后，交换最后一个数与右侧的第一个数
        return index;
    }
};

/*
 * 快速排序 Version2
 *
 * 优化： 每次将等于最后的所有数都进行排序
 *
 *     1. 取数组最后一个数作为主元pivot
 *     2. 将小于等于主元的数划分到数组左侧，等于主元的数，直接判断下一个数，大于主元的数划分到数组右侧
 *     3. 交换 主元与 数组右侧的第一个数
 *     4. 递归将左侧数组 与 数组右侧继续进行partition
 *
 */
class QuickSort_2_0{
public:
    void quickSort(int arr[], int length){
        return partition(arr, 0, length - 1);
    }

private:
    void partition(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        int less = low - 1;     // less 是小于主元的上一个位置
        int more = high ;       // more 是大于主元的下一个位置
        int index = low;
        while (index < more){
            if (arr[index] < arr[high]){
                swap(arr[index++], arr[++less]);
            }
            else if (arr[index] == arr[high]){
                index++;
            }
            else{
                swap(arr[index], arr[--more]);
            }
        }

        for (int i = low; i <= high; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        swap(arr[high], arr[more]);

        for (int i = low; i <= high; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;
        partition(arr, low, less);          // [low, less] 排序
        partition(arr, ++more, high);       // [more + 1, high] 排序
    }
};


class QuickSort_2_0_Rewriting{
public:
    void quickSort(int arr[], int length){
        return quickSort(arr, 0, length - 1);
    }

private:

    void quickSort(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        pair<int, int> p = partition(arr, low, high);
        quickSort(arr, low, p.first - 1);          // [low, less] 排序
        quickSort(arr, p.second + 1, high);         // [more + 1, high] 排序
    }
    pair<int, int> partition(int arr[], int low, int high){
        int less = low - 1;     // less 是小于主元的上一个位置
        int more = high ;       // more 是大于主元的下一个位置
        int index = low;
        while (index < more){
            if (arr[index] < arr[high]){
                swap(arr[index++], arr[++less]);
            }
            else if (arr[index] == arr[high]){
                index++;
            }
            else{
                swap(arr[index], arr[--more]);
            }
        }

        for (int i = low; i <= high; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        swap(arr[high], arr[more]);

        for (int i = low; i <= high; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;

        // 返回等于主元的左边界和右边界
        return {less + 1, more};
    }
};


/*
 * 快速排序 Version3.0
 *
 * 优化：主元随机选择。随机选择一个数，与最后一个数进行交换，作为主元。
 *
 *     0. 数组中随机选择一个数，与数组中最后一个数进行交换
 *     1. 取数组最后一个数作为主元pivot
 *     2. 将小于等于主元的数划分到数组左侧，等于主元的数，直接判断下一个数，大于主元的数划分到数组右侧
 *     3. 交换 主元与 数组右侧的第一个数
 *     4. 递归将左侧数组 与 数组右侧继续进行partition
 *
 */
class QuickSort_3_0{
public:
    void quickSort(int arr[], int length){
        return partition(arr, 0, length - 1);
    }
private:
    void partition(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        int randIdx = rand() % (high - low + 1);
        swap(arr[high], arr[low + randIdx]);        // 从low 开始的第i个

        int less = low - 1;
        int more = high ;
        int index = low;
        while (index < more){
            if (arr[index] < arr[high]){
                swap(arr[index++], arr[++less]);
            }
            else if (arr[index] == arr[high]){
                index++;
            }
            else{
                swap(arr[index], arr[--more]);
            }
        }


        swap(arr[high], arr[more]);

        partition(arr, low, less);
        partition(arr, ++more, high);
    }
};

class QuickSort_3_0_Rewriting{
public:
    void quickSort(int arr[], int length){
        return quickSort(arr, 0, length - 1);
    }
private:

    void quickSort(int arr[], int low, int high){
        if (low >= high){
            return ;
        }

        int randIdx = rand() % (high - low + 1);
        swap(arr[high], arr[low + randIdx]);          // 从low 开始的第i个数，作为主元，与最后一个数交换

        pair<int, int> p = partition(arr, low, high);       // 划分
        quickSort(arr, low, p.first - 1);              // 左侧快排
        quickSort(arr, p.first+1, high);                // 右侧快排
    }

    /*
     * 通过partition，分为
     *
     */
    pair<int, int> partition(int arr[], int low, int high){
        int less = low - 1;
        int more = high ;
        int index = low;
        while (index < more){
            if (arr[index] < arr[high]){
                swap(arr[index++], arr[++less]);
            }
            else if (arr[index] == arr[high]){
                index++;
            }
            else{
                swap(arr[index], arr[--more]);
            }
        }


        swap(arr[high], arr[more]);
        // 返回等于主元的左边界和右边界
        return {less + 1, more};

    }
};


int main(){
    int arr[] = {1, 3, 2, 8, 5, 0, 9, 6};

//    QuickSort_1_0 QS;
//    QS.quickSort(arr, 8);

//    QuickSort_2_0 QS_2_0;
//    QS_2_0.quickSort(arr, 8);

//    QuickSort_3_0 QS_3_0;
//    QS_3_0.quickSort(arr, 8);

    QuickSort_1_0_Rewriting QS_1_0_RW;
    QS_1_0_RW.quickSort(arr, 8);

//    QuickSort_2_0_Rewriting QS_2_0_RW;
//    QS_2_0_RW.quickSort(arr, 8);

//    QuickSort_3_0_Rewriting QS_3_0_RW;
//    QS_3_0_RW.quickSort(arr, 8);
    for (int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}