#include<bits/stdc++.h>
using namespace std;
#define mx 1000000007
#define F first
#define S second
typedef pair<int,int> P;
int main()
{
	int n,m,s;
	int a,b,c;
	int i,j,k,mn,pp;
	
	cin>>n>>m>>s;
	int d[n];
	vector<P> v[n];
	
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		v[a].push_back(P(b,c));
	}

	priority_queue<P, vector<P>, greater<P> >que;
	fill(d,d+n,mx);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
	
		P p=que.top(); que.pop();
		int x=p.S;
		if(d[x]<p.F) continue;
		for(i=0;i<v[x].size();i++){
			P z=v[x][i];
			if(d[z.F]>d[x]+z.S){
				d[z.F]=d[x]+z.S;
				que.push(P(d[z.F],z.F));
			}
		}
	}	

	for(i=0;i<n;i++){
		if(d[i]==mx) cout<<"INF"<<endl;
		else cout<<d[i]<<endl;
	}
	return 0;
}	
