#include <bits/stdc++.h>

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
long long dp[100100];

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int minj;
    int cnt = 0;
    for(int i = 0; i < N-1; i++) {
        minj = i;
        for(int j = i; j < N; j++) {
            if(A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if(i != minj) cnt++;
    }

    for(int i = 0; i < N; i++) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}
