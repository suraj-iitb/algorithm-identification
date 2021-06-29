#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int m = A[i];
        int mj = i;
        for (int j = i+1; j < N; j++) {
            if (m > A[j]) {
                m = min(m, A[j]);
                mj = j;
            }
        }
        if (i != mj) {
            swap(A[i], A[mj]);
            cnt++;
        }
    }
    cout << A[0];
    for (int i = 1; i < N; i++) {
        cout << ' ' << A[i];
    }
    cout << endl;

    cout << cnt << endl;

}

