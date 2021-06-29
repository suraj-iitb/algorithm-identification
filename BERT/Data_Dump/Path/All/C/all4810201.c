#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
typedef pair<ll, ll> P;
//const int MAX=10100;
const ll INF=1LL<<60;

int v,e;
ll dist[110][110];
void warshall_floyd(){
  rep(k,v)rep(i,v)rep(j,v){
    chmin(dist[i][j],dist[i][k]+dist[k][j]);
  }	
}
int main() {
	cin>>v>>e;
	rep(i,v)rep(j,v)dist[i][j]=INF;
	rep(i,v)dist[i][i]=0;
	rep(i,e){
    int s,t,d;
		cin>>s>>t>>d;
		dist[s][t]=d;
	}
  warshall_floyd();
	rep(i,v)rep(j,v)rep(k,v){
    if(dist[i][j]>dist[i][k]+dist[k][j]){
			puts("NEGATIVE CYCLE");
			return 0;	
		}
	}
	rep(i,v)rep(j,v){
    if(dist[i][j]<=1e10){
      if(j!=v-1)cout<<dist[i][j]<<" ";
      else cout<<dist[i][j]<<endl;
		}else {
      if(j!=v-1)cout<<"INF ";
      else cout<<"INF\n";
    }
	}
	return 0;
}
