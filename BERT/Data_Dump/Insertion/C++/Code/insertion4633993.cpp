#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << ' ';
    }
    cout << A[N-1] << endl;
}

void insertionSort(int A[], int N) {
    int i, j, temp;

    for (i = 1; i < N; i++) {
        temp = A[i];
        j = i-1;

        while (j >= 0 && A[j] > temp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
        trace(A, N);
    }
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    trace(A, N);
    insertionSort(A, N);

    return 0;
}

