#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

#define _CRT_SECURE_NO_WARNINGS

priority_queue< P , vector<P> , greater<P> > pq;
const int INF=1000100100;
int V,E,r = 0;
struct Edge{
    int to,cost;
};
vector<Edge> edges[100010];
int costs[100010];
bool checked[100010]={};
int main() {
	cin >> V >> E >> r;

	for(int i=0;i<E;i++){
        int s,t,d;
        cin >> s >> t >> d;
        edges[s].push_back( Edge{t,d} );
    }
    for(int i=0;i<V;i++){
        costs[i]=INF;
    }
    costs[r]=0;

    pq.push( P(0,r) );
    while(!pq.empty()){
        int nowCost=pq.top().first;
        int now=pq.top().second;
        pq.pop();
        checked[now]=true;
        for(int i=0;i<edges[now].size();i++){
            Edge e=edges[now][i];
            if(!checked[e.to] && nowCost + e.cost < costs[e.to] ){
                costs[e.to] = nowCost + e.cost;
                pq.push( P(nowCost + e.cost , e.to) );
            }
        }
    }

    for(int i=0;i<V;i++){
        if(costs[i]<INF){
            printf("%d\n", costs[i]);
        }else{
            printf("INF\n");
        }
    }
	return 0;
}
