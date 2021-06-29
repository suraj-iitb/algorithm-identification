#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
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

/* Do bubble sort */
int main_sort(int *A, int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(&A[j], &A[j-1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int A[100], N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    int cnt = main_sort(A, N);
    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
