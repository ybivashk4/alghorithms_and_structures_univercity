
#define lab2
#ifndef l2
#define l2
struct Complexity {
    double time;
    long long int operations;
    void out (int size) {
        //std::cout << "array size is " << size << ",time is " << ((double)time / CLOCKS_PER_SEC) * 1000 << " msec, " << "operations is " << operations << std::endl;
        std::cout << size << " " << ((double)time / CLOCKS_PER_SEC) * 1000 << " " << operations << std::endl;
    }
};

void serviece_out(int set, int sort);

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
Complexity msd_sort(T arr, int size);

template <typename T>
void MS_radix(T arr, int low, int high, uint mask) ;

template <typename T>
int radix_partition(T arr, int low, int high, uint mask);

template <typename T>
Complexity std_sort(T arr, int size);


#endif