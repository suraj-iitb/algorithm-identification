#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define f first
#define s second
typedef pair<int,int> P;
int n,m,r,i,j,a,b,c,x,y;
int sum[100000],flg[100000];
vector<int>  om[100000],hc[100000];
int main(void)
{
	P p;
	priority_queue<P,vector<P>,greater<P> > qu;
	
	cin>>n>>m>>r;
	for(i=0;i<n;i++) sum[i]=M,flg[i]=0;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		hc[a].push_back(b);
		om[a].push_back(c);
	}
	qu.push(P(0,r));
	sum[r]=0;
	while(qu.size()!=0){
		p=qu.top();
		qu.pop();
		if(flg[p.s]==0){
			flg[p.s]=1;
			for(i=0;i<om[p.s].size();i++){
				x=hc[p.s][i];
				y=om[p.s][i];
				if(sum[x]>p.f+y){
					sum[x]=p.f+y;
					qu.push(P(sum[x],x));
				}
			}
		}
	}
	for(i=0;i<n;i++) {
		if(sum[i]!=M) cout<<sum[i]<<endl;
		else cout<<"INF"<<endl;
	}
	return 0;
}
