#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
struct Point {
	int v, e;
	bool operator<(const Point b)const {
		return this->e > b.e;
	}
	Point(int a, int b) :v(a), e(b) {}
	Point() :v(0), e(0) {}
};

ll d[100000];
bool visit[100000] = { 0 };
vector <Point> G[100000];
priority_queue <Point> PQ;

const ll INF = 1e18;

void dj(int n, int r) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[r] = 0;
	PQ.push(Point(r, 0));
	Point p, q;
	while (!PQ.empty()) {
		p = PQ.top(); PQ.pop();
		visit[p.v] = 1;
		int du = G[p.v].size();
		for (int i = 0; i < du; i++) {
			q = G[p.v][i];
			if (!visit[q.v] && q.e + d[p.v] < d[q.v]) {
				d[q.v] = q.e + d[p.v];
				PQ.push(Point(q.v, d[q.v]));
			}
		}
	}
}
int main()
{
	int V, E, r, s, t, di; 
	scanf("%d%d%d", &V, &E, &r);
	while (E--) {
		scanf("%d%d%d", &s, &t, &di);
		G[s].push_back(Point(t, di));
	}
	dj(V, r);
	for (int i = 0; i < V; i++)
		if(d[i] == INF) puts("INF");
		else printf("%lld\n", d[i]);
	return 0;
}
