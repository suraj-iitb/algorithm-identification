#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<typeinfo>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

/*
 1 partition(A, p, r)
 2   x = A[r]
 3   i = p-1
 4   for j = p to r-1
 4     if A[j] <= x
 5       i = i+1
 6       A[i] と A[j] を交換
 7   A[i+1] と A[r] を交換
 8   return i+1
 */

struct P{
    ll a;
    char c;
    
    bool operator < (const P &p) const {return a<p.a;}
    
    bool operator <= (const P &p) const {return a<=p.a;}
    
    bool operator == (const P &p) const {return a==p.a && c==p.c;}
};

ll Part(vector<P> &A,ll p,ll r){
    const P &x=A[r];
    ll i=p-1;
    for(ll j=p;j<r;j++){
        if(A[j]<=x){swap(A[++i],A[j]);}
    }
    swap(A[i+1],A[r]);
    return i+1;
}

/*
 1 quicksort(A, p, r)
 2   if p < r
 3     q = partition(A, p, r)
 4     quickSort(A, p, q-1)
 5     quickSort(A, q+1, r)
 */

void quick(vector<P> &A,ll p,ll r){
    if(p<r){
        ll q=Part(A,p,r);
        quick(A,p,q-1);
        quick(A,q+1,r);
    }
}



int main(){
    ll n;
    cin>>n;
    vector<P> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].c>>a[i].a;
    }
    vector<P> b=a;
    quick(a,0,n-1);
    stable_sort(b.begin(),b.end(),less<P>());
    bool s=true;
    for(int i=0;i<n;i++){
        if(!(a[i]==b[i])){s=false;}
    }
    cout<<(s?"Stable":"Not stable")<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i].c<<" "<<a[i].a<<endl;
    }
    
    return 0;
}

