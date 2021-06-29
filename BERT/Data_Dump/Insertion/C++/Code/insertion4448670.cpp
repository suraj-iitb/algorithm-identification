#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for (int k = 0; k < N; k++) {
            if (k > 0) cout << " ";
            cout << A[k];
        }
        cout << endl;
    }
    return;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cin >> A[i];
        cout << A[i];
    }
    cout << endl;
    insertionSort(A, N);
}
