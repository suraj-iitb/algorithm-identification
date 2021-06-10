#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define BITREP(i, n) for(int i = 0; i < (1LL<<n); i++)
#define ALL(v) v.begin(), v.end()
#define FS first
#define SC second
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define SQR(x) ((x) * (x))
#define BIT(n) (1LL<<(n))
#define PCNT(x) __builtin_popcountll(x)
#define GCD(x,y) __gcd(x,y)
#define LCM(x,y) x/__gcd(x,y)*y
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
typedef long long lint;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef vector<vector<int> > VVI;
typedef vector<vector<LL> > VVLL;
typedef vector<vector<bool> > VVB;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const LL MOD=1000000007ll;
const LL INF=2000000000ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

long power(long a,long b){return b?power(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;}

long perm(int N, int K){
	long x=1;
	for(int i=1;i<=K;i++)
	{
		x=x*(N-i+1)%MOD;
	}
	return x%MOD;
}

long factorial(int N){
	return perm(N,N);
}

long comb(int N,int K){
	long x=1,y=1;
	for(int i=1;i<=K;i++)
	{
		x=x*(N-i+1)%MOD;
		y=y*i%MOD;
	}
	return x*power(y,MOD-2)%MOD;
}

long hcomb(int N, int K){
    return comb(N+K-1, N-1);
}

int dtoi(double d){
    if ((double) 2*d-floor(d)-ceil(d) >= 0) return ceil(d);
    else return floor(d);
}

bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i ==  0) return false;
    }
    return true;
}

void eratosthenes(int n){
	// エラトステネスのふるい
    bitset<1000000> is_prime(0); // 十分大きなサイズを確保します
    for (int i = 2; i <= n; ++i) is_prime.set(i); // とりあえず全部ふるいに入れます
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) { // 素数 i を発見したら
            for (int j = i * 2; j <= n; j += i) {
                is_prime.reset(j); // i の倍数をふるい落とす
            }
        }
    }
	for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) cout << i << endl;
    }
}

void dfs(const vector<vector<int> > &G, int v, vector<int> &seen) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (int next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen); // 再帰的に探索
    }
}

void bfs(const vector<vector<int> > &G, int v, vector<int> &dist){
    REP(i,SZ(dist)) dist[i] = -1; // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[v] = 0;
    que.push(v); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int next_v : G[v]) {
            if (dist[next_v] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

int knapsack01(int N, int W, vector<int> &value, vector<int> &weight){
    VVI dp(N+1,VI(W+1,0));
    REP(i,N) REP(j,W+1){
        if (j-weight[i] >= 0) dp[i+1][j] = max(dp[i][j-weight[i]] + value[i], dp[i][j]);
        else dp[i+1][j] = dp[i][j];
    }
    return dp[N][W];
}

int knapsack01_reuse(int N, int W, vector<int> &value, vector<int> &weight){
    VI dp(W+1,0);
    dp[0] = 0;
    for (int i = 0; i < N; i++){
        for (int j = W ;j > 0; j--){
            if (j-weight[i] >= 0) dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[W];
}

int knapsack(int N, int W, vector<int> &value, vector<int> &weight){
    VVI dp(N+1,VI(W+1,0));
    REP(i,N) REP(j,W+1){
        dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
        if (j-weight[i] >= 0) dp[i+1][j] = max(dp[i+1][j-weight[i]]+value[i], dp[i+1][j]); 
    }
    return dp[N][W];
}

int knapsack_reuse(int N, int W, vector<int> &value, vector<int> &weight){
    VI dp(W+1,0);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int w = weight[i]; w <= W; ++w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

int longest_increasing_subsequence(int n, vector<int> &A){
    vector<int> L(n+1,0);
    L[0] = A[0];
    int length = 1;

    FOR(i,1,n){
        if (L[length-1] < A[i]) L[length++] = A[i];
        else *lower_bound(L.begin(),next(L.begin(),length),A[i]) = A[i];
    }

    return length;
}

int longest_common_subsequence(string X, string Y){
    int m = X.length();
    int n = Y.length();
    int res = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    VVI c(m+1, VI(n+1,0));
    FOR(i,1,m+1) FOR(j,1,n+1){
        if (X[i] == Y[j]) c[i][j] = c[i-1][j-1] + 1;
        else c[i][j] = max(c[i-1][j], c[i][j-1]);
        res = max(res,c[i][j]);
    }
    return res;
}

void dijkstra(int n, const vector<vector<pair<int, int> > > &G, int v, vector<int> &dist){//頂点N,辺MO(MlogN)
    priority_queue<pair<int, int> > pq;
    vector<int> color(n,0);
    REP(i,n) dist[i] = INF;
    dist[v] = 0;
    pq.push(make_pair(0,v));
    color[v] = 1;

    while(!pq.empty()){
        pair<int, int> f = pq.top();
        pq.pop();
        int u = f.second;
        color[u] = 2;

        if (dist[u] < f.first * (-1)) continue;

        REP(j,G[u].size()){
            v = G[u][j].first;
            if (color[v] == 2) continue;
            if (dist[v] > dist[u] + G[u][j].second){
                dist[v] = dist[u] + G[u][j].second;
                pq.push(make_pair(dist[v]*(-1), v));
                color[v] = 1;
            }
        }
    }
}

void warshall_floyd(int V, vector<vector<LL> > &dp){//O(N^3)
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if (dp[i][k] == INF) continue;
            for(int j=0;j<V;j++) {
                if (dp[k][j] == INF) continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

long long mystoll(string s){
    LL ans = 0;
    for (int i = s.length()-1; i >= 0; i--){
        ans += (s[i]-'0') * pow(10,s.length()-1-i);
    }
    return ans;
}

struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        REP(i, N) par[i] = -1;
    }
    
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return;
    }
    
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    int V, E;
    cin >> V >> E;

    int s, t, d;
    VVLL dist(V,VLL(V,INF));
    REP(i,V) dist[i][i] = 0;
    REP(i,E) {
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    warshall_floyd(V,dist);
  	REP(i,V) if (dist[i][i] < 0) {
      	cout << "NEGATIVE CYCLE" << endl;
      	return 0;
    }
    REP(i,V) REP(j,V) cout << (dist[i][j] != INF ? to_string(dist[i][j]) : "INF") << (j < V-1 ? " " : endl);
}
