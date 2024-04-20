#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
struct Complexity {
    double time;
    long long int operations;
    void out (int size) {
        std::cout << size << " " << ((double)time / CLOCKS_PER_SEC) * 1000 << " " << operations << std::endl;
    }
};
string repeat_text();
string rand_gen(int len);
string get_sequance(string src, int len);
int SearchStringBM(string T, int N, string P, int M, Complexity * analyse);
void SearchStringStrstr(string text, string wanted, Complexity * analyse);
int main () {
    srand(time(NULL));
    
    string asd = repeat_text();
    string temp = get_sequance(asd, asd.length() / 2 - 1);
    Complexity res;
    SearchStringBM(asd, asd.length(), temp, temp.length(), &res);
    res.out(asd.length());
    SearchStringStrstr(asd, temp, &res);
    res.out(asd.length());
    int sizes[5] = {(int)1e7, (int)3e7, (int)5e7, (int)7e7, (int)1e8};
    // size / 2 - 1, size, 1
    string src, wanted;
    // size / 2 - 1
    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, size / 2  - 1);
        SearchStringBM(src, size, wanted, size / 2 - 1, &res);
        res.out(size);
    }

    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, size / 2  - 1);
        SearchStringStrstr(src, wanted, &res);
        res.out(size);
    }

    // size
    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, size);
        SearchStringBM(src, size, wanted, size, &res);
        res.out(size);
    }

    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, size);
        SearchStringStrstr(src, wanted, &res);
        res.out(size);
    }

    // 1
    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, 1);
        SearchStringBM(src, size, wanted, 1, &res);
        res.out(size);
    }

    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src, 1);
        SearchStringStrstr(src, wanted, &res);
        res.out(size);
    }


    // not found
    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src,size/2-1)+"\n";
        SearchStringBM(src, size, wanted, size/2, &res);
        res.out(size);
    }

    for (auto &size : sizes) {
        src = rand_gen(size);
        wanted = get_sequance(src,size/2-1)+"\n";
        SearchStringStrstr(src, wanted, &res);
        res.out(size);
    }
    return 0;
}

int SearchStringBM(string text, int n, string wanted, int m, Complexity * analyse) {
    analyse->time = clock();
    analyse->operations = 0;
    if (m > n) return -1;
    int hash_table[256] = {0};
    for (int i = 0; i < 256; i++) hash_table[i] = m;
    for (int i = 0; i < m-1; i++) hash_table[(int)wanted[i]] = m - i - 1;
    int i = m-1, j = i, k = i;
    while (i < n && j >= 0) {
        j = m - 1;
        k = i;
        while (j >= 0 && text[k] == wanted[j]) {
            j--;
            k--;
        }
        i += hash_table[(int)text[i]];
    }
    analyse->time = clock() - analyse->time;
    return k < n - m ? k+1 : -1;

}

void SearchStringStrstr(string text, string wanted, Complexity * analyse) {
    analyse->time = clock();
    analyse->operations = 0;
    const char * res = strstr(text.c_str(), wanted.c_str());
    analyse->time = clock() - analyse->time;
}

string rand_gen(int len) {
    string str;
    for (int i = 0; i < len; i++)
        str += (rand() % 26 + 'a');
    return str;
}

string repeat_text() {
    string str = "";
    string buf = "";
    ifstream in("text_to_lab.txt");
    while (in) {
        in >> buf;
        str += buf + " ";
    }
    in.close();
    return str;
}

// if want from start - 2 * len > src.len, else from mid
string get_sequance(string src, int len) {
    int n = src.length();
    string res = "";
    if (n > len * 2) {
        int i = len;
        for (;i<len*2;i++) {
            res += src[i];
        }
    }
    else {
        for (int i = 0; i < len && i < n; i++) {
            res += src[i];
        }
    }
    return res;
}
