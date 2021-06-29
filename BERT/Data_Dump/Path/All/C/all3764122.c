#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF (1LL<<60)


int main(){
	int v,e,from,to;
	long long graph[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			graph[i][j]=INF;
		}
		graph[i][i]=0;
	}

	cin>>v>>e;
	for(int i=0;i<e;i++){
		cin>>from>>to;
		cin>>graph[from][to];
	}

	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			if(graph[i][k]==INF) continue;
			for(int j=0;j<v;j++){
				if(graph[k][j]==INF)continue;
				graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}

	bool negative=false;
	for(int i=0;i<v;i++){
		if(graph[i][i]<0){
			negative=true;
			break;
		}
	}



	if(negative){
		cout<<"NEGATIVE CYCLE"<<endl;
	}else{
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(j) cout<<" ";

				if(graph[i][j]==INF) cout<<"INF";
				else cout<<graph[i][j];
			}
			cout<<endl;
		}
	}



	return 0;
}

