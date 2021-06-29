#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int swap_cnt = 0;

    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            swap_cnt++;
        }
    }
    return swap_cnt;
}

int main() {
    int A[100], N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int swap_cnt = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N-1) cout << " ";
    }
    cout << "\n";
    cout << swap_cnt << endl;
    return 0;
}
