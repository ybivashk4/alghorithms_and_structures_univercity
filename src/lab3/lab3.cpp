#include <iostream>
#include <cmath>
#include "lab3.h"

int main () {

    return 0;
}

// if can't find return -1
template <typename T>
int brutforce_search(T[] arr, int size, T to_find) {
    for (int i=0;i<size;i++) {
        if (arr[i] == to_find) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int jump_one_search(T[] arr, int size, T to_find) {
    int step = (int)sqrt(size), i=0;
    bool flag = false;
    if (arr[0] < to_find) {
        for (i=0;i<size;i+=step) {
            if (arr[i] >= to_find) {
                break;
            }
        }
        i -= step;
        for (;i<i+step;i++) {
            if (arr[i] == to_find) {
                flag = true;
                break;
            }
        }
        if (!flag) i = -1;
    }
    else i = -1;
    return i;
}

template <typename T>
int jump_multy_search(T[] arr, int size, T to_find) {
    int step = (int)sqrt(size), i=0;
    bool flag = false;
    if (arr[0] < to_find) {
        for (i=0;i<size;i+=step) {
            if (arr[i] >= to_find) {
                i -= step;
                step /= 2;
                if (step == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) i = -1;
    }
    else i = -1;
    return i;
}

template <typename T>
int interpolation_search(T[] arr, int size, T to_find) {
    // left + (key - a[left]) * (right - left) / (a[right] - a[left])
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (arr[left] < to_find && arr[right] > to_find) {
        mid = left + (to_find - arr[left]) * (right - left) / (arr[right] - arr[left]);
        if (arr[mid] > to_find) 
            left = mid + 1;
        else if (arr[mid] < to_find) 
            right = mid - 1;
        else 
            return mid;
    }
    return arr[left] == to_find ? left : (arr[right] == to_find ? right : -1);
}

// не ищет последний элемент 
template <typename T>
int binary_search(T[] arr, int size, T to_find) {
    int left = 0;
    int right = size - 1;
    int mid = (left + right) / 2;
    while (left <= right && arr[mid] != to_find) {
        if (arr[mid] == to_find) break;
        else if (arr[mid] > to_find) right = mid;
        else  left = mid;
        mid = (left+right) / 2;
    }
}
// 1 2 3 4 5 -> 5
/*


*/