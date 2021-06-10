#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
#define int long long
#define inf 5000000000000
int n,m;
int dis[101][101];
#undef int
int main(){
	#define int long long
	cin >> n >> m;
	for(int a = 0;a < n;a++){
		for(int b = 0;b < n;b++){
			dis[a][b] = (a==b)?0:inf;
		} 
	}
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v] = w;
	}
	for(int a = 0;a < n;a++){
		for(int b = 0;b < n;b++){
			//if (a == b) continue;
			for(int c = 0;c < n;c++){
				//if (a == c||b == c) continue;
				if (dis[b][a] == inf||dis[a][c] == inf) continue;
				dis[b][c] = min(dis[b][a]+dis[a][c],dis[b][c]);
			}
		}
	}
	for(int a = 0;a < n;a++){
		if (dis[a][a]){
			cout << "NEGATIVE CYCLE\n";
			return 0;
		}
	}
	for(int a = 0;a < n;a++){
		for(int b = 0;b < n;b++){
            if (dis[a][b] == 5000000000000) cout << "INF";
			else{
				cout << dis[a][b];
			}
			if (b != n-1)cout << ' ';
		}
		cout << '\n';
	}
}


