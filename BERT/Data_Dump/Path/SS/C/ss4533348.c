#include<bits/stdc++.h>
using namespace std;
struct pr{
	int cost,to;
	bool operator>(const pr&oth)const{return this->cost>oth.cost;}
};

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int v,e,r; cin>>v>>e>>r;
	vector<vector<pr>>g(v);
	for(int i=0;i<e;++i){
		int s,t,d; cin>>s>>t>>d;
		g.at(s).push_back({d,t});
	}
	vector<int>mn(v,2e9); mn.at(r)=0;
	priority_queue<pr,vector<pr>,greater<pr>>q;
	q.push({0,r});
	while(q.size()){
		int nw=q.top().to,nwcost=q.top().cost; q.pop();
		if(nwcost>mn.at(nw))continue;
		for(auto&&i:g.at(nw)){
			int nxp=i.to,nxcost=nwcost+i.cost;
			if(nxcost>mn.at(nxp))continue;
			mn.at(nxp)=nxcost;
			q.push({nxcost,nxp});
		}
	}
	for(auto&&i:mn){
		if(i!=2e9)cout<<i;
		else cout<<"INF"s;
		cout<<"\n"s;
	}
}
