#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N; cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    int ans=0;
    rep(i,N){
        int mn=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[mn]) mn=j;
        }
        swap(A[i],A[mn]);
        if (mn!=i)ans++;
    }
    rep(i,N){
        cout<<A[i];
        if(i!=N-1)cout<<' ';
        else cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
