#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "sort.h"

using namespace std;

int Analist(string file) {
    int i = 0, j = i;
    char *c = new char[6];
    for (i; file[i] != '('; i++) {
        if (isdigit(file[i])) {
            c[j] = file[i];
            j++;
        }
    }
    c[j] = '\0';
    int count = atoi(c);
    return count;
}

int *Parser(string file, int count) {
    int i = 0, j = i;
    char *c = new char[6];
    int *arr = new int[count];
    ifstream F;
    F.open(file, ios::in);
    int k = 0;
    while (!F.eof()) {
        char a;
        F >> a;
        if (a != ',') {
            c[j] = a;
            j++;
        } else {
            c[j] = '\0';
            arr[k] = atoi(c);
            k++;
            j = 0;
        }
    }
    return arr;
}

void Paste(int *arr, int count) {
    int swaps = 0, comp = 0;
    auto start = chrono::system_clock::now();
    for (int i = 1; i < count; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                swaps++;
            }
            comp++;
        }
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> time = end - start;
    cout << time.count() << endl;
    cout << "s = " << swaps << " c = " << comp << endl;
}

void Tim(int *arr, int count) {
    auto start = chrono::system_clock::now();
    sorter_tim_sort(arr,count);
    auto end = chrono::system_clock::now();
    chrono::duration<double> time = end - start;
    cout << time.count() << endl;
    cout << "s = " << getSwaps() << " c = " << getCmp() << endl;
}
