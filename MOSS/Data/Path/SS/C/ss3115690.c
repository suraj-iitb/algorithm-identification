#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.4.0"
// Useful Marcos
//====================START=====================
// Compile use C++11 and above
#ifdef LOCAL
#define debug(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define MSG cout << "Finished" << endl
#else
#define debug(args...)
#define MSG
#endif
#if __cplusplus >= 201703L
template <typename... Args>
void readln(Args &... args)
{
    ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
#elif __cplusplus >= 201103L
void readln()
{
}
template <typename T, typename... Args>
void readln(T &a, Args &... args)
{
    cin >> a;
    readln(args...);
}
void writeln()
{
    cout << endl;
}
template <typename T, typename... Args>
void writeln(T a, Args... args)
{
    cout << a << " ";
    writeln(args...);
}
#endif
#if __cplusplus >= 201103L
#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)
#else
#define FOR(_i, _begin, _end) for (int _i = (int)_begin; _i < (int)_end; _i++)
#define FORR(_i, _begin, _end) for (int _i = (int)_begin; _i > (int)_end; _i--)
#define nullptr NULL
#endif
#if __cplusplus >= 201103L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : _name)        \
        cin >> i;
#else
#define VIS(_kind, _name, _size)    \
    vector<_kind> _name;            \
    _name.resize(_size);            \
    for (int i = 0; i < _size; i++) \
        cin >> _name[i];
#endif
// alias
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define tcase() \
    int T;      \
    cin >> T;   \
    FOR(kase, 1, T + 1)
// Swap max/min
template <typename T>
bool smax(T &a, const T &b)
{
    if (a > b)
        return false;
    a = b;
    return true;
}
template <typename T>
bool smin(T &a, const T &b)
{
    if (a < b)
        return false;
    a = b;
    return true;
}
// ceil divide
template <typename T>
T cd(T a, T b)
{
    return (a + b - 1) / b;
}
// min exchange
template <typename T>
bool se(T &a, T &b)
{
    if (a < b)
        return false;
    swap(a, b);
    return true;
}
// A better MAX choice
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const int maxn = 5e5+10;

struct Edge{
	int from,to,dist;
};
struct HeapNode{
	int d,u;
	bool operator < (const HeapNode& rhs) const{
		return d > rhs.d;
	}
};
struct Dijkstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	
	void init(int n){
		this->n = n;
		for(int i = 0; i < n;i++){
			G[i].clear();
		} 
		edges.clear();
	}
	void AddEdge(int from ,int to,int dist){
		edges.push_back((Edge){from,to,dist});
		m = edges.size();
		G[from].push_back(m-1);
	}
	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i = 0;i<n;i++) d[i] = INF;
		d[s] = 0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty()){
			HeapNode x = Q.top();Q.pop();
			int  u = x.u;
			if(done[u]) continue;
			done[u] = true;
			for(int i=0;i < G[u].size();i++){
				Edge& e = edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
};


// Actual Solver
inline void solve()
{
  int v,e,r,s,t,d;
  Dijkstra di;
  cin>>v>>e>>r;
  di.init(v);
  FOR(i,0,e){
  	cin>>s>>t>>d;
  	di.AddEdge(s,t,d);
  //	di.AddEdge(t,s,d);
  }
  di.dijkstra(r);
  for(int i=0;i<v;i++){
  	if(di.d[i]!=INF)
  	cout<<di.d[i]<<"\n";
  	else cout<<"INF\n";
  }
  
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    clock_t _begin = clock();
#endif

    
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

    return 0;
}
