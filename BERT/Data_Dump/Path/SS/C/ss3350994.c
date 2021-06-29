#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
using namespace std;
typedef pair<int,int>P;
typedef vector<P>VP;
typedef vector<int>V;
V town[100001],cost[100001];
int d[100001];
bool flg[100001];
int main(void){
	int n,m,s;
	int f,t,c;
	int i,j;
	
	priority_queue<P,VP,greater<P> >que;
	P pp;
	int x,y;
	int b,bc;
	
	cin>>n>>m>>s;
	for(i=0;i<m;i++){
		cin>>f>>t>>c;
		town[f].PB(t);
		cost[f].PB(c);
	}
	
	fill(d,d+n,INT_MAX);
	fill(flg,flg+n,false);
	
	
	que.push(make_pair(0,s));
	while(!que.empty()){
		pp=que.top();	que.pop();
		x=pp.F;	y=pp.S;
		if(!flg[y]){
			d[y]=x;
			flg[y]=true;
			for(i=0;i<town[y].size();i++){
				b=town[y][i];
				bc=cost[y][i];
				if(!flg[b]){
					que.push(make_pair(x+bc,b));
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(d[i]==INT_MAX)	cout<<"INF"<<endl;
		else				cout<<d[i]<<endl;
	}
	return 0;
}
	
	
