#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N; cin>>N;
    vector<int> A(N);
    rep(i,N) {
        cin>>A[i];
        cout<<A[i];
        if(i!=N-1)cout<<' ';
        else cout<<endl;
    }

    for (int i=1;i<N;i++){
        int v = A[i];
        int j = i-1;
        while(j>=0&&A[j]>v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        rep(i,N) {
            cout<<A[i];
            if(i!=N-1)cout<<' ';
            else cout<<endl;
        }
    }
}
