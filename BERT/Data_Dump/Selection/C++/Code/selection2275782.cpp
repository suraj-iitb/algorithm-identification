#include <iostream>

using namespace std;

int selectionSort(int* A, int N)
{
    int kaisuu = 0;
    for (int i = 0; i < N - 1; i++) {
        int min_j = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[min_j]) {
                min_j = j;
            }
        }
        if (min_j != i) {
            int tmp = A[i];
            A[i] = A[min_j];
            A[min_j] = tmp;
            kaisuu++;
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

    int kaisuu = selectionSort(A, N);

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
