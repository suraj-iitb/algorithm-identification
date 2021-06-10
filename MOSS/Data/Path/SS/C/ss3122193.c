#include<cstdio>
#include<functional>
#include<algorithm>
#include<queue>
#include<vector>
#define MM 210000000000000000
using namespace std;
typedef pair<long long,int> P;
vector<int> mati[100000],cost[100000];
int main(void)
{
	int i,n,m,j,b,c,d,p,s,t,r,v,e,flg[100000];
	long long leng[100000],a;

	priority_queue<P,vector<P>,greater<P> > que;
	P ppp;
	scanf("%d %d %d",&v,&e,&r);
	for(i=0;i<e;i++)	{
		scanf("%d %d %d",&s,&t,&d);
		mati[s].push_back(t);
		cost[s].push_back(d);
	}

	for(i=0;i<v;i++)	{
		leng[i]=MM;	flg[i]=0;
	}
	que.push(P(0,r));
	while(que.size()!=0)	{
		ppp=que.top();	que.pop();
		a=ppp.first;	b=ppp.second;
		if(a<leng[b])	{
			leng[b]=a;	flg[b]=1;
			for(i=0;i<mati[b].size();i++)	{
				if(flg[mati[b][i]]==0)	{
					que.push(P(a+cost[b][i],mati[b][i]));
				}
			}
		}
	}
	for(i=0;i<v;i++)	{
		if(leng[i]==MM)	printf("INF\n");
		else printf("%lld\n",leng[i]);
	}
	return 0;
}
