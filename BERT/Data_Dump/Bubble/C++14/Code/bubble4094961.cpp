#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

int bubblesort(vector<int> &A, int N) {
    int ret = 0;
    bool Flag = true;
    while (Flag) {
        Flag = false;
        for (int i = N-1; i > 0; i--) if (A[i] < A[i-1]) {
            swap(A[i], A[i-1]);
            ret++;
            Flag = true;
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = bubblesort(A, N);
    for (int i = 0; i < N; i++) {
        cout << A[i] << ((i+1==N)?"\n":" ");
    }
    cout << ans << endl;
    return 0;
}
