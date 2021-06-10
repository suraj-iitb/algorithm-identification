#include <bits/stdc++.h>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(s) (s).begin(), (s).end()
#define dis distance
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector <int> > vvi;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = (1 << 29);
const ll LINF = 1e18;
const double PI = acos(-1);

struct Edge{
    int from,to;
    ll cost;
    Edge(int _from = -1, int _to = -1, ll _cost = -1):from(_from),to(_to),cost(_cost){}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int V,E;
typedef pair<ll,int> P;

vll dijkstra(int s,Graph G){
    priority_queue<P, vector<P>, greater<P> > Q;
    vll ret(V,LINF);
    ret[s] = 0;
    Q.push(P(0,s));

    while(!Q.empty()){
        P p = Q.top();Q.pop();
        int v = p.second;
        for(Edge e: G[v]){
            if(ret[e.to] > p.first + e.cost){
                ret[e.to] = p.first + e.cost;
                Q.push(P(ret[e.to], e.to));
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    int r;
    cin >> r;
    Graph G(V);
    REP(i,E){
        int s,t,d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(s,t,d));
    }

    vll dist = dijkstra(r,G);
    REP(i,V){
        if(dist[i] == LINF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
    return 0;
}

