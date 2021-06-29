#include <cassert>// c
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
using namespace std;

typedef int32_t i32;typedef int64_t i64;typedef i64 ll;typedef uint32_t uint;typedef uint64_t ull;

#define ALL(c) (begin(c)),(end(c))
#define REP(i,n) FOR(i,0,n)
#define REPr(i,n) FORr(i,0,n)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define FORr(i,l,r) for(int i=(int)(r)-1;i>=(int)(l);--i)
#define EACH(it,o) for(__typeof((o).begin()) it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);

class range {
private:
    struct Iter{
        int v;
        int operator*(){return v;}
        bool operator!=(Iter& itr) {return v < itr.v;}
        void operator++() {++v;}
    };
    Iter i, n;
public:
    range(int n) : i({0}), n({n}) {}
    range(int i, int n) : i({i}), n({n}) {}
    Iter& begin() {return i;}
    Iter& end() {return n;}
};

//output
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){REP(i,as.size()){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T> >& as){REP(i,as.size()){if(i!=0)os<<endl; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){EACH(a,ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){os<<p.first<<" "<<p.second;return os;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;EACH(p,m){if(!isF)os<<endl;os<<p;isF=false;}return os;}

//input
char tmp[1000];
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%lld",&n) //I64d
#define nextDouble(n) scanf("%lf",&n) 
#define nextChar(n) scanf("%c",&n)
#define nextString(n) scanf("%s",tmp);n=tmp

// values
template<class T> T INF(){assert(false);};
template<> int INF<int>(){return 1<<28;};
template<> ll INF<ll>(){return 1LL<<58;};
template<> double INF<double>(){return 1e16;};

template<class Cost> struct Edge{
    int to;Cost cost;
    Edge(int to,Cost cost):to(to),cost(cost){};
    bool operator<(Edge r) const{ return cost<r.cost;}
    bool operator>(Edge r) const{ return cost>r.cost;}
};
template<typename T> ostream& operator << (ostream& os, const Edge<T>& e){ return os<<"(->"<<e.to <<","<<e.cost<<")";}


typedef ll Cost;
typedef vector<vector<Edge<Cost>>> Graph;

template<class Cost> vector<Cost> dijkstra(const Graph& g,const int s){
    vector<Cost> ds(g.size(),INF<Cost>());ds[s]=0;
    priority_queue<pair<Cost,int>,vector<pair<Cost,int>>,greater<pair<Cost,int>>> que;que.push({0,s});// [ ,e,,f, ] <=> e.cost < e.cost
    while(!que.empty()){
        Cost c;int v;tie(c,v)=que.top();que.pop();
        if(ds[v] < c)continue;
        for(const Edge<Cost>& e:g[v]){
            Cost nxtc= c + e.cost;
            if(nxtc<ds[e.to]){
                ds[e.to]=nxtc;
                que.push({nxtc,e.to});
            }
        }
    }
    return ds;
}


class Main{
    public:
    void run(){
        int n,m,r;cin >> n >> m >> r;
        Graph g(n);
        REP(i,m){
            int s,t,d;cin >> s >> t >> d;
            g[s].push_back({t,d});
        }
        auto res = dijkstra<Cost>(g,r);
        for(auto v: res)if(v==INF<Cost>()) cout << "INF" << endl; else cout << v <<endl;
    }
};

int main(){
 cout <<fixed<<setprecision(20);
 cin.tie(0);
 ios::sync_with_stdio(false);
 Main().run();
 return 0;
}
