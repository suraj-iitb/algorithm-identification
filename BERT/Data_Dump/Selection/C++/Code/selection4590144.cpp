#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
    int count = 0;
    for(int i = 0; i < N - 1; i++) {
        int t = A[i];
        int minj = i;
        for(int j = i; j < N; j++) {
            if(A[j] < A[minj]) minj = j;
        }
        A[i] = A[minj];
        A[minj] = t;
        if(minj != i) count++;
    }
    return count;
}
int main() {
    int A[100], N, count;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    count = selectionSort(A, N);

    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
