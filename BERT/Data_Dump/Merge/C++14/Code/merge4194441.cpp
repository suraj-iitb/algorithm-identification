#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll inf=1001001001;
ll res=0;

void merge(vector<ll> &a, ll left, ll mid, ll right){
    ll n1=mid-left;
    ll n2=right-mid;
    vector<ll> l(n1+1), r(n2+1);
    rep(i,n1) l[i]=a[left+i];
    rep(i,n2) r[i]=a[mid+i];
    l[n1]=inf; r[n2]=inf;
    ll i=0, j=0;
    for(ll k=left; k<right; k++){
        res++;
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }else{
            a[k]=r[j];
            j++;
        }
    }
}

void mergeSort(vector<ll> &a, ll left, ll right){
    if(left+1<right){
        ll mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(){
    ll n; cin>>n;
    vector<ll> s(n);
    rep(i,n) cin>>s[i];
    res=0;
    mergeSort(s,0,n);
    rep(i,n){
        cout<<s[i];
        if(i<n-1) cout<<' ';
        else cout<<endl;
    }
    cout<<res<<endl;
    return 0;
}
