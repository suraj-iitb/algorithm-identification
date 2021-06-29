#include <iostream>
using namespace std;


void is (int *A, int N) {
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << ' ';
    }
    cout << A[N-1] << '\n';
    for (int i = 1; i <= N-1; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        cout << A[0];
        for (int i = 1; A[i] != 0 ; i++) {
            cout << ' ' << A[i];
        }
        cout << '\n';
    }
}

int main () {
    int N;
    cin >> N;
    int A[1001] = {};
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    is(A, N);
}
