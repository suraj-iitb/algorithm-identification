#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second



int dijkstra(int n,int s,vector<mp>* vs,int* dist,int g=-1){
	memset(dist,-1,sizeof(int)*n);
	//rep(i,n)dist[i]=-1;
	priority_queue<mp,vector<mp>,greater<mp> > que;
	que.push(mp(0,s));
	while(!que.empty()){
		mp pa=que.top();
		que.pop();
		int co=pa.fir,
			no=pa.sec;
		if(dist[no]!=-1 && dist[no]<co)continue;
		dist[no]=co;
		if(no==g)return co;
		rep(i,vs[no].size()){
			mp pb=vs[no][i];
			int to=pb.fir,
				tc=co+pb.sec;
			if(dist[to]!=-1 && dist[to]<=tc)continue;
			dist[to]=tc;
			que.push(mp(tc,to));
		}
	}
	return -1;
}


int n,m;

vector<mp> vs[100005];


int dist[100005];




int main(void){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	rep(i,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		vs[a].push_back(mp(b,c));
		//vs[b].push_back(mp(a,c));
	}
	dijkstra(n,s,vs,dist);
	rep(i,n){
		if(dist[i]!=-1)printf("%d\n",dist[i]);
		else printf("INF\n");
	}
	return 0;
	
}
