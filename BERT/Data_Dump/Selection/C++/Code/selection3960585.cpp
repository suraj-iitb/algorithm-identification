#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int Selection_Sort(int A[], int N){
    int cnt=0;
    for (int i=0; i<N-1; i++){
        int min=A[i];//先頭の値を暫定の最小値として初期化する
        int k=i;//先頭の位置を保存する
        for (int j=i+1; j<N; j++){
            //
            if(min>A[j]){
                min=A[j];
                k=j;
            }
        }
        //交換するアルゴリズム
        if(A[i]!=A[k]){
            swap(A[i],A[k]);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    int A[101];
    int ans;
    rep(i,N) cin >> A[i];
    ans=Selection_Sort(A,N);
    rep(i,N-1) cout << A[i] << " ";
    cout << A[N-1] << endl;
    
    cout << ans << endl;
}
