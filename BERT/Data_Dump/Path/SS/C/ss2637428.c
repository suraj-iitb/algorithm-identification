#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long int llg;

template <typename T>
using reverse_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

const int INF = 1000001000;
#define REP(var, count) for(int var=0; var<count; var++)


int vert[100010];
vector<pair<int, int> > edge[500010];

int main(void) {
	int V, E, r;
	scanf("%d", &V);
	scanf("%d", &E);
	scanf("%d", &r);
	
	REP(v, V) { vert[v] = INF; }
	vert[r] = 0;
	
	REP(i, E) {
		int s, t, d;
		scanf("%d", &s);
		scanf("%d", &t);
		scanf("%d", &d);
		
		edge[s].push_back( make_pair(t, d) );
	}
	
	reverse_queue<pair<int, int> > que;
	que.push(make_pair(0, r));
	
	while( que.size() ) {
		auto nx = que.top();
		que.pop();
		
		int s = nx.second;
		
		for( auto e : edge[s] ) {
			int t = e.first;
			int d = e.second;
			if ( vert[s]+d < vert[t] ) {
				vert[t] = vert[s] + d;
				que.push(make_pair(vert[t], t));
			}
		}
	}
	
	REP(v, V) {
		if ( vert[v] == INF ) {
			cout << "INF" << endl;
		} else {
			cout << vert[v] << endl;
		}
	}

}
