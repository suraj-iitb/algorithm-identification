#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

ll d[101][101];// d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF、ただしd[i][i]=0とする) 
ll V;// 頂点数
void warshall_floyd() {
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0;j < V; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
	ll e;cin>>V>>e;
	for(int i = 0; i < V; i++) {
		for(int j =  0; j < V; j++) {
			if (i != j){
				d[i][j] = LINF;
			}
		}
	}
	for(int i = 0; i < e; i++) {
		ll s,t,D;cin>>s>>t>>D;
		d[s][t] = D;
	}
	warshall_floyd();

	for(int i = 0; i < V; i++) {
		if (d[i][i] < 0){
				cout << "NEGATIVE CYCLE" << endl;
				return 0;
		}	
	}
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if (d[i][j] < (1LL<<50)){
				cout << d[i][j];
			}
			else{
				cout << "INF";
			}
			if (j != V - 1){
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
