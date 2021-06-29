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
int N,min,count=0;
cin>>N;
int A[N];
REP(i,N)cin>>A[i];

REP(j,N){
    min=j;
    FOR(i,j,N){
    if(A[min]>A[i]){
        min=i;
    }
    }
    if(A[j]!=A[min])count++;
    swap(A[min],A[j]);
}
REP(i,N-1)cout<<A[i]<<" ";
cout<<A[N-1]<<endl<<count<<endl;
}
