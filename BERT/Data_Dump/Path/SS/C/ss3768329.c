#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define INF (1<<30)
#define BLACK 0
#define GRAY 1
#define WHITE 2

int n;
vector< pair<int,int> > graph[MAX];
int d[MAX];

// プロトタイプ宣言
void dijkstra(int r);
// ここまで

int v,e;
int main(){
	int r;
	cin>>v>>e>>r;
	int s,t,cost;
	for(int i=0;i<e;i++){
		cin>>s>>t>>cost;

		graph[s].push_back( make_pair(t,cost) );
	}

	dijkstra(r);

	for(int i=0;i<v;i++){
		if(d[i]==INF)cout<<"INF"<<endl;
		else cout<<d[i]<<endl;
	}

	return 0;
}

void dijkstra(int r){
	priority_queue< pair<int,int> > PQ;
	int color[MAX];
	for(int i=0;i<v;i++){
		d[i]=INF;
		color[i]=WHITE;
	}

	d[r]=0;
	PQ.push(make_pair(0,r));		// （重み、ノード番号）
	color[r]=GRAY;


	while(PQ.empty()==false){
		pair<int,int> f=PQ.top();	PQ.pop();
		int from = f.second;
		color[from]=BLACK;

		if(d[from] < f.first*(-1) )continue;

		for(pair<int,int> next:graph[from]){
			int to=next.first;
			int w=next.second;
			if(color[to]==BLACK) continue;

			if(d[to]>d[from]+w){
				d[to]=d[from]+w;

				PQ.push( make_pair(d[to]*(-1), to) );
				color[to]=GRAY;
			}
		}
	}
}

