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
	int i=0, j=0, mn = min_val, mx = max_val, l=0, n=size, step=(max_val-min_val)/interval;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			if (i % 2 == l) {
				arr[i] = mn;
				mn+=step;
			}
			else {
				arr[i] = mx;
				mx-=step;
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
		for (int i=0;i<size;i++) {
			arr[i] = (double)(rand() % ((int)max_val - (int)min_val + 1) + (int)min_val) / pow(10, count);
			temp = rand() % 1000 + 9000;
			while (temp > 1) {
				temp /=10;
			}
			arr[i] *= temp;
			if (arr[i] < min_val/pow(10, count)) arr[i] = min_val/pow(10, count);
			if (arr[i] > max_val/pow(10, count)) arr[i] = max_val/pow(10, count);
		}
			

	}
}


void double_array::sin_gen(double min_val, double max_val) {
	int mid, i = 0, n = size, j = 0;
	double val = max_val, step=(max_val-min_val)/interval;
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

void double_array::step_gen(double min_val, double max_val) {
	int j=0, n=size, dif = 0;
	double range = max_val - min_val, step = range / (n / interval) / 2, mn=step+min_val, mx = 2*step+min_val, temp = 0;
	
	while (n - interval >= 0) {
		dif = (int)mx - (int)mn;
		// printf("%lg, %lg, %d\n", mn, mx, dif);			
		if (dif > 0) {
			for (int i=0+j;i<interval+j;i++) {
				arr[i] = (double)(rand() % (dif+1)) + mn;
				
				temp = rand() % 1000 + 9000; // 0.9 - 0.999
				while (temp > 1) {
					temp /=10;
				}
				arr[i] *= temp;
				if (arr[i] < mn) arr[i] = mn;
				if (arr[i] > mx) arr[i] = mx;
			}
		}
		else if (dif == 0) {
			int count = 0;
			while (mn < 1) {
				mn *= 10;
				mx *= 10;
				count++;
			}
			for (int i=0+j;i<interval+j;i++) {
				arr[i] = (double)(rand() % ((int)mx - (int)mn + 1) + (int)mn) / pow(10, count);
				temp = rand() % 1000 + 9000;
				while (temp > 1) {
					temp /=10;
				}
				arr[i] *= temp;
				if (arr[i] < mn/pow(10, count)) arr[i] = mn/pow(10, count);
				if (arr[i] > mx/pow(10, count)) arr[i] = mx/pow(10, count);
			}
			mn /= pow(10, count);
			mx /= pow(10, count);
		}
		n -= interval;
		j += interval;
		mn += 2 * step;
		mx += 2 * step;
	}
}


void double_array::sawtooth_gen(double min_val, double max_val) {
	int i=0, j=0, l=0, n=size;
	double mn = min_val, mx = max_val, step=(max_val-min_val)/interval;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			if (i % 2 == l) {
				arr[i] = mn;
				mn+=step;
			}
			else {
				arr[i] = mx;
				mx-=step;
			}
		}
		l = (l+1)%2;
		n -= interval;
		j += interval;
		mx = max_val;
		mn = min_val;
	}
}

void double_array::kvazi_gen(double min_val, double max_val) {
	int i=0, j=0, n=size;
	double val = min_val, step=(max_val-min_val)/interval;
	while (n - interval >= 0) {
		for (i=0+j;i<interval+j;i++) {
			arr[i] = val;
			
			if (val+step <= max_val)
				val += step;
			else 
				val = max_val;
		}
		inversion_gen(j);
		i--;
		n -= interval;
		j += interval;
		val = min_val;
	}
}

void double_array::inversion_gen(int start) {
	int inversions = 0, swapped, temp;
	int mx_index, mn_index;
	//inversions = rand() % (interval / 2 + 1);
	// 1 работает, остальное не смотерл 
	inversions = 1;
	switch (inversions) {
		case 1:
			mn_index = 0;
			mx_index = interval-1;
			swapped = rand() % (mx_index+1) + mn_index;
			cout << swapped << endl;
			// свап влево или вправо
			if ((rand() % 2 && swapped != mn_index) || swapped == mx_index) {
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			}
			else {
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			}
			break;
		case 2:
			mn_index = 0;
			mx_index = (interval/2)-1;
			swapped = rand() % (mx_index+1) + mn_index;
			if ((rand() % 2 && swapped != mn_index) || swapped == mx_index) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			mn_index = interval/2;
			mx_index = interval/2;
			swapped = rand() % (mx_index) + mn_index;
			if ((rand() % 2 && swapped != mn_index) || swapped == mn_index+mx_index-1) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			break;
		case 3:
			mn_index = 0;
			mx_index = interval/3;
			swapped = rand() % mx_index;
			if ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			mn_index = interval/3;
			swapped = rand() % (mx_index) + mn_index;
			if ((rand() % 2 && swapped != mn_index) || swapped == mx_index + mn_index - 1) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			mn_index = interval/3 * 2;
			swapped = rand() % (mx_index) + mn_index;
			if ((rand() % 2 && swapped != mn_index) || swapped == mx_index + mn_index - 1) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			break;
		case 4:
			temp = rand() % 3; // в каком месте встваим на 2 позиции

			mn_index = 0;
			mx_index = interval/3;
			swapped = rand() % mx_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp == 0) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			mn_index = interval/3 * 2;
			swapped = rand() % (mx_index) + mn_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp == 1) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			mn_index = 0;
			mx_index = interval/3;
			swapped = rand() % mx_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp == 2) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			break;
		case 5:
			temp = rand() % 3; // в каком месте не встваим на 2 позиции

			mn_index = 0;
			mx_index = interval/3;
			swapped = rand() % mx_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp != 0) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			mn_index = interval/3 * 2;
			swapped = rand() % (mx_index) + mn_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp != 1) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);

			mn_index = 0;
			mx_index = interval/3;
			swapped = rand() % mx_index;
			if (temp != 0 && ((rand() % 2 && swapped != mn_index) || swapped == mx_index - 1)) 
				swap_arr(arr, start+swapped, start+swapped - 1, 0);
			else if (temp != 2) {
				// mx elem 
				swap_arr(arr, mn_index, mn_index+mx_index-1, 0);
				swap_arr(arr, mn_index+1, mn_index+mx_index-1, 0);
			}
			else 
				swap_arr(arr, start+swapped, start+swapped + 1, 0);
			break;
	}

}

// 0-2 2-0 элемента переставляем на 1 позицию (свап)
// 3 выбираем 3 случайных числа 1-8 и вставляем
// 4 - выбираем 2 элемента 1-2+7-8 и вставляем, дальше 1 элемент 3-6 и вставляем либо вправо либо влево на 2
// 5 - выбираем 1 элемент 1-9
// можно вставлять вместо свапа - на n элементов переставили, получили n инверсий
// нужно переставить 3 элемента

// 0 - double*, 1 - int*
void swap_arr(void * arr, int i, int j, int doub_or_int) {
	int temp1 = 0;
	double temp2;
	if (doub_or_int) {
		temp1 = ((int *)arr)[i];
		((int *)arr)[i] = ((int *)arr)[j];
		((int *)arr)[j] = temp1;
	}
	else {
		temp2 = ((double *)arr)[i];
		((double *)arr)[i] = ((double *)arr)[j];
		((double *)arr)[j] = temp2;
	}

}

void double_array::output() {
	for (int i=0;i<size;i++) 
		printf("%lg ", arr[i]);
	printf("\n");
}


void start_gen(double_array * gen_1, int_array * gen_2, int min_val_int, int max_val_int,
							double min_val_double, double max_val_double, int int_step, double double_step) {
	cout << "Int generation start\n\n";
	cout << "down generation\n";
	clock_t start_time = clock();
	gen_2->gen_down(min_val_int, max_val_int, int_step);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "up generation\n";
	gen_2->gen_up(min_val_int, max_val_int, int_step);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "random generation\n";
	gen_2->gen_rand(min_val_int, max_val_int);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "sawtooth generation\n";
	gen_2->sawtooth_gen(min_val_int, max_val_int);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "sin generation\n";
	gen_2->sin_gen(min_val_int, max_val_int);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "step generation\n";
	gen_2->step_gen(min_val_int, max_val_int);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	cout << "kvazi generation\n";
	gen_2->kvazi_gen(min_val_int, max_val_int);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_2->output();
	
	cout << "Double generation start\n\n";
	cout << "down generation\n";
	gen_1->gen_down(min_val_double, max_val_double, double_step);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "up generation\n";
	gen_1->gen_up(min_val_double, max_val_double, double_step);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "random generation\n";
	gen_1->gen_rand(min_val_double, max_val_double);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "sawtooth generation\n";
	gen_1->sawtooth_gen(min_val_double, max_val_double);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "sin generation\n";// 1 2 3 4 5 6 7 8 9 10

	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "step generation\n";
	gen_1->step_gen(min_val_double, max_val_double);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec"  << endl;
	start_time = clock();
//	gen_1->output();
	cout << "kvazi generation\n";
	gen_1->kvazi_gen(min_val_double, max_val_double);
	cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " sec" << endl;
	start_time = clock();
	gen_1->output();
}


int main(){
	srand(time(NULL));
	int n = 0;
	printf("enter size of array\n");
	scanf("%d", &n);
	double_array gen_1(n);
	int_array gen_2(n);
	start_gen(&gen_1, &gen_2, 0, 1000, 0.123, 9.23, 90, 0.21);

	return 0;
}
/*
Квази-упорядоченная последовательность – это последовательность, в которой имеется
ограниченное количество инверсий (количество элементов, для которых не
выполняется отношение порядка) и оно много меньше размера последовательности.
*/