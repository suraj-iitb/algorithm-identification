#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

struct edge{
	int to, cost;
};

int V, E, s;
vector<edge> e[100000];

vector<int> bellman_ford(){
	vector<int> d(V, INF);
	d[s]=0;
	
	while(1){
		bool flag=0;
		
		REP(i, V){
			REP(j, e[i].size()){
				edge ne=e[i][j];
				if(ne.cost!=INF && d[ne.to]>d[i]+ne.cost){
					d[ne.to]=d[i]+ne.cost;
					flag=1;
				}
			}
		}
		
		if(!flag) break;
	}
	
	return d;
}

int main(){
	cin >> V >> E >> s;
	
	REP(i, E){
		int f, t, d;
		cin >> f >> t >> d;
		e[f].push_back((edge){t, d});
	}
	
	vector<int> d;
	d=bellman_ford();
	
	REP(i, V){
		if(d[i]==INF) cout << "INF";
		else cout << d[i];
		cout << endl;
	}
}
