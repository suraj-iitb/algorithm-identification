#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long ll;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,a[100],minj,cnt=0;
  cin>>n;
  REP(i,n){
    cin>>a[i];
  }
  REP(i,n){
    minj=i;
    FOR(j,i,n){
      if(a[j]<a[minj]){
         minj=j;
       }
     }
    if(i!=minj) cnt++;
    swap(a[i],a[minj]);
  }
  REP(i,n){
    if(i==n-1) cout<<a[i]<<endl;
    else  cout<<a[i]<<" ";

  }

  cout <<cnt<<endl;



  return 0;
}

