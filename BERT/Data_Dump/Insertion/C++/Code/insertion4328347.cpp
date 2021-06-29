#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (0 < i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    trace(A,N);

    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (0 <= j && v < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A,N);
    }
    return 0;
}

