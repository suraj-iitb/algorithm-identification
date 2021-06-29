#include<cstdio>
#include<iostream>
using namespace std;
int n, e; long long int adj[105][105];
long long int INFTY = (1LL<<32);
void floyd()
{
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
    {
      if(adj[i][k] == INFTY) continue;
      for(int j=0; j<n; j++)
      {
        if(adj[k][j] == INFTY) continue;
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
}

int main()
{
  scanf("%d%d", &n, &e);
  int s, t, d;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      adj[i][j] = INFTY;
    adj[i][i] = 0;
  }
  for(int i=0; i<e; i++)
  {
    scanf("%d%d%d", &s, &t, &d);
    adj[s][t] = d;
  }
  floyd();
  for(int i=0; i<n; i++)
  {
    if(adj[i][i] != 0)
    {
      printf("NEGATIVE CYCLE\n"); return 0;
    }
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(j) printf(" ");
      if(adj[i][j] == INFTY)
        printf("INF");
      else printf("%lld", adj[i][j]);
    }
    printf("\n");
  }
  return 0;
}

