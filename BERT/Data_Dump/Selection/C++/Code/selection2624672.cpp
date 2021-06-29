#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

int n;
int a[111];

int main(){
	cin>>n;
  int res=0;
  rep(i,n)cin>>a[i];
  rep(i,n){
    int minj=i;
    repl(j,i,n){
      if(a[minj]>a[j])minj=j;
    }
    if(minj!=i){
      swap(a[minj],a[i]);
      res++;
    }
  }
  cout<<a[0];
  repl(i,1,n)cout<<" "<<a[i];
  cout<<endl;
  cout<<res<<endl;
	return 0;
}
