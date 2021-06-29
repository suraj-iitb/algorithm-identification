#include <iostream>

using namespace std;

int bubbleSort(int A[], int N) {
    int flag = 1;
    int cnt = 0;
    while (flag) {
        flag = 0;
        for (int j = N-1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

void trace(int A[], int N) {
    for (int k = 0; k < N; k++) {
        if (k > 0) cout << ' ';
        cout << A[k];
    }
    cout << endl;
}

int main() {
    int N, A[100], cnt;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    cnt = bubbleSort(A, N);
    trace(A, N);
    cout << cnt << endl;

    return 0;

    
}
