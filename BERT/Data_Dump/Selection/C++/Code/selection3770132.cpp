#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[110];
    rep(i,0,N) cin >> A[i];
    ll cnt = 0;
    rep(i,0,N){
        ll minj = i;
        rep(j,i,N){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            cnt++;
            swap(A[i], A[minj]);
        }
    }
    printa(A, N);
    print(cnt);
}
