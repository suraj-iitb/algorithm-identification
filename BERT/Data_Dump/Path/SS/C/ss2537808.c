#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<functional>

using namespace std;

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;

#ifdef DEBUG
#define dprintf      printf
#define dputs        puts
#define dout(x)      cout<<#x" = "<<(x)<<endl
#define darray(x,n)  {int i;rep(i,n)cout<<#x"["<<i<<"] = "<<*((x)+i)<<endl;}
#define dloop(i,s,g) for(int (i)=(s);(i)<(g);(i)++)
#define drep(i,n)    for(int (i)=0;(i)<(n);(i)++)
#define dstop()      scanf("%*c")
#else
#define dprintf      (1)?0:printf
#define dputs        (1)?0:puts
#define dout(x)
#define darray(x,n)
#define dloop(i,s,g) if(int i=0){}else
#define drep(i,n)    if(int i=0){}else
#define dstop()
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())
#define in(T,...) T __VA_ARGS__; impl(__VA_ARGS__)
#define array(T,id,n) T id[(n)]; for(int i=0;i<(n);i++)cin>>id[i]
#define putv(n)     cout<<(n)<<endl

//#define int long long;
#ifndef int
#define INF (0x7fffffff)
#else
#define INF (0x7fffffffffffffff)
#endif

void impl(){};
template <typename T,typename... TS >
void impl(T &head,TS &... tail)
{
  cin>>head;
  impl(tail ...);
}

#define MAX_V 112345 //??????????????°????????§

struct edge
{
  int to;
  int cost;
};

int V; // ???????????°(???????????£??\??????)
vector<edge> G[MAX_V]; // ?????????
int d[MAX_V]; // ??¨?????????????????????????????????

void dijkstra(int s)
{
  int i;
  priority_queue<i_i,vector<i_i>,greater<i_i>> que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(i_i(0,s));
  while(!que.empty())
    {
      i_i p=que.top();
      que.pop();
      int v=p.second;
      if(d[v]<p.first) continue;
      int n=G[v].size();
      for(i=0;i<n;i++)
	{
	  edge e=G[v][i];
	  if(d[e.to]>d[v]+e.cost)
	    {
	      d[e.to]=d[v]+e.cost;
	      que.push(i_i(d[e.to],e.to));
	    }	  
	}
    }
}

signed main(void)
{
  cin>>V;
  in(int,E,r);
  int i;
  int s,t,c;
  rep(i,E)
    {
      cin>>s>>t>>c;
      G[s].pb((edge){t,c});
    }
  dijkstra(r);
  for(i=0;i<V;i++)
    d[i]==INF?cout<<"INF"<<endl:putv(d[i]);
  return 0;
}
