#define _CRT_SECURE_NO_WARNINGS
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> ostream &operator << (ostream &os, const vector<T> &);
template<size_t n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, const tuple<T...> &){}
template<size_t n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream &os, const tuple<T...> &t){
    os << (n == 0 ? "" : " ") << get<n>(t); _ot<n+1>(os, t);
}
template<class...T> ostream &operator << (ostream &os, const tuple<T...> &t){
    _ot<0>(os, t); return os;
}
template<class T, class U> ostream & operator << (ostream &os, const pair<T,U> &p){
    return os << "(" << p.first << ", " << p.second << ") ";
}
template<class T> ostream &operator << (ostream &os, const vector<T> &v){
    for(size_t i = 0; i < v.size(); i++) os << v[i] << (i + 1 == v.size() ? "" : ", "); return os;
}
#ifdef DEBUG
#define dump(...) (cerr << #__VA_ARGS__ << " = " << make_tuple(__VA_ARGS__) \
                   << " (L : " << __LINE__ << ")" << endl)
#else
#define dump(...)
#endif
#define all(c) begin(c), end(c)
#define range(i,a,b) for(int i = a; i < (int)(b); i++)
#define rep(i,b) range(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
void fastios(){ ios_base::sync_with_stdio(0); cin.tie(0); }
int const mod = 1000000007;

using Weight = long long;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

auto const inf = numeric_limits<Weight>::max()/8;
Matrix warshallFloyd(const Graph &g){
    int n = g.size(); Matrix d(n, Array(n, inf));
    rep(i,n) d[i][i] = 0;
    rep(i,n) for(auto &e : g[i])
        d[e.src][e.dst] = min(d[e.src][e.dst], e.weight);
    rep(k,n)rep(i,n)rep(j,n)if(d[i][k] != inf && d[k][j] != inf)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

int main(){
    int V,E;
    while(cin >> V >> E){
        Graph g(V);
        rep(i,E){
            int a,b,c;
            cin >> a >> b >> c;
            g[a].eb(a,b,c);
        }
        auto d = warshallFloyd(g);
        bool negCycle = false;
        rep(i,g.size()){
            negCycle |= d[i][i] < 0;
        }
        if(negCycle) cout << "NEGATIVE CYCLE" << endl;
        else {
            rep(i,V)rep(j,V){
                if(d[i][j] >= inf) cout << "INF";
                else cout << d[i][j];
                if(j != V-1) cout << ' ';
                else cout << endl;
            }
        }
    }
}
