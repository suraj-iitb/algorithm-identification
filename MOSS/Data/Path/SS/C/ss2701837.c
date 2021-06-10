#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//_____
#define pb emplace_back
#define fi first
#define se second
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define err(...) fprintf(stderr, __VA_ARGS__)
#define show(x) cerr << #x << ':' << (x) << endl
#define outl(x) cout << (x) << '\n'
#define FAST() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
#define let const auto
template<class A, class B>inline bool chmax(A &a, B b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, B b){return b<a ? a=b,1 : 0;}
inline bool inside(int y, int x, int H, int W){return(y>=0 && x>=0 && y<H && x<W);}
const int dx[] = {1, 0, -1, 0,  1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1,  -1, 1, 1, -1};
#define INF  0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define NIL -1
//_______
typedef pair<int,int> pii;
typedef pair<ll, int> pli;

int N, M;
vector <pii> G[100010];
ll mcos[100010];

void dijkstra(let s)
{
   priority_queue < pli, vector<pli>, greater<pli> >pq;
   pq.emplace( pii(0,s) );
   memset( mcos, 0x3f, sizeof(mcos) );
   mcos[s] = 0;

   while (!pq.empty()) {
      let tmp = pq.top(); pq.pop();
      if(mcos[tmp.se] < tmp.fi)continue;
      for( let &x: G[tmp.se] ) {
         let nc = x.fi + tmp.fi;
         let nxt = x.se;
         if( chmin(mcos[nxt], nc) ) pq.emplace( pii(nc,nxt) );
      }
   }
   return ;
}

signed main()
{
   FAST();
   int r;
   cin >> N >> M >> r;
   while (M--) {
      int s, t, c;
      cin >> s >> t >> c;
      G[s].pb( pii(c,t) );
   }
   dijkstra(r);

   rep(i, N) {
      if (mcos[i] == LINF) outl("INF");
      else outl(mcos[i]);
   }
}


