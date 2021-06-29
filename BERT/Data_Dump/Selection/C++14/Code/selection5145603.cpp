#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;



int main(){
    int n; cin>>n;
    vector<int> A(n);
    rep(i, n) cin>>A[i];
    int ans = 0;
    rep(i, n){
        int mn = i;
        for (int j=i; j<n; j++){
            if (A[j] < A[mn]) mn = j;
        }
        if (i != mn){
            ans++;
            swap(A[i], A[mn]);
        }
    }
    rep(i, n-1) cout<<A[i]<<" ";
    cout << A[n-1] << endl;
    cout << ans << endl;
}
