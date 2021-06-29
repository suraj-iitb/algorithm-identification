#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111
	
	int tmp[310000];
	vpii morty[310000];

	void dijkstra(int x){
		queue<pair<int,int>>queue1;
		queue1.push({x,0});
		while(!queue1.empty()){
			pair<int,int> first = queue1.front();
			queue1.pop();
			FORR(x1,morty[first.first]){
				if(tmp[x1.first]<=first.second+x1.second)continue;
				queue1.push({x1.first,first.second+x1.second});
				tmp[x1.first] = first.second+x1.second; 
			}
		}
	}



	void solve(){

		
		ini(n,n1,x);
		FOR(i,0,n)tmp[i] = inf;
		tmp[x] = 0;
		FOR(i,0,n1){
			ini(tmpx,tmpx1,tmpp);
			morty[tmpx].push_back({tmpx1,tmpp});
		}
		dijkstra(x);
		FOR(i,0,n){
			if(tmp[i] == inf)out("INF");
			else out(tmp[i]);
		}
		
		
		

		


		
		
	}



	



















int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}

