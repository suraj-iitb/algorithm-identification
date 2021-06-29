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

    int num = 0;
    int i = 0;
    while (i < N) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j],A[j - 1]);
                num++;
            }
        }
        i++;
    }
    trace(A,N);
    cout << num << endl;
}

