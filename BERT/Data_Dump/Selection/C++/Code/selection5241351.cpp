#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main_sort(int *A, int N) {
    int cnt = 0;
    for (int i = 0; i < N-1; i++) {
        /* index of the minimum value in an unsorted sequence */
        int minj = i;
        for (int j = i; j < N; j++) {
            /* serach the minimum value among an unsorted sequence */
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        swap(&A[i], &A[minj]);
        if (i != minj) cnt++;
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

}
