/*
                  友利奈緒ぱわーでACしてくれ！！！！！！！！！！！！
                  Charlotteまだ見てない人は見ような！！！！！！！

                  ／　 /:／　　　　　　　　　　　 　 ＼:ヽ　＼
  　　　　　　　 /　　／　　　　　　 　 　 　 　 　 　 　 ＼　　ヽ
  　　　　　＼__L 彡　　　　　　　　　　　　　　　　　　　 ヽ　　',
  　　　　　　　ﾌ /　　　/　　/　 /　　　,　　 　 　 　 ヽ　　', 　ｊ
  　　　　　　　ﾚ　　　 /　　/ 　/　 　 　 　 　 　 　 　 ', 　ヽ　j
  　　　 　 　 // 　 　 !　/_l＿/__ノ 　　{ ＼}　　　　 　 ',　　',/
  　　　　　　i ﾊ 　 　 {　从j　ﾊ　i　　　 ',　 ト-､}　 i i　 }　　jj
  　　　　　　( ﾊ　　　(　 川　ハ ﾊ　 !　 '　ﾊ　 ﾊ　j j　,' 　 八
  　　　 ＜＿,ｨ∧　　　斗芹ﾃミxハ ﾊ　 ﾚ　} /__ﾚﾚ　/ 　 ∧ ＼　ﾉ
  　　　 　 　 ∨　＼ 　ゝ　辷:ソ　　 　)　芹ﾚ心ヾレ′　/ ト--　´
  　　　＼ｰ‐'　ﾉ　　 ＼ゝ　　　　　　 　 　 ゞ:_ソ "/ 　／ 　ヽ
  　　　　 　 フ　　　　i八 " "　　　,　　　　　　　ム彡　　　　＼
  　　　　 　/　　/　　j　 ト　　　　　　 　 　 " "イト＜　 　 　 ＼＼
  　　　　 /　　/　　　j　/／ヽ､ 　 ∩　　 　 イ　{ {　　￣ フフへ ＼＼
  　　　　(　／　　　 ,/ / 　　i　＞――＜ニニニﾆ┐　 〃／: : ヽ　ヽヽ
  　　　　／　　ィT´/ /┌―　￣￣ /::: , ,)　 　 　 〃／／: : : : : :}　ヽヽ)
  　　　/ /　 ∧ヾi┌― { {￣　　　 ﾉ:::トﾟ<　 　 　 ∥//: : : : : : : : i　 ﾉ ﾉ
  . 　　( 人　 {:ヽヾi∨　∧V　　　 /:::/　､ヽ　　　 ∥/: : : : : : : : : :}　/
  　　　V　( ∧: :＼'∨　∧V　　 ﾉ:::/　 ∧ 〉＿__∥: : : : : :／: : : :ﾚ
  　　 　 　 /∧: : : : ∨　∧V┬ｲ:::ﾉ　 〈 TT　|　|{{: : : : ／: : : : : ∧　　 ﾉ
  　　　 　 (　ハ: : : : :∨'T∧Vi　i (　 　 V　!　!　{{: : ／ : : : : : : /　ｰ　ノ
  　　　　　V　ハ: : : : :∨ﾍ∧V　i ゝゝ　 i／⌒＼{／ : : : : : : : /ｰ― ´
  　　　　　 ∨　ヽ: : : : :∨ﾍ∧∨i　〉 〉 /　/二　 ): : : : : : : : :/

          (https://seesaawiki.jp/asciiart/d/Charlotte より)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;
#define int ll
// #define DEBUG 42
inline void nprint(){}
template <class Head, class... Tail>
inline void nprint(Head &&head, Tail &&... tail) {
    cout << head << endl;
    nprint(move(tail)...);
}
#ifdef DEBUG
  #define eprint(...) nprint(__VA_ARGS__)
#else
  #define eprint(...) if(0==1) cout << 1 << endl;
#endif
#define Yes(a) cout << (a ? "Yes" : "No") << endl
#define YES(a) cout << (a ? "YES" : "NO") << endl
#define POSSIBLE(a) cout << (a ? "POSSIBLE" : "IMPOSSIBLE") << endl
using cmp = complex<double>;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) REP(i,n+1)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPS(i,n) RREP(i,n+1)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PERM(c) sort(ALL(c)); for(bool cp = true;cp;cp = next_permutation(ALL(c)))
#define eb(val) emplace_back(val)
const double PI = acos(-1), EPS = 1e-10;
const ll MOD = 1E9+7;
int dx[] = {1,0,-1,0}; int dy[] = {0,1,0,-1};
constexpr ll INF = 1LL<<40;
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p){
  return s << "(" << p.first << ", " << p.second << ")";
}
template<class T> istream& operator>>(istream &is,vector<T> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> istream& operator>>(istream &is,vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> ostream& operator<<(ostream &os, const vector<T> &st){
  for(size_t i=0;i<st.size();++i){
    if(i==st.size()-1){
      if(st[i]<INF) os << st[i];
      else os << "INF";
    }else {
      if(st[i]<INF) os << st[i] << " ";
      else os << "INF" << " ";
    }
  }
  return os;
}
template<class T> ostream& operator<<(ostream &os, const vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i){
    os << st[i];
    if(i!=st.size()-1) os << endl;
  }
  return os;
}
pair<vector<vector<int>>,vector<vector<int>>>
warshal_floyd(const vector<vector<int>> &g){
  int n = g.size();
  constexpr static ll INF = 1LL<<40;
  vector<vector<int>> dist = g, inter(n,vector<int>(n,-1));
  REP(k,n)REP(i,n)REP(j,n){
    if(dist[i][k]<INF&&dist[k][j]<INF&&dist[i][j] > dist[i][k]+dist[k][j]){
      dist[i][j] = dist[i][k]+dist[k][j];
      inter[i][j] = k;
    }
  }
  REP(i,n) if(dist[i][i]<0) return make_pair(vvi(),vvi());
  return make_pair(dist,inter);
}
void buildPath(const vector< vector<int> > &inter,
int s, int t, vector<int> &path) {
  int u = inter[s][t];
  if (u < 0) path.push_back(s);
  else buildPath(inter, s, u, path), buildPath(inter, u, t, path);
}
vector<int> buildPath(
const vector< vector<int> > &inter, int s, int t) {
  vector<int> path;
  buildPath(inter, s, t, path);
  path.push_back(t);
  return path;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int v,e;
  cin >> v >> e;
  vvi g(v,vi(v,INF));
  REP(i,e){
    int s,t,d;
    cin >> s >> t >> d;
    g[s][t] = d;
  }
  REP(i,v) g[i][i] = 0;
  auto dist = warshal_floyd(g).first;
  if(dist.size()==0){
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  cout << dist << endl;
  eprint(INF);
}

