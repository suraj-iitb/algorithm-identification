//ALDS1_2_B_19140837_Ojima_Yukiya.cpp
//
//提出日 2020/07/01 wednesday
//
//プログラミング基礎演習2 CS 第8回課題 ALDS1_2_B
//
//学修番号 19140837　小島優希也

#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v.at(i) << " ";
    }
    cout << v.at(v.size() - 1) << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(vector<int> a) {
    int counta = 0;
    for (int i = 0; i < a.size(); i++) {
        int minj = i;
        for (int j = i; j < a.size(); j++) {
            if (a.at(j) < a.at(minj)) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(a.at(i), a.at(minj));
            counta++;
        }
    }
    display(a);
    cout << counta << endl;
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
    selectionsort(vec);
    return 0;
}
