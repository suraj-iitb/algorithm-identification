//
// Created by MengHaitao on 2019/11/27 0027.
//
//Bubble Sort
#include <iostream>
using namespace std;
int arr[1005], n, count;
void swap(int &a, int &b) { a ^= b ^= a ^= b; }   //交换两个数
void bubbleSort() {
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >i; --j) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                count++;
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        if (j == n - 1) cout << arr[j] << endl;
        else
            cout << arr[j] << " ";
    }
    cout<<count<<endl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bubbleSort();
}

int main() {
    solve();
    return 0;
}
