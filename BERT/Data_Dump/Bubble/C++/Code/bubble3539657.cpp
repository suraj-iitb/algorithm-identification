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

    int flag = 1;
    int cnt = 0;
    int i = 0;
    while(flag) {
        flag = 0;
        for(int j = N-1; j >= i+1; j--) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                cnt++;
            }
            flag = 1;  
        }
        i++;
    }

    for(int i = 0; i < N; i++) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}
