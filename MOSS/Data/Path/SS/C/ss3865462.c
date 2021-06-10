#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
using namespace std;
typedef pair<int,int>P;
typedef vector<P>VP;
typedef priority_queue<P,VP,greater<P>>PQ;
int flg[100000],d[100000];
VP v[100000];
int main(void){
	int n,m,s;
	int x,y,cost;
	int now,next;
	int now_cost,next_cost;
	int i,j;
	int flag;
	P pp;
	PQ que;
	cin>>n>>m>>s;
	for(i=0;i<n;i++){
		flg[i]=0;
		d[i]=INT_MAX;
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>cost;
		v[x].PB(P(cost,y));
	}
	que.push(P(0,s));
	while(!que.empty()){
		pp=que.top();
		que.pop();
		now_cost=pp.F;
		now=pp.S;
		if(flg[now]==0){
			flg[now]=1;
			d[now]=now_cost;
			for(i=0;i<(int)v[now].size();i++){
				next_cost=v[now][i].F;
				next=v[now][i].S;
				if(flg[next]==0)	que.push(P(now_cost+next_cost,next));
			}
		}
	}
	for(i=0;i<n;i++){
		if(d[i]==INT_MAX)	cout<<"INF"<<endl;
		else				cout<<d[i]<<endl;
	}
	return 0;
}
