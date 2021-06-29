#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int k=10001,N=2000001;
    vector<int> A(N),B(N),C(k,0);
    //for(int i=1;i<=n;i++) C[i]=0;
    for(int i=1;i<=n;i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    for(int i=1;i<=k;i++) C[i]+=C[i-1];
    for(int j=n;j>=1;j--) {
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    for(int i=1;i<=n;i++) {
        if(i>1) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
