#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1001001001;
struct Edge{
    int dst;//辺の終点
    int cost;//辺の重み
    //辺の重みで大小比較できるようにする
    //greater<Edge>で優先度付きキューの処理順を変更するので
    //比較演算子> （大なり記号）をオーバーロードする
    bool operator>(const Edge& other) const {
        return cost > other.cost;
    }
};

int main(){
    int v, e, r;
    cin >> v >> e >> r;
    //G[始点となる頂点の番号]は{終点，辺の重み}を記録する構造体の配列
    vector<vector<Edge>> G(v);
    for(int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    //辺の重みの昇順で要素が取り出されるような優先度付きキューを用意する
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    //最短経路上の重みの総和を記録する配列
    vector<int> mincost(v, INF);
    //始点をQに投入する
    Edge startedge = {r, 0};
    Q.push(startedge);
    while(Q.size()){
        Edge cur = Q.top();
        Q.pop();

        if(mincost[cur.dst] != INF) continue;
        mincost[cur.dst] = cur.cost;
        for(int i = 0; i < G[cur.dst].size(); i++){
            Q.push({G[cur.dst][i].dst,
            cur.cost + G[cur.dst][i].cost});
        }
    }

    for(int i = 0; i < v; i++){
        if(mincost[i] == INF) cout << "INF" << endl;
        else cout << mincost[i] << endl;
    }
    return 0;
}
