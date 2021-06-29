#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

//辺の情報を個別に持つタイプ
typedef struct edge{ll s,g,c;}E;
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
			g.e[m].c=1;
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

//ベルマンフォード
//グラフと始点を引いて単一始点最短経路を返す
//辺のソートは不要
//O(EV)、負辺ありでもOK
//*
ll d[1010];
void berumanfoodo(G g,ll s){
	rep(i,0,g.vcnt)d[i]=i==s?0:INF;
	rep(nnnn,0,g.vcnt-1)rep(i,0,g.ecnt)if(d[g.e[i].s]!=INF)d[g.e[i].g]=min(d[g.e[i].g],d[g.e[i].s]+g.e[i].c);
	rep(nnnn,0,g.vcnt)rep(i,0,g.ecnt)if(d[g.e[i].s]!=INF){
		if(d[g.e[i].g]>d[g.e[i].s]+g.e[i].c)d[g.e[i].g]=-INF;
	}
}
//*/

int main(){
	readgraph();
	berumanfoodo(g,1);
	for(int i=1;i<g.vcnt;i++)printf("%d %d\n",i,d[i]==INF?-1:d[i]);
}
