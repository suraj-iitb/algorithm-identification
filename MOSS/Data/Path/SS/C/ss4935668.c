#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=(n); i--)
#define LREP(lst,itr) for(auto itr = lst.begin(); itr != lst.end(); ++itr)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define P(s) cout<<(s)<<endl
#define P2(a, b) cout<<(a)<<" "<<(b)<<endl
#define P3(a, b, c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define V2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const ll NODE_SIZE = 101010;
vector<pair<ll, ll>> graph[NODE_SIZE];
ll dist[NODE_SIZE];
ll V, E, start;

// //ダイクストラ法
// void dijkstra() {
//     priority_queue<pair<ll, ll> > PQ;  //<(-1)*最短距離, ノード番号>

//     REP(i, 0, V) dist[i] = INF;
//     dist[start] = 0;
//     PQ.push(make_pair(0, start));  //開始ノードを0とする。

//     while (!PQ.empty()) {
//         ll curCost = -PQ.top().first;
//         ll curNode = PQ.top().second;
//         PQ.pop();

//         if (dist[curNode] < curCost) continue;
//         dist[curNode] = curCost;

//         REP(i, 0, graph[curNode].size()) {
//             ll nextNode = graph[curNode][i].first;
//             ll addCost = graph[curNode][i].second;

//             if (dist[nextNode] > dist[curNode] + addCost) {
//                 dist[nextNode] = dist[curNode] + addCost;
//                 //rev[nextNode] = curNode; // ** 最短経路のルートが欲しい場合
//                 PQ.push(make_pair(-dist[nextNode], nextNode));
//             }
//         }
//     }
// }

// class cmp{
//     public:
//     bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b){
//         return a.second < b.second;
//     }
// };

void dijkstra(){
    REP(i, 0, V){
        if(i==start){
            dist[i]=0;
        }else{
            dist[i]=INF;
        }
    }
    // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair(0, start));
    pair<ll, ll> current_node_info;
    ll current_node;
    ll current_dist;
    while(!pq.empty()){
        current_node_info = pq.top();
        pq.pop();
        current_dist = -current_node_info.first;
        current_node = current_node_info.second;

        if(dist[current_node] < current_dist) continue;
        dist[current_node] = current_dist;

        for(auto next_node_info: graph[current_node]){
            ll next_node = next_node_info.first;
            ll next_dist = next_node_info.second;
            if(dist[next_node] > current_dist + next_dist){
                dist[next_node] = current_dist + next_dist;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }
}

int main(){
    cin >> V >> E >> start;
    REP(i, 0, E){
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(make_pair(t, d));
    }
    dijkstra();
    REP(i, 0, V){
        if(dist[i]==INF){
            P("INF");
        }else{
            P(dist[i]);
        }
    }
}
