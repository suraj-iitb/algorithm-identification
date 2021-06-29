#include <iostream>
using namespace std;

/* Print each value of a given array */
void trace(int *A, int N) {
    for (int i = 0; i < N; i++) {
        if (i != N-1) {
            cout << A[i] << ' ';
        }
        else { cout << A[i]; }
    }
    cout << endl;
}

void main_sort(int *A, int N) {
    int v, j;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main() {
    int N;
    int A[100];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    trace(A, N);
    main_sort(A, N);

    return 0;
}
