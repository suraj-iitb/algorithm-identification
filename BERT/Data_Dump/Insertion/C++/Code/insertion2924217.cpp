#include <iostream>
using namespace std;

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        cout << A[i];
        ( i == N - 1 ) ? cout << endl : cout << " ";
    }
}

void insertionSort(int A[], int N) {
    int i, j;
    for (i = 1; i < N; i++) {
        int v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(int argc, char* argv[]) {
    int N, i;
    int A[100];

    cin >> N;
    for ( i = 0; i < N; i++ ) cin >> A[i];

    trace(A, N);
    insertionSort(A, N);

    return 0;
}

