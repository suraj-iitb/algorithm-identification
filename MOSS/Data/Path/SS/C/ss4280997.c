#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct Node{
    int id, v;
    bool done = false;
    Node(int id, int v=INT_INF): id(id), v(v) {}
    Node(): id(0), v(INT_INF) {}

    inline bool operator==(const Node& x) { return v == x.v; }
    inline bool operator!=(const Node& x) { return v != x.v; }
    inline bool operator<(const Node& x) { return v < x.v; }
    inline bool operator>(const Node& x) { return v > x.v; }
    inline bool operator<=(const Node& x) { return v <= x.v; }
    inline bool operator>=(const Node& x) { return v >= x.v; }

    bool comp(Node node){
        return v < node.v;
    }
};

struct Edge{
    int from, to, cost, id;
    Edge(int from, int to, int cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}

    bool comp(Edge e){
        return cost < e.cost;
    }
};

struct Graph{
    int N;
    vector<vector<Edge>> adj;
    vector<Node> node;

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, int cost=1, int id=-1){
        Edge e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge> get_adj(Node node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }
};

bool operator>(const Node& a, const Node& b){
    return a.v > b.v;
}

int main(void){
    int N,M,r; cin >> N >> M >> r;
    Graph G(N);
    REP(i,M){
        int s,t,d; cin >> s >> t >> d;
        G.add_edge(s,t,d);
    }

    priority_queue<Node,vector<Node>,greater<Node>> q;
    q.push(Node(r,0));
    while(q.size()){
        Node n = q.top(); q.pop();
        if(G.node[n.id].done) continue;
        G.node[n.id].done = true;
        if(chmin(G.node[n.id].v, n.v)){
            for(Edge e : G.get_adj(n)){
                q.push(Node(e.to, n.v+e.cost));
            }
        }
    }

    REP(i,N){
        if(G.node[i].v == INT_INF) cout << "INF" << en;
        else cout << G.node[i].v << en;
    }
    return 0;
}
