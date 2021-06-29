#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i != 0) cout << " ";
        cout << vec[i];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool flag = true;
    int cnt = 0;
    while (flag) {
        flag = false;
        for (int i = N-1; i > 0; i--) {
            if (A[i-1] > A[i]) {
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = true;
                cnt++;
            }
        }
    }
    print_vec(A);
    cout << cnt << endl;
}

