#include <bits/stdc++.h>

using namespace std;

bool flag;
int cnt;

void printArr(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i < n-1)
            cout << ' ';
    }
    cout << endl;
}

void bubbleSort(int A[], int N) {
    flag = true;
    int i = 0; // 未ソート部分列の先頭インデックス
    while (flag) {
        flag = false;
        for (int j = N-1; j > i; --j) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                ++cnt;
                flag = true;
            }
        }
        ++i;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    bubbleSort(arr, n);
    printArr(arr, n);
    cout << cnt << endl;
}
