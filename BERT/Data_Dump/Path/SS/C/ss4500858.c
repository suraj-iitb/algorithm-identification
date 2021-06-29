#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()


struct edge {
    int to;
    int cost;
};

void dijkstra(const vector<vector<edge>>& edges, vector<int>& distance, int start_point) {
    distance[start_point] = 0;

    // P -> first : 最短距離, second : 頂点の番号
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, start_point);

    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        int next = p.second;
        if (distance[next] < p.first){
            continue;
        }
        for(const auto e : edges[p.second]){
            if(distance[e.to] > distance[next] + e.cost){
                distance[e.to] = distance[next] + e.cost;
                que.emplace(distance[e.to], e.to);
            }
        }
    }
}

int main() {

	int v, e, r;
	cin >> v >> e >> r;
    vector<vector<edge>> edges(v);
	rep(i, e){
		int s, t, w;
		cin >> s >> t >> w;
		edges[s].emplace_back((edge){t, w});
	}
	
	vector<int> distance(v, 1000000000);
	dijkstra(edges, distance, r);
	
	for(auto x : distance){
		if(x == 1000000000){
			cout << "INF" << endl;
		}
		else{
			cout << x << endl;
		}
	}

    return 0;
}
