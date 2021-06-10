#include <iostream>
#include <numeric>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
ll graph[105][105];
int V,E;
const ll inf=1e11+5;


void floyd()
{
  for(int k=0;k<V;k++)
    {
      for(int i=0;i<V;i++)
	{
	  for(int j=0;j<V;j++)
	    {
	      if(graph[i][k]==inf || graph[k][j]==inf) continue;
	      graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
	    }
	}
    }
}
int main(int argc,char const* argv[])
{
  cin >> V >> E;
 fill(graph[0],graph[V],inf);
  for(int i=0;i<V;i++)
    {
      graph[i][i]=0;
    }
  for(int i=0;i<E;i++)
    {
      int s,t,cost;
      cin >> s >> t >> cost;
      graph[s][t]=cost;
    }
  floyd();
  for(int i=0;i<V;i++)
    {
      if(graph[i][i]<0)
	{
	  cout << "NEGATIVE CYCLE" << endl;
	  return 0;
	}
    }
  for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
	{
	  if(graph[i][j]==inf)
	    {
	      cout << "INF";
	    }
	  else
	    {
	      cout << graph[i][j];
	    }
	  if(j!=V-1) cout << ' '; 
	}
      cout << endl;
    }
  return 0;
}

