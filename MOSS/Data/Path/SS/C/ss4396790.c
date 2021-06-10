#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

const string YES = "Yes";
const string NO = "No";

#define MAX_V 1000000

#define MAX_V 1000000
struct edge{
    lli to;
    lli cost;
};
bool operator< (const edge &l, const edge &r){
    return l.cost < r.cost;
}
bool operator> (const edge &l, const edge &r){
    return l.cost > r.cost;
}
vector<edge> G[MAX_V];
vector<lli> dijkstra(lli s,lli num){
    priority_queue<edge,vector<edge>,greater<edge>> que;
    vector<lli> d(num+2,INF);
    //fill(d,d+n+2,INF);
    d[s]=0;
    que.push({s,0});

    while(!que.empty())
    {
        edge p = que.top();
        que.pop();
        lli v = p.to;
        if(d[v] < p.cost)continue;

        for(lli i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push({e.to,d[e.to]});
            }
        }
    }
    return d;
};

int main(){
    // cout << fixed << setprecision(5);

    lli V,E,R;
    cin>>V>>E>>R;

    REP(i,0,E){
        lli s,t,d;
        cin>>s>>t>>d;
        G[s].push_back({t,d});
    }

    auto d = dijkstra(R,V);

    REP(i,0,V){
        if(d[i] != INF)cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }

    return 0;
}

