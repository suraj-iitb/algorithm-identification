#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> P;
struct Edge{ int to, cost; };
const int INF = 1 << 30;
const int V = 100010;
vector<Edge> list[V];
int d[V];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int v, e, r;
	cin >> v >> e >> r;
	
	int a, b, c;
	for(int i = 0; i < e; ++i){
		cin >> a >> b >> c;
		list[a].push_back(Edge{b, c});
	}
	
	priority_queue<P, vector<P>, greater<P> > pque;
	fill(d, d + v, INF);
	d[r] = 0;
	pque.push(P(0, r));
	
	while(!pque.empty()){
		P p = pque.top();
		pque.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		
		for(size_t i = 0; i < list[v].size(); ++i){
			Edge e1 = list[v][i];
			if(d[e1.to] > d[v] + e1.cost){
				d[e1.to] = d[v] + e1.cost;
				pque.push(P(d[e1.to], e1.to));
			}
		}
	}
	
	for(int i = 0; i < v; ++i){
		if(d[i] == INF)
			cout << "INF";
		else
			cout << d[i];
		cout << endl;
	}
	
	return 0;
}
