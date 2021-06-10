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


namespace EGraph{
    typedef ll Cost;Cost CINF=INF<Cost>();
    struct Edge{
        int from,to;Cost cost;
        Edge(int from,int to,Cost cost)
        : from(from),to(to),cost(cost) {};
        bool operator<(Edge r) const{ return cost<r.cost;}
        bool operator>(Edge r) const{ return cost>r.cost;}
    };
    typedef vector<vector<Edge> >  Graph;
}
using namespace EGraph;

namespace ShortestPath{
    using namespace EGraph;

    struct Task{
        int prev,pos;Cost cost;
        Task(int prev,int pos,Cost cost)
            :prev(prev),pos(pos),cost(cost){};
        bool operator>(const Task& r) const{ return cost > r.cost;}
    };

     // 最大も可 負の閉路が判定可能
    //O(V*E)
    vector<Cost> bellmanFord(const Graph& g,const int s,vector<int>& prev){
        const int V=g.size();
        vector<Cost> d(V,CINF);d[s] = 0;
        fill(ALL(prev),-2);
        REP(loop,V){
            REP(v,V)EACH(e,g[v])if(d[v] != CINF)if(d[e->to] > d[v] + e->cost){
                d[e->to] = d[v] + e->cost;
                prev[e->to] = e->from;
                if(loop==V-1)d[e->to] = -CINF;
            }
        }
        return d;
    }
    vector<Cost> bellmanFord(const Graph& g,const int s){
        vector<int> prev(g.size());return bellmanFord(g,s,prev);
    }
}
using namespace ShortestPath;

stringstream ss;
class Main{
    public:
    void run(){
        int n,m;cin >> n >> m;
        Graph g(n);
        REP(i,m){
            int s,t,d;cin >> s >> t >> d;
            g[s].push_back(Edge(s,t,d));
        }
        vector<vector<string>> res(n,vector<string>(n));
        REP(r,n){
            auto ds = bellmanFord(g,r);
            for(auto v: ds)if(v==-CINF){
                cout <<"NEGATIVE CYCLE"<<endl;return;
            }
            REP(i,n){
                if(ds[i]==CINF)res[r][i]="INF";
                else{
                    ss<< ds[i];ss >> res[r][i];ss.clear();
                }
            }
        }
        cout << res <<endl;
    }
};

int main(){
 cout <<fixed<<setprecision(20);
 cin.tie(0);
 ios::sync_with_stdio(false);
 Main().run();
 return 0;
}
