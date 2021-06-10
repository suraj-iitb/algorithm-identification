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
	
	int dp[3100][3100];
	



	void solve(){

		
		ini(n,n1);
		FOR(i,0,3100)FOR(i1,0,3100)dp[i][i1] = inf;
		FOR(i,0,3100)dp[i][i] = 0;
		FOR(i,0,n1){
			ini(tmpx,tmpx1,tmpp);
			dp[tmpx][tmpx1] = tmpp;
		}
		FOR(i,0,n){
			FOR(i1,0,n){
				FOR(i2,0,n){
					if(dp[i1][i] == inf or dp[i][i2] == inf)continue;
					dp[i1][i2] = min(dp[i1][i2],dp[i1][i]+dp[i][i2]);
					//out(i1,i2,dp[i1][i2]);
				}
			}
		}
		FOR(i,0,n)if(dp[i][i]<0)	return out("NEGATIVE CYCLE");
		FOR(i,0,n){
			FOR(i1,0,n){
				if(dp[i][i1] == inf)cout<<"INF";
				else cout<<dp[i][i1];
				if(i1!=n-1)cout<<" ";
			}
			out();
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

