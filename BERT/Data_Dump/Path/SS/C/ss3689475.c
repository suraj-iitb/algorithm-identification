#include<bits/stdc++.h>

using namespace std;

#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define Eunique(v) v.erace(unique(all(v)),v.end())
#define pvec(v)　rep(i,v.size()){cout << v[i] << " ";}
#define INF 0x3f3f3f3f
#define mset(m,v) memset(m,v,sezeof(m))
#define mod (int)(1e9 +7);

const double pi = acos(-1.0);

typedef vector<int> vi;
typedef string ss;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef deque<ll> dll;
typedef pair<ll,ll> P;
ll dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

ll gcd(ll x,ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

ll lcm(ll x,ll y)
{
    x /= gcd(x,y);
    y /= gcd(x,y);
    return (x*y);
}

    ll n,k;
    vll a;

bool dfs(ll i,ll sum)
{
    cout << '(' << i << ',' << sum << ')' << endl;
    if(i == n)return sum == k;

    if(dfs(i+1,sum))return true;

    if(dfs(i+1,sum + a[i]))return true;

    return false;
}

struct edge {
    //ll from;
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
//using P = pair<int, int>;

int V;
vector<edge> G[100007];
vll d;

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    //fill(d, d+V, INF);
    d[s] = 0;
    //cout << " 000 " << endl;
    que.push(P(0, s));
    //cout << 1 << endl;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        //cout << p.first << " " << p.second << endl;
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    //cout << 1 << endl;
}

int main() {
    cin >> V;
    d.resize(V,M);
    int E,r;
    cin >> E >> r;
    //cout << 4 << endl;
    for (int i=0; i<E; ++i) {
        edge e;
        int a;
        cin >> a >> e.to >> e.cost;
        G[a].pb(e);
        //G.pb(e);
    }
    //cout << 3 << endl;
    dijkstra(r);
    for (int i=0; i<V; ++i) {
        if(d[i] != M){
           cout << d[i] << endl;
        }

        else cout << "INF\n";
           // cout << "0から" << i << "までのコスト: " << d[i] << endl;
    }
}
