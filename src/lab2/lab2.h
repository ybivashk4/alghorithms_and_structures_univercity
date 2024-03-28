/* int * or double * */
struct Complexity {
    double time;
    long long int operations;
    void out (int size) {
        cout << "array size is " << size << ",time is " << (double)time / CLOCKS_PER_SEC << " sec, " << "operations is " << operations << endl;
    }
};

template <typename T>
bool is_sorted(const T arr, int size);

template <typename T>
Complexity flag_bubble_sort(T arr, int size);

template <typename T>
Complexity last_index_bubble_sort(T arr, int size);

template <typename T>
Complexity heap_sort(T arr, int size);

template <typename T>
long int shift(T arr, int low, int high);

template <typename T>
Complexity bin_MSD_sort(T arr, int size, int max);