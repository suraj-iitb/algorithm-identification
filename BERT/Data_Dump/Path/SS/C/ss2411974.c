#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>


#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 999999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 

using namespace std;

typedef struct {
    int cost;
    int to;
} Edge;

typedef pair<int,int> p;// first: ????????????second: ????´???????


int main(void){
    
    int n_vertex;
    int n_edge;
    int start;
    priority_queue<p , vector<p> , greater<p> > costs;
    
    cin >> n_vertex >> n_edge >> start;
    
    int now_cost[n_vertex];
    vector<Edge> G[n_vertex];
    
    REP(i,n_edge){
        int f,t,c;
        cin >> f>>t>>c;
        G[f].push_back((Edge){c,t});
    }
    
    
    REP(i,n_vertex)now_cost[i] = INF;
    
    now_cost[start] = 0;
    costs.push(p(0,start));
    
    while( costs.size() ){
        p pp = costs.top();costs.pop();
        if( now_cost[pp.second] < pp.first ) continue;
        
        int f = pp.second;
        
        REP(i,G[f].size()){
            int t = G[f][i].cost + pp.first;
            if( t < now_cost[G[f][i].to] ){
                now_cost[G[f][i].to] =t ;
                costs.push(p(t,G[f][i].to));
            }
        }
    }
    
    REP(i,n_vertex){
        if( now_cost[i] == INF )
            cout << ("INF") << endl;
        else
            cout << now_cost[i] << endl;
    }
    
    
    return 0;
}
