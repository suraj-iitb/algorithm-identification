#include<iostream>
#include<algorithm>
using namespace std;

int selection_sort(int A[], int N) {
    int minj, cnt;

    cnt = 0;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    return cnt;
}

int main () {
    int N, A[100], cnt;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    cnt = selection_sort(A, N);

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
}

