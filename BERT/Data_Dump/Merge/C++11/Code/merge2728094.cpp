#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[500001];
int INF=1000100010;
int cnt;
void merge(int l,int mid,int r){
    int cl=mid-l,cr=r-mid;
    vector<int> vl,vr;
    rep(i,cl) vl.pb(a[l+i]);
    rep(i,cr) vr.pb(a[mid+i]);
    vl.pb(INF),vr.pb(INF);
    cl=0,cr=0;
    FOR(i,l,r){
        if(vl[cl]<=vr[cr]) a[i]=vl[cl++];
        else a[i]=vr[cr++];
        ++cnt;
    }
}
void mergesort(int l,int r){
    if(r-l>1){
        int mid=(r+l)/2;
        mergesort(l,mid);
        mergesort(mid,r);
        merge(l,mid,r);
    }
}
int main(){
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    mergesort(0,n);
    rep(i,n) cout<<a[i]<<(i==n-1?"":" ");
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
