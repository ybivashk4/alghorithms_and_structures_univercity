#define interval 10
using namespace std;

class double_array {
	private:
		int size;
		double * arr;
		// enum last_gen = {pseudo_gen=1, sorted_gen=2};
	public:
		void output();
		void gen_rand(double min_val, double max_val);
		// max_val no control
		void gen_up(double min_val, double max_val, double step);
		void gen_down(double min_val, double max_val, double step);

		// не реализовано 
		// void sawtooth_gen(double min_val, double max_val);
		// void step_gen(double min_val, double max_val);
		// void kvazi_gen(double min_val, double max_val);

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
		void output();
		void gen_rand(int min_val, int max_val);
		// max_val no control
		void gen_up(int min_val, int max_val, int step);
		void gen_down(int min_val, int max_val, int step);
		// interval = 10
		void sin_gen(int min_val, int max_val);

		//a1 < a2 > a3 < … > an-1 < an
		void sawtooth_gen(int min_val, int max_val);
		void step_gen(int min_val, int max_val);
		void kvazi_gen(int min_val, int max_val);
		int_array(int n) {
			arr = new int[n];
			for (int i=0;i<n;i++) arr[i] = 0;
			size = n;
		}
		~int_array() {
			delete arr;
		}
};