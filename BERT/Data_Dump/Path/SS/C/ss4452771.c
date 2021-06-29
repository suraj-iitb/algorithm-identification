#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const long long MOD = 1e9 + 7;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|

template <typename C>
struct Vertex{
    C cost;
    bool done;
    int from;
    vector<int> edges_to; //to vertex number
	vector<C> edges_cost; // edge cost

    bool operator<(const Vertex& another) const { // priority --> min
        return another.cost < cost; // order(cost)
    }
	
	bool operator==(const Vertex& another) const {
        return another.cost == cost; // order(cost)
    }
};

template <typename C>
struct Graph{
    vector<Vertex<C>> vertex;
    Graph(int n){
        vertex.resize(n);
    }

    void addedgedir(int x,int y){
        vertex[x].edges_to.push_back(y);
    }
    void addedge(int x, int y){
        vertex[x].edges_to.push_back(y);
        vertex[y].edges_to.push_back(x);
    }

    void caddedgedir(int x, int y, C c){
        vertex[x].edges_to.push_back(y);  
        vertex[x].edges_cost.push_back(c);  
    }

    void caddedge(int x, int y, C c){
        vertex[x].edges_to.push_back(y);  
        vertex[x].edges_cost.push_back(c);  
        vertex[y].edges_to.push_back(x);  
        vertex[y].edges_cost.push_back(c); 
    }

    void dijkstra(int start){
        int N = vertex.size();
        priority_queue<C> Q;
        
        REP(i,N){
            vertex[i].done = false;
            vertex[i].cost = -1;
        }
        
        vertex[start].cost = 0; //start
        Q.push(start);
        
        while (!Q.empty()){
            int now = Q.top(); Q.pop();
            vertex[now].done = true;
            REP(i,vertex[now].edges_to.size()){
                int nto = vertex[now].edges_to[i];
                C ncost = vertex[now].cost + vertex[now].edges_cost[i];
                if (((vertex[nto].cost) < 0) or (ncost < vertex[nto].cost)){  //not visited or required refresh
                    vertex[nto].cost = ncost;
                    vertex[nto].from = now;
                    Q.push(nto);
                }	
            }
        }
    }
};

int main() {
    int V,E,r;
    cin >> V >> E >> r;
    Graph<ll> G(V);

    REP(i,E){
        int a,b,d;
        cin >> a >> b >> d;
        G.caddedgedir(a,b,d);
    }

    G.dijkstra(r);

    REP(i,V){
        if (G.vertex[i].cost == -1) puts("INF");
        else cout << G.vertex[i].cost << "\n";
    }
}
