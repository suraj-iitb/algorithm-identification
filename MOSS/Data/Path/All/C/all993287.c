#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pr(a) cout << (a) << endl
typedef long long ll;
typedef pair<int,int> P;
const int MAX=1000000000;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main() {
  int n,m;
  cin >> n >> m;
  ll g[n][n];
  rep(i,n) {
    rep(j,n) {
      g[i][j]=(ll)MAX*(ll)MAX;
      if(i==j) g[i][j]=0;
    }
  }
  rep(i,m) {
    int x,y,z;
    cin >> x >> y >> z;
    g[x][y]=z;
  }
  rep(k,n) {
    rep(i,n) {
      rep(j,n) {
	if(g[i][k]!=(ll)MAX*(ll)MAX && g[k][j]!=(ll)MAX*(ll)MAX) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
  bool neg=false;
  rep(i,n) {
    if(g[i][i]<0) neg=true;
  }
  if(neg) pr("NEGATIVE CYCLE");
  else {
    rep(i,n) {
      rep(j,n) {
	if(j) cout << " ";
	if(g[i][j]==(ll)MAX*(ll)MAX) cout << "INF";
	else cout << g[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
