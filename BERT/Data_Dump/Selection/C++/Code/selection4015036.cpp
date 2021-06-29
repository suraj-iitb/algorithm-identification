//
// Created by MengHaitao on 2019/11/27 0027.
//
//Select Sort
#include <iostream>

using namespace std;
int arr[1005], n, count;

void swap(int &a, int &b) { a ^= b ^= a ^= b; }   //交换两个数
void bubbleSort() {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (i != min) {
            swap(arr[i], arr[min]);
            count++;
        }

    }
    for (int j = 0; j < n; ++j) {
        if (j == n - 1) cout << arr[j] << endl;
        else
            cout << arr[j] << " ";
    }
    cout << count << endl;
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
