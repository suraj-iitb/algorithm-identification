#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N) {
    int num = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                num++;
            }
        }
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int sortnum = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n-1) cout << " ";
        else cout << endl;
    }
    cout << sortnum << endl;
    return 0;
}
