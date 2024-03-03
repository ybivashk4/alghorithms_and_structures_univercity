#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

namespace up_sort_gen{
	void gen_double(double * arr, int n) {
		int i = 0;
		double j = 0.1;
		for (i=0;i<n;i++) {
			arr[i] = j;
			j += 0.2;
		}
	}
	void gen_int(int * arr, int n) {
		int i = 0;
		for (i=0;i<n;i++) {
			arr[i] = i;
		}
	}
};

namespace down_sort_gen{
	void gen_double(double * arr, int n) {
		int i = 0;
		double j = 0.1 + 0.2 * n;
		for (i=0;i<n;i++) {
			arr[i] = j;
			j -= 0.2;
		}
	}
	void gen_int(int * arr, int n) {
		int i = 0;
		for (i=0;i<n;i++) {
			arr[i] = n - i;
		}
	}
};

class double_array {
	public:
		int size;
		double * double_arr;
		void output() {
			for (int i=0;i<size;i++) 
				printf("%lg ", double_arr[i]);
			printf("\n");
		}
		void gen_rand() {
			for (int i=0;i<size;i++)
				double_arr[i] = rand() * (1.0 / (i+1));
		}
		double_array(int n) {
			double_arr = new double[n];
			size = n;
		}
		~double_array() {
			delete double_arr;
		}
};

class int_array {
	public:
		int * int_arr;
		int size;
		void output() {
			for (int i=0;i<size;i++) 
				printf("%d ", int_arr[i]);
			printf("\n");
		}
		void gen_rand() {
			for (int i=0;i<size;i++)
				int_arr[i] = rand();
		}
		int_array(int n) {
			int_arr = new int[n];
			size = n;
		}
		~int_array() {
			delete int_arr;
		}
};
// разбить на интервалы 
void sin_gen(int * arr, int n) {
	int mid = n / 2;
	int i=0;
	for (i=0;i<mid;i++) {
		arr[i] = n-i;
	}
	for (i=mid;i<n;i++) {
		arr[i] = i;
	}
}

void sawtooth_gen(int * arr, int n) {
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
