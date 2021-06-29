#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}
};

class WarshallFloyd{
public:
	vector<vector<ll>> dist;

	void CalcShortestPath(ConnectNodeInfo& connect){
		int V = connect.size();
		dist.resize(V,vector<ll>(V,1LL<<60));

		REP(i,V){
			dist[i][i]=0;
			int U = connect[i].size();
			REP(j,U){
				dist[i][connect[i][j].first] = connect[i][j].second;
			}
		}

		REP(k,V){
			REP(i,V){
				REP(j,V){
					if(dist[i][k]!=(1LL<<60) && dist[k][j]!=(1LL<<60)){
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
	}
	
	bool HasNegativeLoop(){
		bool flag = false;
		for(int i=0,ei=dist.size();i<ei;i++){
			if(dist[i][i]<0){
				flag = true;
				break;
			}
		}
		return flag;
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	auto N=in(),Q=in();
	ConnectNodeInfo connect(N);
	REP(i,Q){
		auto u=in(),v=in(),w=in();
		connect.AddDirectionalConnection(u,v,w);
	}
	WarshallFloyd WF;
	WF.CalcShortestPath(connect);
	if(WF.HasNegativeLoop()){
		out("NEGATIVE CYCLE");
		return 0;
	}
	REP(i,N){
		REP(j,N){
			if(WF.dist[i][j]>=(1LL<<60)){
				cout << "INF";
			}
			else{
				cout << WF.dist[i][j];
			}
			if(j==N-1) cout <<endl;
			else cout << ' ';
		}
	}

	return 0;
}

