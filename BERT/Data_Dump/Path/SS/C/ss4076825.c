#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//https://www.creativ.xyz/dump-cpp-652/
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
 
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
using P = pair <int,int>; //to, cost
using WeightedGraph = vector<vector <P>>;
vector <int> dijkstra(WeightedGraph &G, int s=0){
    vector <int> d(G.size(),INF);
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    que.push(P(0,s)); 
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v]< p.first) continue;
        int sz = G[v].size();
        rep(i,sz) if(chmin(d[G[v][i].F], d[v] + G[v][i].S)) que.push(P(d[G[v][i].F], G[v][i].F));
    }
    return d;
}
signed main(void) { cin.tie(0); ios::sync_with_stdio(false);
    int n,m,r; cin>>n>>m>>r;
    WeightedGraph g(n);
    rep(i,m){
        int a,b,c; cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    auto d = dijkstra(g, r);
    rep(i,n) d[i] != INF ? cout<<d[i]<<endl : cout<<"INF"<<endl;;
}
