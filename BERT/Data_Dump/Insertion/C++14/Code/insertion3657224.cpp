#include<bits/stdc++.h>

#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define ALL(obj) (obj).begin(),(obj).end()
#define space <<" "<<
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
#define FIX <<fixed<<setprecision(10)<<
using namespace std;

using ll = long long; using ull = unsigned long long;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pii = pair<int,int>; using pll = pair<ll,ll>;

const ll MOD = 1e9+7;

int main(){
int n;
int j;
cin>>n;
vector<int> A(n);
int v;
REP(i,n)cin>>A[i];

REP(i,n){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=v;
    REP(k,n-1)cout<<A[k]<<" ";
    cout<<A[n-1]<<endl;
}
}
