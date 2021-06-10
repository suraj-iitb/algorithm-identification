#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

class List {
public:
    struct node {
        int prev, next;
    };
    const int N, H;
    vector<node> dat;
    List(const int _N, const int _H) : N(_N), H(_H), dat(N+H){ clear(); }
    inline bool empty(const int h) const { return (dat[N+h].prev == N+h); }
    inline int back(const int h) const { return dat[N+h].prev; }
    inline void insert(const int h, const int u){
        dat[u].prev = dat[N+h].prev, dat[u].next = N+h;
        dat[dat[N+h].prev].next = u, dat[N+h].prev = u;
    }
    inline void erase(const int u){
        dat[dat[u].prev].next = dat[u].next, dat[dat[u].next].prev = dat[u].prev;
    }
    inline void clear(const int h){ dat[N+h].prev = dat[N+h].next = N+h; }
    inline void clear(){
        for(int i = N; i < N+H; ++i) dat[i].prev = dat[i].next = i;
    }
};

class RadixHeap{
public:
    const int V;
    int size, last;
    List bucket;
    #define impl(x) (x == last) ? 0 : 32 - __builtin_clz(x ^ last)

    RadixHeap(const int node_size) : V(node_size), size(0), last(0), bucket(V, 32){}
    inline bool empty(){ return (size == 0); }
    inline void decrease_key(int newd, int ver){
        bucket.erase(ver), bucket.insert(impl(newd), ver);
    }
    inline void push(int dist, int ver){
        ++size, bucket.insert(impl(dist), ver);
    }
    inline pair<int, int> pop(const vector<int>& dist){
        pair<int, int> res = {numeric_limits<int>::max(), -1};
        if(bucket.empty(0)){
            int id = 0;
            while(bucket.empty(++id));
            for(int i = bucket.dat[V+id].next; i < V; i = bucket.dat[i].next){
                if(dist[i] < res.first) res = {dist[i], i};
            }
            last = res.first, bucket.erase(res.second);
            for(int i = bucket.dat[V+id].next, j = bucket.dat[i].next; i < V;){
                bucket.insert(impl(dist[i]), i), j = bucket.dat[i = j].next;
            }
            bucket.clear(id);
        }else{
            res = {last, bucket.back(0)}, bucket.erase(res.second);
        }
        return --size, res;
    }
};

class Dijkstra {
public:
    struct edge{
        int to, cost;
    };
    const int V, inf;
    vector<vector<edge> > G;
    vector<int> d;
    Dijkstra(const int node_size)
     : V(node_size), inf(numeric_limits<int>::max()), G(V), d(V, inf){}
    void add_edge(const int u, const int v, const int cost){
        G[u].push_back((edge){v, cost});
    }
    void solve(const int s){
        RadixHeap que(V);
        d[s] = 0;
        que.push(0, s);
        while(!que.empty()){
            pair<int, int> p = que.pop(d);
            const int v = p.second;
            for(auto& e : G[v]){
                if(d[e.to] == inf){
                    d[e.to] = d[v] + e.cost;
                    que.push(d[e.to], e.to);
                }else if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.decrease_key(d[e.to], e.to);
                }
            }
        }
    }
};

int in() {
    int n, c;
    while ((c = getchar()) < '0') if (c == EOF) return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}

void out(int n) {
    int res[11], i = 0;
    do { res[i++] = n % 10, n /= 10; } while (n);
    while (i) putchar(res[--i] + '0');
    putchar('\n');
}

int main()
{
    int n = in(), m = in(), s = in();
    Dijkstra dj(n);
    rep(i,m){
        int a = in(), b = in(), c = in();
        dj.add_edge(a,b,c);
    }
    dj.solve(s);
    rep(i,n){
        if(dj.d[i] == numeric_limits<int>::max()){
            putchar('I'), putchar('N'), putchar('F'), putchar('\n');
        }else{
            out(dj.d[i]);
        }
    }
    return 0;
}

