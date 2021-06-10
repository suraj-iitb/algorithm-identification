#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

const LL LINF=334ll<<53;
// start, goal, graph, previous vertex on the shortest pass (prev[start]=-1)
typedef pair<LL,int> PLI;
struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to,LL cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

LL dijkstra(const int start,const int goal, const vector<vector<Edge>> &graph , vector<PLI> &prev){
    typedef pair<LL,int> pii;
    fill(prev.begin(),prev.end(),make_pair(LINF,-1));
    int N = graph.size();
    vector<char> visited(N,false);
    // <<cost , place>, prev>
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>> > Q;
    Q.push(make_pair(make_pair(0,start),-1));
    while(!Q.empty()){
        LL cost;
        int place,from;
        cost = Q.top().first.first;
        place = Q.top().first.second;
        from=Q.top().second;
        Q.pop();
        if(visited[place]) continue;
        prev[place].second=from;
        prev[place].first=cost;
        //if(place == goal) return cost;
        visited[place] = true;
        for(int j=0;j<(int)graph[place].size();j++){
            Q.push(make_pair(make_pair(graph[place][j].cost+cost,graph[place][j].to),place));
        }
    }
    return -1;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,s,t; //vertex,edge
    cin >> n >> m>>s;
    Graph G(n);
    vector<PLI> prev(n);

    for(int i=0;i<m;i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        G[a].push_back(Edge(a,b,cost));
        //G[b].push_back(Edge(b,a,cost));
    }

    dijkstra(s,n-1,G,prev);
    REP(i,n){
        if(prev[i].first==LINF)cout << "INF"<<endl;
        else cout << prev[i].first<<endl;
    }

    return 0;
}
