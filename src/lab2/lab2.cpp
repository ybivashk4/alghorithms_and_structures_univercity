#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../lab1/lab1.h"
#include "lab2.h"
#include <algorithm>
using namespace std;

// accounting operation in MSD, what is s-heap, 
// add qsort
#ifdef lab2
int main () {
    long int arr_size = 2e4;
    int_array arr(arr_size);
    Complexity res;

    /* bubble sort with flag */
    serviece_out(1, 1);
    arr.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = flag_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    serviece_out(1, 2);
    arr.gen_up(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = flag_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    serviece_out(1, 3);
    arr.gen_rand(1, arr_size);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = flag_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    serviece_out(1, 4);
    arr.sawtooth_gen(1, arr_size);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = flag_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    /* bubble sort last index */

    serviece_out(2, 1);
    arr.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = last_index_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);


    serviece_out(2, 2);
    arr.gen_up(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = last_index_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    serviece_out(2, 3);
    arr.gen_rand(1, arr_size);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = last_index_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    serviece_out(2, 4);
    arr.sawtooth_gen(1, arr_size);
    cout << "arr before sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res = last_index_bubble_sort(arr.get_arr(), arr.get_size());
    cout << "arr after sort " << is_sorted(arr.get_arr(), arr.get_size()) << endl;
    res.out(arr_size);

    /* heap sort */

    arr_size = 5e6;
    int_array arr2(arr_size);

    serviece_out(3, 1);
    arr2.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = heap_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(3, 2);
    arr2.gen_up(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = heap_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(3, 3);
    arr2.gen_rand(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = heap_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(3, 4);
    arr2.sawtooth_gen(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = heap_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    /* MSD sort*/

    serviece_out(4, 1);
    arr2.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = msd_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(4, 2);
    arr2.gen_up(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = msd_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(4, 3);
    arr2.gen_rand(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = msd_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(4, 4);
    arr2.sawtooth_gen(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = msd_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    /* std sort*/

    serviece_out(5, 1);
    arr2.gen_down(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = std_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(5, 2);
    arr2.gen_up(1, arr_size, 1);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = std_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(5, 3);
    arr2.gen_rand(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = std_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    serviece_out(5, 4);
    arr2.sawtooth_gen(1, arr_size);
    cout << "arr before sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res = std_sort(arr2.get_arr(), arr2.get_size());
    cout << "arr after sort " << is_sorted(arr2.get_arr(), arr2.get_size()) << endl;
    res.out(arr_size);

    return 0;
}
#endif
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
        buf = arr[ind]; arr[ind] = arr[low]; arr[low] = buf;
        low = ind;
        ind = 2*low + 1;
    }
    return operations;
}

template <typename T>
Complexity msd_sort(T arr, int size) {
    int i; uint mask = 0;
    Complexity res = {0};
    res.time = clock();
    for (i = 0; i < size; i++) mask |= (uint)arr[i];
    for (i = 31; i >=1; i--) if(mask & (1 << i)) break;
    MS_radix(arr,0,size-1,1<<i);
    res.time = (clock()-res.time);
    return res;
}

template <typename T>
void MS_radix(T arr, int low, int high, uint mask) {
    int i;
    if(mask > 0 && low < high) {
        i = radix_partition(arr,low,high,mask);
        MS_radix(arr, low, i-1, mask>>1);
        MS_radix(arr, i, high, mask>>1);
    }
    
}

template <typename T>
int radix_partition(T arr, int low, int high, uint mask) {
    int i = low-1, j = high+1;
    int buf;
    for(;;) {
        while((!(mask & (uint)arr[++i])) && i < high);
        while( (mask & (uint)arr[--j]) && j > low);
        if(i >= j) break;
        buf = arr[i]; arr[i] = arr[j]; arr[j] = buf;
    }
    if (i == j && i == high) i++; return i;
}
// 2, 3, 17, 19 {пилообразная}, int

template <typename T>
Complexity std_sort(T arr, int size) {
    Complexity res = {0};
    res.time = clock();
    std::sort(arr, arr+size);
    res.time = (clock()-res.time);
    return res;
}

void serviece_out(int set, int sort) {
    switch(set) {
        case 1:
            cout << "down gen " << endl;
            break;
        case 2:
            cout << "up gen " << endl;
            break;
        case 3:
            cout << "rand gen " << endl;
            break;
        case 4:
            cout << "sawtooth gen " << endl;
            break;
    }
    switch (sort) {
        case 1:
            cout << "bubble sort with flag" << endl;
            break;
        case 2:
            cout << "bubble sort last index" << endl;
            break;
        case 3:
            cout << "heap sort" << endl;
            break;
        case 4:
            cout << "msd sort" << endl;
            break;
        case 5:
            cout << "std sort" << endl;
            break;
    }

}