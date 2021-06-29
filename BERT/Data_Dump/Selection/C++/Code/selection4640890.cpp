#include <iostream>
using namespace std;

void selectionSort(int A[], int N) {
    /// ソート後の配列と交換回数を標準出力する
    int count = 0;
    for (int i = 0; i <= N - 1; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            count++;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << "\n" << count << endl;
}

int main() {
    int N;
    int A[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    selectionSort(A, N);
    return 0;
}
