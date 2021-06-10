#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000
#define MAX_V 100010

struct edge{int to,cost;};
struct Dijkstra{
	int V;
	vector<edge> G[MAX_V];
	int d[MAX_V];
	void init(int v){V=v;}
	void add_edge(int from,int to,int cost){
		G[from].push_back((edge){to,cost});
	}
	void shortpath(int s){
		fill(d,d+V,INF);
		priority_queue<P, vector<P>, greater<P> > que;
		que.push(P(0,s));
		while(!que.empty()){
			P np=que.top(); que.pop();
			int v=np.second;
			if(d[v]!=INF)continue;
			d[v]=np.first;
			for(int i=0;i<G[v].size();i++){
				que.push(P(d[v]+G[v][i].cost,G[v][i].to));
			}
		}
	}
};

Dijkstra djk;
int V,E,s;

int main(){
	cin.sync_with_stdio(false);
	cin>>V>>E>>s;
	djk.init(V);
	rep(i,E){
		int a,b,c;
		cin>>a>>b>>c;
		djk.add_edge(a,b,c);
	}
	djk.shortpath(s);
	rep(i,V){
		if(djk.d[i]==INF)cout<<"INF"<<endl;
		else cout<<djk.d[i]<<endl;
	}
	return 0;
}
