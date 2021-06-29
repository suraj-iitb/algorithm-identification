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

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }

        if (minj != i) {
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            cnt++;
        }
    }
    print_vec(A);
    cout << cnt << endl;
}


