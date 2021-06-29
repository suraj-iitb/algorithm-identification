#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)

#define SORT(c) sort((c).begin(),(c).end())
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define CLR(a) memset((a), 0 ,sizeof(a))

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int MAX = 100;
int V, E;
LL D[MAX][MAX];

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void input(){
  std::cin >> V >> E;
  REP0(i,V) {
    REP0(j,V) {
      D[i][j] = ( (i==j) ? 0 : LLINF );
    }
  }
  REP0(i, E){
    int s, t, d;
    std::cin >> s >> t >> d;
    D[s][t] = d;
  }
}


void floyd(){ // minpath of i to j through k(=0..n)
  REP0(k,V){
    REP0(i,V){
      if ( D[i][k] == LLINF ) continue;
      REP0(j,V){
        if ( D[k][j] == LLINF ) continue;
        D[i][j] = min( D[i][j], D[i][k] + D[k][j] );
      }
    }
  }
}


void output(){
  REP0(i,V){
    if ( D[i][i] < 0 ) {
      std::cout << "NEGATIVE CYCLE" << '\n';
      return;
    }
  }

  REP0(i,V) {
    REP0(j,V) {
      if ( j ) std::cout << " ";
      if ( D[i][j] == LLINF ) {
        std::cout << "INF";
      } else {
        std::cout << D[i][j];
      }
    }
    std::cout << '\n';
  }
}


int main(int argc, char const *argv[]) {
  input();
  floyd();
  output();
  return 0;
}

