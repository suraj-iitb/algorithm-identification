//ALDS1_2_A_19140837_Ojima_Yukiya.cpp
//
//提出日 2020/07/01 wednesday
//
//プログラミング基礎演習2 CS 第8回課題 ALDS1_2_A
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

void bubblesort(vector<int> a) {
    bool flag = true;
    int counta = 0;
    while (flag) {
        flag = false;
        for (int j = a.size() - 1; j >= 1; j--) {
            if (a.at(j) < a.at(j - 1)) {
                swap(a.at(j), a.at(j-1));
                counta++;
                flag = true;
            }
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
    bubblesort(vec);
    return 0;
}
