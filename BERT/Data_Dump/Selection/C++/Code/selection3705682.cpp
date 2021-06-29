#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int selectionSort(int A[], int N) {
    int minj;
    int cnt = 0;
    for (int i = 0; i < N-1; ++i) {
        minj = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if (i != minj) cnt++;
    }

    return cnt;
}

int main() {
    int N; cin >> N;
    int A[100];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int cnt;

    cnt = selectionSort(A, N);

    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
