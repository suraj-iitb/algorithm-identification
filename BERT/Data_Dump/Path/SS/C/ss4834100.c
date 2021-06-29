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
ll dp[100001];
int d[500005],y[500005];
vector<vector<int> > t(MAX_N);
int s[100001];
priority_queue<Pli,vector<Pli>,greater<Pli> > que;

int main(){

	int v,e,r;
	cin>>v>>e>>r;

	rep(i,e){
		int x;
		cin>>x>>y[i]>>d[i];
		t[x].push_back(i);
		s[x]++;
	}
	rep(i,v)dp[i]=INF;
	dp[r]=0;
	rep(i,s[r]){
		dp[y[t[r][i]]]=d[t[r][i]];
		que.push(make_pair(dp[y[t[r][i]]],y[t[r][i]]));
	}

	while(!que.empty()){
		Pli top=que.top();
		que.pop();
		if(top.first>dp[top.second])continue;
		rep(j,s[top.second]){
			if(dp[y[t[top.second][j]]]>d[t[top.second][j]]+dp[top.second]){
				dp[y[t[top.second][j]]]=d[t[top.second][j]]+dp[top.second];
				que.push(make_pair(dp[y[t[top.second][j]]],y[t[top.second][j]]));
			}
		}
	}
	rep(i,v){
		if(dp[i]==INF)cout<<"INF"<<endl;
		else cout<<dp[i]<<endl;
	}

	return 0;
}

