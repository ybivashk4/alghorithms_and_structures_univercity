#include <iostream>
#include <locale>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
#define M 512
// 110300 + 110300 + 1103 * 100 + 1103 * 10 + 1103
struct AutoNumber;
AutoNumber *not_hash;
struct AutoNumber {
    wchar_t Letter[3]; // 1 + 2 * 10 + 3 * 100 + Number
    int Number;
    int hash() {
        // 1081 1098 1099 1100
        int deleted = 0;
        for (int i = 0; i < 3; i++) {
            if (Letter[i] > 1081) {
                deleted += 1;
            }
            if (Letter[i] > 1098) {
                deleted += 3;
            }
        }
        return Letter[0] + Letter[1] + Letter[2] + Number - 1072 * 3 - deleted;
        // 1072 1073...1102 1103 - value of rus letters
    }
    bool equals(AutoNumber a) {
        return ((Letter[0] == a.Letter[0]) && (Letter[1] == a.Letter[1]) && (Letter[2] == a.Letter[2]) && (Number == a.Number));
    }
    AutoNumber(int * values, int size) {
        bool flag = true;
        while (flag) {
            Number = rand() % (M-84);
            Letter[0] = values[rand() % size];
            Letter[1] = values[rand() % size];
            Letter[2] = values[rand() % size];
            
            for (int i=0;i<10000;i++) {
                if (not_hash[i].equals(*this)) {
                    flag = false;
                }
            }
            flag = !flag;
        }

        // 84 for symbols and M-84 on Number
        
    }
    AutoNumber() {
        Number = -1;
        Letter[0] = 0;
        Letter[1] = 0;
        Letter[2] = 0;
    }
};


int main() {
    char const * const l1 = setlocale(LC_ALL, "ru_RU.utf8");
    srand(time(NULL));    
    wchar_t l = L'а';
    int values[28];
    int j = 0;
    not_hash = new AutoNumber[10000];
    for (int i=0;i<32;i++) {
        if ((wchar_t)(l+i) == L'й' || (wchar_t)(l+i) == L'ы' || (wchar_t)(l+i) == L'ъ' || (wchar_t)(l+i) == L'ь' )  {
            j++;
            // wcout << (wchar_t)(l+i) << " " << l+i << endl;
            continue;
        }
        values[i-j] = (l+i);
    }
/*
    int a[2][3];
    
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            a[i][j] = i*10+j;
        }
    }
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            cout << a[i][j] << endl;
        }
    }*/
    AutoNumber *asd = new AutoNumber(values, 28);
    AutoNumber hash_table[M][M];
    j = 0;
    // int count = 0;
    // int hashes[10000] = {0};
    for (int i=0;i<10000;i++) {
            asd = new AutoNumber(values, 28);
            // hashes[i] = (asd->Number + 110300) + asd->Letter[0] * 100 + asd->Letter[1] * 10 + asd->Letter[2] ;
            j = 0;
            while ((hash_table[asd->hash()]+j)->Number != -1){
                
                j++;
            }
            hash_table[asd->hash()][j] = *asd;
    }
    for (int i=0;i<M;i++) {
        bool flag = false;
        for (j=0;j<M;j++) {
            if (hash_table[j][i].Number != -1) {
                flag = true;
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
                
        }
        if (flag)
            cout << endl;
    }
    /*
    count = 0;
    cout << " asd" << endl;
    for (int i=0;i<2000;i++) {
        cout << hashes[i] << endl;
            for (int j=i+1;j<2000;j++) {
                if (hashes[i] == hashes[j]) {
                    hashes[i] = -1;
                    count++;
                    
                }
            }
    }
    cout << endl;
        */
    // cout << " " << count << endl;
    double sigma = 0;
    int count = 0;
    for (int i=0;i<M;i++) {
        count = 0;
        while (hash_table[i][count].Number != -1) {
            count++;
        }
        sigma += pow((count - 10000 / M), 2);
    }
    cout << sigma * ((double)M/(double)10000);
    delete [] not_hash;
    return 0;
}

// Генерируемые ключи должны быть уникальны. 
// как 
