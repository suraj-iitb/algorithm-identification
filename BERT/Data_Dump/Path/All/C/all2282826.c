#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define VMAX 102
#define EMAX 9905
#define INF (long long)1e18

//??????????????¢??????????????¨debug()??????????????????
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

ll V,E,ans,d[VMAX][VMAX];
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
dy[8] = {1,1,0,-1,-1,-1,0,1};

struct edge{
	ll to,cost;
};
vector<edge> G[VMAX];

void solve(){
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			for (int k = 0; k < V; ++k)
			{
				if(d[j][i] != INF && d[i][k] != INF){
					d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
				}
			}
		}
	}
}

void debug(){

}

int answer(){
	for (int i = 0; i < V; ++i)
	{
		if(d[i][i] < 0){
			cout << "NEGATIVE CYCLE\n";
			return 0;
		}
	}
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			if(i == j){
				cout << "0";
			}else if(d[i][j] == INF){
				cout << "INF";
			}else{
				cout << d[i][j];
			}
			if(j != V-1){
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

int main(){
	cin >> V >> E;
	Fill(d,INF);
	for (int i = 0; i < E; ++i)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		G[a].push_back((edge){b,c});
		d[a][b] = c;
	}
	solve();
	#ifdef DEBUG
	debug();
	#endif
	ans = answer();

	return 0;
}
