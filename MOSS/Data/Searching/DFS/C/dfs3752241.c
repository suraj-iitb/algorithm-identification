#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

//辺の情報を個別に持つタイプ
typedef struct edge{ll s,g;}E;
typedef struct graph{
	int vcnt,ecnt;
	E  e[200010];//適宜変える
	int id[100010];//適宜変える
}G;

int esort(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

G g;
void readgraph(){
	//適宜変える
	ll n;
	ll m=0;
	scanf("%lld",&n);
	rep(i,0,n){
		ll t,k;
		scanf("%lld%lld",&t,&k);
		while(k--){
			int s;
			scanf("%d",&s);
			g.e[m].s=t;
			g.e[m].g=s;
			m++;
		}
	}
	g.vcnt=n+1;
	g.ecnt=m;
	qsort(g.e,g.ecnt,sizeof(E),esort);
//	qsort(g.e,g.ecnt,sizeof(E),csort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵
}


int in[110];
int out[110];
int time;
//dfs
ll dfs(int v,int pre){
	in[v]=++time;
	rep(i,g.id[v],g.id[v+1]){
		if(!in[g.e[i].g]){
			dfs(g.e[i].g,v);
		}
	}
	out[v]=++time;
}

int main(){
	readgraph();
	for(int i=1;i<g.vcnt;i++)if(!in[i])dfs(i,-1);
	for(int i=1;i<g.vcnt;i++)printf("%d %d %d\n",i,in[i],out[i]);
}
