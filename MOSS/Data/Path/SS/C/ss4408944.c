#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int n,m;
vector<pair<ll,ll>> g[100000];
ll d[100000];


void dikestra(int s)
{
	d[s]=0;
	priority_queue<P,vector<P>,greater<>> PQ;
	PQ.push(P(0,s));
	d[s]=0;
	while (!PQ.empty())
	{
		P now = PQ.top();
		ll v = now.second;
		PQ.pop();
		if(d[v]<now.first)continue;
		for(int i = 0;i<g[v].size();++i)
		{
			P next = g[v][i];
			if(d[next.first]>d[v]+next.second)
			{
				d[next.first] = d[v]+next.second;
				PQ.push(P(d[next.first],next.first));
			}
		}
	}
	
}

int main()
{
	for(int i = 0;i<100000;i++)d[i]=1e18;
	int s,t;
	cin >> n >> m;
	cin  >> s ;
	//s--;
	t--;
	for(int i = 0;i<m;i++)
	{
		ll u,v,d;
		cin >> u >> v >> d;
		//v--;
		//u--;
		g[u].emplace_back(v,d);
		//g[v].emplace_back(u,d);
	}
	dikestra(s);
	for(int i = 0;i<n;i++)
	{
		if(d[i]==1e18)cout<<"INF"<<endl;
		else cout<<d[i]<<endl;
	}
}
