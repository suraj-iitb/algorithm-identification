/**
 * Sort I - Bubble Sort
 */

#include <iostream>

using namespace std;

int main() {
    int N, A[100], count = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[j + 1]) {
                A[j] += A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
                count++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }
    }
    cout << count << endl;
}
