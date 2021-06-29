#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;
using PII = pair<ll, ll>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())
#define MP make_pair
#define p_yes() p("YES")
#define p_no() p("NO")
#define possible() p("Possible")
#define impossible() p("Impossible")

ll SUM(VI& V){
  return accumulate(ALL(V), 0LL);
}

ll MIN(VI& V){return *min_element(ALL(V));}
ll MAX(VI& V){return *max_element(ALL(V));}

void print_vector(VI& V){
  ll n = V.size();
  rep(i, n){
    if(i) cout << ' ';
    cout << V[i];
  }
  cout << endl;
}

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

// long double
using ld = long double;
#define EPS (1e-14)
#define equals(a,b) (fabs((a)-(b)) < EPS)

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);

// snuke's mint
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
// const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

//#include <atcoder/dsu>
//using namespace atcoder; // 忘れがち

struct Edge{
    ll to;
    ll cost;
    Edge(ll to, ll cost): to(to), cost(cost) {}
    Edge(){
        to = 0;
        cost = 0;
    }
};
 
struct Node{
    ll distance;
    ll index;
    Node(ll d, ll i){
        distance = d;
        index = i;
    }
    Node(){}
 
    bool operator<(const Node &another) const
    {
        return distance < another.distance;
    }
    bool operator>(const Node &another) const
    {
        return distance > another.distance;
    }
};
 
struct Dijkstra{
    vector<ll> d;
    vector<vector<Edge> > graph;
    vector<bool> done;
 
    // ノード数を入れる
    void initialize(ll size){
        d.resize(size);
        done.resize(size);
        graph.resize(size);
        reset();
    }
 
    void reset(){
        ll N = graph.size();
        FOR(i, 0, N){
            d[i] = inf;
            done[i] = false;
        }
    }
    
    ll distance(int i){
        if((ll)d.size()<=i) return -1;
        return d[i];
    }
 
    void print_graph(){
        FOR(i, 0, (ll)graph.size()){
            cout << i << " -> ";
 
            for(auto edge : graph[i]){
                cout << edge.to << " ";
            }
            cout << endl;
        }
        p("distance");
        FOR(i, 0, (ll)graph.size()){
            ll d = distance(i);
            cout << i << " " << d << endl;
        }
    }
 
    void register_edge(ll a, ll b, ll cost){
        if(cost<0){
            p("ダイクストラなのに負コストですがいいですか？");exit(0);
        }
        auto edge = Edge(b, cost);
        graph[a].push_back(edge);
    }
 
    // 双方向
    void register_edge2(ll a, ll b, ll cost){
      register_edge(a, b, cost);
      register_edge(b, a, cost);
    }
 
    void calc_shortest_path(ll from=0){
      ll N = graph.size();
      if(from<0 || from>=N){
        cout << "index error" << endl;
        exit(0);
      }
        priority_queue<Node, vector<Node>, greater<Node> > que;
        auto node = Node();
        // 始点
        node.index = from;
        node.distance = 0;
        que.push(node);
 
        while(!que.empty()){
            // 1番distanceが小さいノード
            Node n = que.top();
            que.pop();
 
            if(done[n.index]){
                continue;
            }
            
            done[n.index] = true;
            d[n.index] = n.distance;
 
            auto edge_list = graph[n.index];
            for(auto edge : edge_list){   
                // 短くなるノードがあれば
                if(!done[edge.to] && n.distance + edge.cost < d[edge.to]){
                    ll shorter_distance = n.distance + edge.cost;
                    que.push(Node(shorter_distance, edge.to));
                }
            }
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N,M,r;cin>>N>>M>>r;
    
    Dijkstra dij;
    dij.initialize(N);

    rep(i,M){
      ll a,b,c;cin>>a>>b>>c;
      dij.register_edge(a,b,c);
    }
    dij.calc_shortest_path(r);

    rep(i,N){
      ll d = dij.distance(i);
      if(d==inf){
        p("INF");
      }else{
        p(d);
      }
    }
    
    return 0;
}
