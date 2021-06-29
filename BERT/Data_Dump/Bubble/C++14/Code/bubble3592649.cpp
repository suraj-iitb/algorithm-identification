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
    int flag = 1;
    while ( flag ) {
        flag = 0;
        for (int j = N-1; j > 0; j-- ) {
            if ( A[j] < A[j-1] ) {
                int t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                flag = 1;
                cnt++;
            }
        }
    }
    
    for ( int i = 0; i < N; i++ ) {
        cout << (i!=0 ? " " : "") << A[i];
    }
    cout << '\n';
    cout << cnt << '\n';
    return 0;
}
