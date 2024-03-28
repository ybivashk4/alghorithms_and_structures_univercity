#include <iostream>
#include "../lab1/lab1.h"
#include "lab2.h"
using namespace std;

// #ifdef lab2
int main () {
    long int arr_size = 2e4;
    int_array arr(arr_size);
    Complexity res;
    arr.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = flag_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    arr.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = last_index_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    arr_size = 5e6;
    int_array arr2(arr_size);
    arr2.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = heap_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    return 0;
}
// #endif
template <typename T>
bool is_sorted(const T arr, int size) {
    bool flag = true;
    for (int i=0;i<size-1;i++) {
        if (arr[i] > arr[i+1]) {
            flag = false;
            break;
        }
    }
    return flag;
}


template <typename T>
Complexity flag_bubble_sort(T arr, int size) {
    Complexity res;
    res.time = clock();
    res.operations = 0;
    bool flag = true;
    int buf2;
    for (int i=0;i<size;i++) {
        res.operations++;
        if (!flag) break;
        flag = false;
        for (int j=0;j<size-1;j++) {
            res.operations += 1;
            if (arr[j] > arr[j+1]) {
                flag = true;
                buf2 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buf2;
            }
            
        }
        
        
    }
    res.time = (clock()-res.time);
    return res;
}

template <typename T>
Complexity last_index_bubble_sort(T arr, int size) {
    Complexity res;
    res.time = clock();
    res.operations = 0;
    int buf2;
    for (int i=0;i<size;i++) {
        res.operations++;
        for (int j=0;j<size-1-i;j++) {
            res.operations += 1;
            if (arr[j] > arr[j+1]) {
                buf2 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buf2;
            }
            
        }
        
        
    }
    res.time = (clock()-res.time);
    return res;
}

template <typename T>
Complexity heap_sort(T arr, int size) {
    Complexity res;
    int buf;
    res.time = clock();
    res.operations = 0;
    res.operations++;
    if (size > 1) {
        for (int i = (size-1)/2; i >=0; i--)
            res.operations += shift(arr,i,size-1);
        for (int i = size-1; i >=1; i--) {
            buf = arr[0]; arr[0] = arr[i]; arr[i] = buf;
            res.operations += shift(arr,0,i-1);
        }
    }
    res.time = (clock()-res.time);
    return res;
}

template <typename T>
long int shift(T arr, int low, int high) {
    int ind = 2*low + 1;
    int buf;
    long int operations=0;
    operations++;
    while(ind <= high) {
        operations++;
        if (ind < high && arr[ind+1] > arr[ind]) ind++;
        operations++;
        if (arr[low] >= arr[ind]) break;
        // Swap(A[ind],A[Low]);
        buf = arr[ind]; arr[ind] = arr[low]; arr[low] = buf;
        low = ind;
        ind = 2*low + 1;
    }
    return operations;
}
// 2, 3, 17, 19 {пилообразная}, int

