#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define repr(i, a, b) for (int i = a; i < b; i--)
using namespace std;
typedef long long ll;

int Bubble(int A[], int N){
    int cnt=0;
    rep(i,N-1){
        for (int j=N-1; i<j; j--){
            if (A[j]<A[j-1]) {
                swap(A[j],A[j-1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    int A[101];
    rep(i,N) cin >> A[i];
    int ans;
    
    ans=Bubble(A,N);
    rep(i,N-1){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << ans << endl;
    
}
