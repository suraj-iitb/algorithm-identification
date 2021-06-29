#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <cstdio>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
# define ll int64_t
# define str string
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define PI 3.141592653589793
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;



#define INF 2000000000
#define MAX_V 10


bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll modpow(ll a,ll n) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) x*=i;
    return x;
}

ll gcd(ll a,ll b) { return b ? gcd(b, a%b) : a; }

ll l[500000/2 + 2],r[500000/2 + 2],cnt;

void merge(ll a[],ll left,ll mid,ll right){
    ll n1 = mid - left;
    ll n2 = right - mid;
    rep(i,n1) l[i]=a[left+i];
    rep(i,n2) r[i]=a[mid+i];
    
    l[n1]=INF;
    r[n2]=INF;
    ll i=0,j=0;
    
    for(ll k=left;k<right;k++){
        cnt++;
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
    }
}

void mergeSort(ll a[],ll left,ll right){
    if(left+1<right){
        ll mid = (left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cnt = 0;
    
    ll n;
    cin>>n;
    ll A[500000];
    rep(i,n) cin>>A[i];
    
    mergeSort(A,0,n);
    rep(i,n){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}

