#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());
    rep(i, n){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return 0;
}
