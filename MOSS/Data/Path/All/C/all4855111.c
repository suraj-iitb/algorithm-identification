#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 100001
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<P1,ll> P2;
typedef list<int> li;
typedef list<li> lli;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	ll a;
	int b;
};
ll dp[101][101];

int main(){

	int n,m;
	cin>>n>>m;
	rep(i,n){
		rep(j,n){
			dp[i][j]=INF;
		}
	}
	rep(i,m){
		int a,b;
		ll t;
		cin>>a>>b>>t;
		dp[a][b]=t;
	}
	rep(i,n)dp[i][i]=0;
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			if(dp[i][k]==INF)continue;
			for(int j=0; j<n; j++){
				if(dp[k][j]==INF)continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=0; i<n; i++){
		if(dp[i][i]<0){
			cout<<"NEGATIVE CYCLE"<<endl;
			return 0;
		}
	}
	for(int i=0; i<n; i++){
		if(dp[i][0]==INF)cout<<"INF";
		else cout<<dp[i][0];
		for(int j=1; j<n; j++){
			if(dp[i][j]==INF)cout<<" INF";
			else cout<<" "<<dp[i][j];
		}
		cout<<endl;
	}

	return 0;
}

