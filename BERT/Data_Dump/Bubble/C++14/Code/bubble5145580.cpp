#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;



int main(){
    int n; cin>>n;
    vector<int> A(n);
    rep(i, n) cin>>A[i];
    int ans = 0;
    rep(i,n)rep(j,n)if(i<j) ans += A[i] > A[j];
    sort(A.begin(), A.end());
    rep(i, n-1) cout << A[i] << " ";
    cout << A[n-1] << endl;
    cout << ans << endl;
}
