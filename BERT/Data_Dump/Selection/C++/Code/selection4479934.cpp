#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
    int count = 0;
    for (int  i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    int A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int count = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i == N-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
    cout << count << endl;

    return 0;
}
