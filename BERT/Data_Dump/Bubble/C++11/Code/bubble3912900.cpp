#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int n, int *A) {
    int count = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        for (int i = n - 1; i >= 1; --i) {
            if(A[i-1] > A[i]) {
                swap(A[i], A[i-1]);
                flag = true;
                count++;
            }
        }
    }

    // output
    for (int i = 0; i < n; ++i) {
        cout << A[i] << ((i != n - 1) ? " " : "\n");
    }
    cout << count << "\n";
}

int main() {
    int array[101] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    BubbleSort(n, array);
    return 0;
}
