#include <iostream>
#include <ctime>
#include <cstdlib>
#define interval 10
using namespace std;

class double_array {
	public:
		int size;
		double * arr;
		void output() {
			for (int i=0;i<size;i++) 
				printf("%lg ", arr[i]);
			printf("\n");
		}
		void gen_rand() {
			for (int i=0;i<size;i++)
				arr[i] = rand() * (1.0 / (i+1));
		}
		void gen_up(int n) {
			int i = 0;
			double j = 0.1;
			for (i=0;i<n;i++) {
				arr[i] = j;
				j += 0.2;
			}
		}
		void gen_down(int n) {
			int i = 0;
			double j = 0.1 + 0.2 * n;
			for (i=0;i<n;i++) {
				arr[i] = j;
				j -= 0.2;
			}
		}
		double_array(int n) {
			arr = new double[n];
			size = n;
		}
		~double_array() {
			delete arr;
		}
};

class int_array {
	private:
		int * arr;
		int size;
	public:
		void output() {
			for (int i=0;i<size;i++) 
				printf("%d ", arr[i]);
			printf("\n");
		}
		void gen_rand(int min_val, int max_val) {
			for (int i=0;i<size;i++)
				arr[i] = rand() % max_val + min_val;
		}
		void gen_up(int min_val, int max_val, int step) {
			int val = min_val;
			int i = 0;
			for (i=0;i<size;i++) {
				arr[i] = val;
				val += step;
			}
		}
		void gen_down(int min_val, int max_val, int step) {
			int val = max_val;
			int i = 0;
			for (i=0;i<size;i++) {
				arr[i] = val;
				val -= step;
			}
		}
		// interval = 10
		void sin_gen(int min_val, int max_val) {
			int mid, i = 0, n = size, j = 0, k = 0;
			mid = interval / 2;
			while (n - interval >= 0) {
				for (i=0+j;i<mid+j;i++) {
					arr[i] = size-k;
					k++;
				}
				for (i=mid+j;i<interval+j;i++) {
					arr[i] = k;
					k++;
				}
				n -= interval;
				j += interval;
				k=0;
			}
			// не влезло 
			for (i=size-n;i<size;i++) {
				arr[i] = 0;
			}
		}

		//a1 < a2 > a3 < … > an-1 < an
		void sawtooth_gen(int n) {
			int mx = n;
			int mn = 0;
			int i=0;
			for (i=0;i<n;i++) {
				if (i % 2 == 0) {
					arr[i] = mn;
					mn++;
				}
				if (i % 2 == 1) {
					arr[i] = mx;
					mx--;
				}
			}
		}
		int_array(int n) {
			arr = new int[n];
			size = n;
		}
		~int_array() {
			delete arr;
		}
};




void start_gen(double_array * gen_1, int_array * gen_2, int n) {
	printf("---------------------\nstart double generation\nup_sorted:\n");
	up_sort_gen::gen_double(gen_1->double_arr, n);
	gen_1->output();
	printf("down_sorted:\n");
	down_sort_gen::gen_double(gen_1->double_arr, n);
	gen_1->output();
	printf("random:\n");
	gen_1->gen_rand();
	gen_1->output();
	printf("---------------------\nstart int generation\nup_sorted:\n");
	up_sort_gen::gen_int(gen_2->int_arr, n);
	gen_2->output();
	printf("down_sorted:\n");
	down_sort_gen::gen_int(gen_2->int_arr, n);
	gen_2->output();
	printf("random:\n");
	gen_2->gen_rand();
	gen_2->output();
	printf("sawtooth\n");
	sawtooth_gen(gen_2->int_arr, n);
	gen_2->output();
	printf("sin_gen\n");
	sin_gen(gen_2->int_arr, n);
	gen_2->output();	
}

int main(){
	srand(time(NULL));
	int n = 0;
	printf("enter size of array\n");
	scanf("%d", &n);
	double_array gen_1(n);
	int_array gen_2(n);
	start_gen(&gen_1, &gen_2, n);
	
	
	system("pause");
	return 0;
}
/*
Квази-упорядоченная последовательность – это последовательность, в которой имеется
ограниченное количество инверсий (количество элементов, для которых не
выполняется отношение порядка) и оно много меньше размера последовательности.
*/