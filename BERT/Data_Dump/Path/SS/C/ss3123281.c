#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef pair<int,int> P;

priority_queue<P,vector<P>,greater<P> > Que;
vector<int> rin[100000],rin2[100000] ; //隣接   数値　 場所
int v,e,r; //　グラフGの　頂点の数　辺の数　　　スタート
int s,t,d;//  i番目の辺が結ぶ２つの頂点   i 番目の辺の重み
int leng[100000];
int q;
int i,j;

int main(void){
	
	cin>>v>>e>>r;
	for(i=0;i<e;i++){
		cin>>s>>t>>d;
		rin[s].push_back(d);
		rin2[s].push_back(t);
	}
	
	for(i=0;i<v;i++) leng[i]=M;
	
	//rin 確認
	/*cout<<endl;
	cout<<"rin"<<endl;
	for(i=0;i<e;i++){
		for(j=0;j<rin[i].size();j++) cout<<rin[i][j]<<" ";
		cout<<endl;
	}*/
	
	//rin2 確認
	/*cout<<"rin2"<<endl;
	for(i=0;i<e;i++){
		for(j=0;j<rin2[i].size();j++) cout<<rin2[i][j]<<" ";
		cout<<endl;
	}*/
			
	
	leng[r]=0;
	Que.push(P(0,r)); // 数値　 場所
	while(!Que.empty()){
		
		/*for(i=0;i<v;i++) cout<<leng[i]<<" ";
		cout<<endl;*/
		
		P q=Que.top(); Que.pop();
		
		if(leng[q.second]>q.first) continue;
		
		for(i=0;i<rin[q.second].size();i++){
			if(leng[rin2[q.second][i]]>q.first+rin[q.second][i]){
				leng[rin2[q.second][i]]=q.first+rin[q.second][i];
				Que.push(P(leng[rin2[q.second][i]],rin2[q.second][i]));
			}
		}
	}
	
	for(i=0;i<v;i++){
		if(leng[i]==M) cout<<"INF"<<endl;
		else cout<<leng[i]<<endl;
	}
	
	return 0;
}
