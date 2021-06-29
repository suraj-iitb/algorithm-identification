//ALDS1_1_A_19140837_Ojima_Yukiya.cpp
//
//提出日 2020/07/01 wednesday
//
//プログラミング基礎演習2 CS 第8回課題 ALDS1_1_A
//
//学修番号 19140837　小島優希也

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void display(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v.at(i) << " ";
    }
    cout << v.at(v.size() - 1) << endl;
}

void insertionsort(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        int v = a.at(i);
        int j = i - 1;
        while (j >= 0 && a.at(j) > v) {
            a.at(j + 1) = a.at(j);
            j--;
        }
        a.at(j + 1) = v;
        display(a);
    }
}

int main(void) {
    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        vec.push_back(value);
    }
    insertionsort(vec);
    return 0;
}
