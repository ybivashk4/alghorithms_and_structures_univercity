#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lab1.h"
#include <cmath>
void int_array::output() {
	for (int i=0;i<size;i++) 
		printf("%d ", arr[i]);
	printf("\n");
}

void int_array::gen_rand(int min_val, int max_val) {
	for (int i=0;i<size;i++) {
		arr[i] = rand() % (max_val-min_val+1) + min_val;
	}

}

// max_val no control
void int_array::gen_up(int min_val, int max_val, int step) {
	int val = min_val;
	int i = 0;
	for (i=0;i<size;i++) {
		arr[i] = val;
		if (val+step <= max_val)
			val += step;
		else 
			val = max_val;
	}
}

void int_array::gen_down(int min_val, int max_val, int step) {
	int val = max_val;
	int i = 0;
	for (i=0;i<size;i++) {
		arr[i] = val;
		
		if (val-step >= min_val)
			val -= step;
		else 
			val = min_val;
	}
}

void int_array::sin_gen(int min_val, int max_val) {
	int mid, i = 0, n = size, j = 0, val = max_val, step=(max_val-min_val)/interval;
	mid = interval / 2;
	while (n - interval >= 0) {
		for (i=0+j;i<mid+j;i++) {
			arr[i] = val;
			if (val-step >= min_val)
				val -= step;
			else 
				val = min_val;
		}
		for (i=mid+j;i<interval+j;i++) {
			arr[i] = val;
			if (val+step <= max_val)
				val += step;
			else 
				val = max_val;
		}
		n -= interval;
		j += interval;
		val = max_val;
	}
}

//a1 < a2 > a3 < … > an-1 < an
void int_array::sawtooth_gen(int min_val, int max_val) {
	int i=0, j=0, mn = min_val, mx = max_val, l=0, n=size;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			if (i % 2 == l) {
				arr[i] = mn;
				mn++;
			}
			else {
				arr[i] = mx;
				mx--;
			}
		}
		l = (l+1)%2;
		n -= interval;
		j += interval;
		mx = max_val;
		mn = min_val;
	}
}

void int_array::step_gen(int min_val, int max_val) {
	int range = max_val - min_val, i=0, j=0, n=size, step = range / (n / interval) / 2, mn=step+min_val, mx = 2*step+min_val;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			arr[i] = rand() % (mx-mn+1) + mn;
		}
		n -= interval;
		j += interval;
		mn += 2 * step;
		mx += 2 * step;
	}
}

void int_array::kvazi_gen(int min_val, int max_val) {
	int i=0, j=0, n=size, val = min_val, step=(max_val-min_val)/interval, temp=0;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			arr[i] = val;
			
			if (val+step <= max_val)
				val += step;
			else 
				val = max_val;
		}
		// 3 инверсии
		i--;
		temp = arr[i-2];
		arr[i-2] = arr[i];
		arr[i] = temp;
		n -= interval;
		j += interval;
		val = min_val;
	}
}

void double_array::gen_down(double min_val, double max_val, double step) {
	double val = max_val;
	for (int i=0;i<size;i++) {
		if (val > min_val) {
			arr[i] = val;
			val -= step;
		}
		else {
			arr[i] = min_val;
		}	
	}
}

void double_array::gen_up(double min_val, double max_val, double step) {
	double val = min_val;
	for (int i=0;i<size;i++) {
		if (val < max_val) {
			arr[i] = val;
			val += step;
		}
		else {
			arr[i] = max_val;
		}	
	}
}

void double_array::gen_rand(double min_val, double max_val) {
	int dif = max_val - min_val;
	double temp = 0;
	if (dif > 0) {
		for (int i=0;i<size;i++) {
			arr[i] = (double)(rand() % dif) + min_val;
			
			temp = rand() % 500 + 500; // 0.5 - 0.999
			while (temp > 1) {
				temp /=10;
			}
			arr[i] *= temp;
			if (arr[i] < min_val) arr[i] = min_val;
		}
	}
	else if (dif == 0) {
		int count = 0;
		while (min_val < 1) {
			min_val *= 10;
			max_val *= 10;
			count++;
		}
		for (int i=0;i<size;i++)
			arr[i] = (double)(rand() % ((int)max_val - (int)min_val + 1) + (int)min_val) / pow(10, count);

	}
}

void double_array::output() {
	for (int i=0;i<size;i++) 
		printf("%lg ", arr[i]);
	printf("\n");
}

/*
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
	gen_2->output(	start_gen(&gen_1, &gen_2, n);
);
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
*/

int main(){
	srand(time(NULL));
	int n = 0;
	printf("enter size of array\n");
	scanf("%d", &n);
	double_array gen_1(n);
	int_array gen_2(n);
	/*int test
	gen_2.gen_down(0, 1000, 3);
	gen_2.output();
	gen_2.gen_up(0, 1000, 3);
	gen_2.output();
	gen_2.gen_rand(0, 1000);
	gen_2.output();
	printf("\n\n");
	gen_2.sawtooth_gen(0, 1000);
	gen_2.output();

	gen_2.sin_gen(0, 1000);
	gen_2.output();

	gen_2.step_gen(0, 1000);
	gen_2.output();

	gen_2.kvazi_gen(0, 1000);
	gen_2.output();
	*/
	gen_1.gen_up(0.123, 10.23, 2.7);
	gen_1.output();
	gen_1.gen_down(0.123, 10.23, 2.7);
	gen_1.output();
	gen_1.gen_rand(0.123, 10.23);
	gen_1.output();
	// Добавить проверку на ЧУМ - если ЧУМ выводить по интервалам, а не по сайзам
	return 0;
}
/*
Квази-упорядоченная последовательность – это последовательность, в которой имеется
ограниченное количество инверсий (количество элементов, для которых не
выполняется отношение порядка) и оно много меньше размера последовательности.
*/