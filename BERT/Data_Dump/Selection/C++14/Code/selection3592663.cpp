#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    
    int cnt = 0;
    for ( int i = 0; i < N; i++ ) {
        int minj = i;
        for ( int j = i; j < N; j++ ) {
            if (A[minj] > A[j]) {
                minj = j;
            }
        }
        if ( minj != i ) {
            int t = A[i];
            A[i] = A[minj];
            A[minj] = t;
            cnt++;
        }
    }

    for ( int i = 0; i < N; i++ ) {
        cout << (i==0 ? "" : " ") << A[i];
    }
    cout << '\n';
    cout << cnt << '\n';
    return 0;
}
