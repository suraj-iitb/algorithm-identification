#include <iostream>
#include <algorithm>
using namespace std;
//_____
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define err(...) fprintf(stderr, __VA_ARGS__)
#define show(x) cerr << #x << ':' << (x) << endl
#define outl(x) cout << (x) << '\n'
#define FAST() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef pair<int,int> pii;
typedef const int let;
template<class A, class B>inline bool chmax(A &a, B b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, B b){return b<a ? a=b,1 : 0;}
#define INF  0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define NIL -1
//_______

int N;
ll dp[102][102];

void floyd()
{
   rep(k,N) {
      rep(i,N) {
         if (dp[i][k] == LINF)continue;
         rep(j,N) {
            if (dp[k][j] == LINF) continue;
            chmin( dp[i][j], dp[i][k] + dp[k][j] );
         }
      }
   }
   return;
}

signed main()
{
   FAST();
   int E, s, t, c;
   cin >> N >> E;

   rep(i,N)rep(j,N)
      dp[i][j] = (i == j) ? 0 : LINF;

   while (E--) {
      cin >> s >> t >> c;
      dp[s][t] = c;
   }

   floyd();

   rep(i, N) if(dp[i][i] < 0) {
      outl("NEGATIVE CYCLE");
      return (0);
   }
   rep(i, N) {
      rep(j, N) {
         if(dp[i][j] == LINF)cout << "INF";
         else cout << dp[i][j];
         cout << (j+1 < N ? ' ' : '\n');
      }
   }
}


