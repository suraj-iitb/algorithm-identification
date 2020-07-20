#include <iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int flag = 1;
    int i = 0;
    int swap_cnt = 0;

    while (flag) {
        flag = 0;
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                swap_cnt++;
            }
        }
        i++;
    }
    return swap_cnt;
}

int main() {
    int N, A[100];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int swap_cnt = bubbleSort(A, N);

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N-1) cout << " ";
    }
    cout << "\n";
    cout << swap_cnt << endl;
    return 0;
}
