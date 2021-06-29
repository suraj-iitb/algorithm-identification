#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000001
using namespace std;
struct E{
	int rel,cost;
};
vector <E> grh[100000];
int v,e,r;

void dijkstra(){

	priority_queue < pair <int,int> > Q;
	int sum = 0;
	int d[100000];
	for(int i=0;i<v;i++) d[i] = INF;
	d[r] = 0;
	Q.push(make_pair(0,r));
	int s,f;
	while(!Q.empty()) {
		f = Q.top().first;
		s = Q.top().second;
		Q.pop();
		for(int i=0;i<grh[s].size();i++) {
			E e = grh[s][i];
			if(d[e.rel] > e.cost - f) {
				d[e.rel] = e.cost - f;
				Q.push(make_pair(-d[e.rel],e.rel));
			}
		}
	}
	for(int i=0;i<v;i++) {
		if(d[i] == INF ) cout << "INF"<<endl;
		else cout << d[i] << endl;
	}
}

int main() {
	cin >> v >> e >> r; 
	int a,b,c;
	for(int i=0;i<e;i++) {
		cin >> a >> b>> c;
		grh[a].push_back((E){b,c});
	}
	dijkstra();

	return 0;
}
