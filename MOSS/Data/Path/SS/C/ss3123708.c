#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<LL,LL>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    LL from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};
//スタート点,頂点数、辺を渡して、最短経路の配列を返す
std::vector<LL> dijkstra(int s,int N,vector<Edge> E){
    std::vector<LL> ans(N,LINF);
    std::vector<std::vector<Edge>> Edges(N);
    FOREACH(e,E){
        Edges.at(e.from).push_back(e);
    }
    priority_queue<P, std::vector<P>, greater<P>> que;
    ans.at(s)= 0;
    que.push(make_pair(0,s));
    while(!que.empty()){
        P p = que.top();que.pop();
        if(ans.at(p.second) < p.first)continue;
        for(int i = 0;i < Edges.at(p.second).size();i++){
            if(ans.at(p.second) + Edges.at(p.second).at(i).value < ans.at(Edges.at(p.second).at(i).to)){
                ans.at(Edges.at(p.second).at(i).to) = ans.at(p.second) + Edges.at(p.second).at(i).value;
                que.push(make_pair(ans.at(Edges.at(p.second).at(i).to),Edges.at(p.second).at(i).to));
            }
        }
    }
    return ans;
}
int main(){
    CIN(v);CIN(E);
    CIN(r);
    vector<Edge> Edges;
    for(int a = 0;a < E;a++){
        CIN(s);CIN(t);CIN(d);
        Edge e(s,t,d);
        Edges.pb(e);
    }
    V<LL> w = dijkstra(r,v,Edges);
    for(int a = 0;a < v;a++){
        if(LINF == w.at(a)){
            COUT("INF");
        }else{
            COUT(w.at(a));
        }
    }
    return 0;
}

