#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void GenerateV1(string type, string count, string low, string high, string part = "0") {
    ofstream F;
    /*auto time1 = std::chrono::system_clock::now();
    time_t t = std::chrono::system_clock::to_time_t(time1);
    string t1 = ctime(&t);*/
    string file =
            "C:\\Users\\refre\\CLionProjects\\Kursovaya\\" + type + count + '(' + low + '-' + high + ") - " + part +
            ".txt";
    F.open(file, ios::out);
    string numbers;
    int num = stoi(low);
    srand(time(nullptr));
    if (type == "Up") {
        numbers = numbers + to_string(num) + ',';
        for (int i = 1; i < stoi(count); i++) {
            int delta;
            if (rand() % 100 < 40) {
                delta = (rand() % (stoi(high) - stoi(low) + 1) + stoi(low)) % (stoi(count)/2);
            } else {
                if (rand() % 100 < 50) {
                    delta = 1;
                } else {
                    delta = 0;
                }
            }
            if (num + delta <= stoi(high)) {
                num = num + delta;
            }
            numbers = numbers + to_string(num) + ',';
        }
    }
    if (type == "Down") {
        num = stoi(high);
        numbers = numbers + to_string(num) + ',';
        for (int i = 1; i < stoi(count); i++) {
            int delta;
            if (rand() % 100 < 40) {
                delta = (rand() % (stoi(high) - stoi(low) + 1) + stoi(low)) % (stoi(count)/2);
            } else {
                if (rand() % 100 < 50) {
                    delta = 1;
                } else {
                    delta = 0;
                }
            }
            if (num - delta >= stoi(low)) {
                num = num - delta;
            }
            numbers = numbers + to_string(num) + ',';
        }
    }
    if (type == "Rand") {
        for (int i = 0; i < stoi(count); i++) {
            num = rand() % (stoi(high) - stoi(low) + 1) + stoi(low);
            numbers = numbers + to_string(num) + ',';
        }
    }
    if (type == "PartRand") {
        if (rand() % 100 < 50) {
            num = stoi(low);
            numbers = numbers + to_string(num) + ',';
            for (int i = 1; i < stoi(count); i++) {
                int delta;
                if (i % stoi(part)) {
                    if (rand() % 100 < 40) {
                        delta = (rand() % ((stoi(high) - stoi(low)) / (stoi(count) / 4)));
                    } else {
                        if (rand() % 100 < 50) {
                            delta = 1;
                        } else {
                            delta = 0;
                        }
                    }
                    if (num + delta <= stoi(high)) {
                        num = num + delta;
                    }
                } else {
                    num = rand() % (stoi(high) - stoi(low) + 1) + stoi(low);
                }
                numbers = numbers + to_string(num) + ',';
            }
        } else {
            num = stoi(high);
            numbers = numbers + to_string(num) + ',';
            for (int i = 1; i < stoi(count); i++) {
                int delta;
                if (i % stoi(part)) {
                    if (rand() % 100 < 40) {
                        delta = (rand() % ((stoi(high) - stoi(low)) / (stoi(count) / 4)));
                    } else {
                        if (rand() % 100 < 50) {
                            delta = 1;
                        } else {
                            delta = 0;
                        }
                    }
                    if (num - delta <= stoi(high)) {
                        num = num - delta;
                    }
                } else {
                    num = rand() % (stoi(high) - stoi(low) + 1) + stoi(low);
                }
                numbers = numbers + to_string(num) + ',';
            }
        }
    }
    numbers = numbers + '\0';
    F << numbers;
    F.close();
}

