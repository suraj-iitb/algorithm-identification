#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int bubbleSort(int *arr, int n) {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int n, cnt;
    int *val;

    cin >> n;
    val = new int(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cnt = bubbleSort(val, n);
    for (int i = 0; i < n; i++) {
        cout << val[i];
        if (i != n - 1)
            cout << " ";
    }
            
    cout << endl << cnt << endl;

    return 0;
}
