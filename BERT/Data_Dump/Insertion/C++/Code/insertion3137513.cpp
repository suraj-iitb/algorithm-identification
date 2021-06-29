#include <iostream>
using namespace std;

const int MAX_N = 100;

void trace(int (&A)[MAX_N], int N) {
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int (&A)[MAX_N], int N) {
    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main() {
    int N;
    int A[MAX_N];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    trace(A, N);
    insertionSort(A, N);

    return 0;
}
