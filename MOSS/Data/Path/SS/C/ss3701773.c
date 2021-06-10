// 以下のライブラリを使ってみる.
// dr_ken氏.
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1455855#1
#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100001
const long long INF = 1LL<<60;

static int V, E, r;
static vector<pair<int, long long> > graph[MAX_V];
static long long dist[MAX_V];

void bfs(){
    
    // 1. 初期化.
    priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long, int> > > pq;
    for(int i = 0; i < MAX_V; ++i) dist[i] = INF;
    
    // 2. 始点設定.
    dist[r] = 0;
    pq.push(make_pair(0, r));
    
    // 3. 始点から各ノードについて, 最短経路上の辺の重みの総和を保存.
    while(!pq.empty()){
        long long cD = pq.top().first;
        int cV = pq.top().second;
        pq.pop();
        
        if(dist[cV] < cD) continue;

        for(int i = 0; i < graph[cV].size(); ++i){
            int nV = graph[cV][i].first;
            long long nD = cD + graph[cV][i].second;
            if(dist[nV] > nD){
                dist[nV] = nD;
                pq.push(make_pair(nD, nV));
            }
        }
    }
}

int main(){

    // 1. 入力情報.
    scanf("%d %d %d", &V, &E, &r);
    
    // 2. グラフ作成.
    for(int i = 0; i < E; ++i){
        int s, t; long long w;
        scanf("%d %d %lld", &s, &t, &w);
        graph[s].push_back(make_pair(t, w));
    }
    
    // 3. 単一始点最短経路の重み計算.
    bfs();
    
    // 4. 出力.
    for(int i = 0; i < V; ++i){
        if(dist[i] < INF) printf("%lld\n", dist[i]);
        else              printf("%s\n", "INF");
    }
    return 0;

}
