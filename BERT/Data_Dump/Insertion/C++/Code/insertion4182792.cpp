#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(a);i<=(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(b);i>=(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
ll sum(const T& a){return accumulate(all(a),0LL);}

void insertionSort(vl &a,ll n){
    rep(i,n){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    fore(i,1,n-1){
        ll v=a[i];
        ll j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        rep(i,n){
            if(i>0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
}

void solve(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    insertionSort(a,n);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

