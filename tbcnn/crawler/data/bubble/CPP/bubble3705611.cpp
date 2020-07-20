#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int boubleSort(int A[], int N) {
    int cnt = 0;
    bool flag = 1;
    for (int i = 0; flag; ++i) {
        flag = 0;
        for (int j = N-1; j > i; --j) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                cnt++;
            }
        }
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

    cnt = boubleSort(A, N);

    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
