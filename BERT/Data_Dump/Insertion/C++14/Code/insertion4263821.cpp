#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using lint = long int;
using llint = long long int;
using namespace std;

auto trace = [&](vector<int> A) {
    for (size_t i = 0; i < A.size(); ++i) {
        cout << A[i];
        if (i == A.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
};

void insertionSort(vector<int> &A, int N) {
    trace(A);
    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int loop;
    cin >> loop;
    vector<int> vi(loop);
    rep(i, loop) cin >> vi[i];
    insertionSort(vi, loop);
    return 0;
}

