#include <iostream>
using namespace std;

void print(int A[], int N, int cnt) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return;
}

void bubbleSort(int A[], int N) {
    int flag = 1, cnt = 0;
    while (flag) {
        flag = 0;
        for (int i = N - 1; i > 0; i--) {
            if (A[i] < A[i - 1]) {
                int tmp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = tmp;
                cnt++;
                flag = 1;
            }
        }
    }
    print(A, N, cnt);
    return;
}

int main() {
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    bubbleSort(A, N);
}
