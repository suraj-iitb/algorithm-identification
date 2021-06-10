#include<bits/stdc++.h>
#define MAX INT_MAX
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
vector<int> town[100000],cost[100000];
int main(void)
{
	int V,E,R;
	int S,T,D;
	int flg[100000];
	int length[100000];
	
	int X,Y;
	int i;
	priority_queue<P,vector<P>,greater<P>> que;
	P pp;
	
	cin>>V>>E>>R;
	
	for(i=0;i<E;i++){
		cin>>S>>T>>D;
		town[S].push_back(T);
		cost[S].push_back(D);
	}
	
	fill(length,length+V,MAX);
	fill(flg,flg+V,0);
	
	que.push(P(0,R));
	while(que.size()!=0){
		pp=que.top();
		que.pop();
		X=pp.F;
		Y=pp.S;
		if(X<length[Y]){
			length[Y]=X;
			flg[Y]=1;
			
			for(i=0;i<town[Y].size();i++){
				if(flg[town[Y][i]]==0){
					que.push(P(X+cost[Y][i],town[Y][i]));
				}
			}
		}
	}
	
	for(i=0;i<V;i++){
		if(length[i]==MAX){
			cout<<"INF"<<endl;
		}
		else{
			cout<<length[i]<<endl;
		}
	}
	return 0;
}

		
	
	
	
	
	

	

