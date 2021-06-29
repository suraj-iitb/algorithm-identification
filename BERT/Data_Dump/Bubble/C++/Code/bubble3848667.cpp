#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N; cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    
    bool flag = true;
    int ans=0;
    for(int i=0;flag;i++){
        flag = false;
        for(int j=N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=true;
                ans++;
            }
        }
    }
    rep(i,N){
        cout<<A[i];
        if(i!=N-1)cout<<' ';
        else cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
