#include <iostream>

using namespace std;

int bubbleSort(int* A, int N)
{
    int kaisuu = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int tmp    = A[j];
                A[j]   = A[j-1];
                A[j-1] = tmp;
                kaisuu++;
            }
        }
    }
    return kaisuu;
}

int main(void)
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int kaisuu = bubbleSort(A, N);

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i != N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    cout << kaisuu << endl;

    return 0;
}
