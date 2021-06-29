#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int A[2002002], B[2002002], C[10101];

int main(){
    int n; cin >> n;
    rep(i, n) cin >> A[i];

    int U = 10101;
    rep(i, n) C[A[i]]++;
    rep(i, U-1) C[i+1] += C[i];

    for(int i=n-1; i>=0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    rep(i, n){
        if (i) cout << " ";
        cout << B[i+1];
    }
    cout << endl;
    return 0;
}
