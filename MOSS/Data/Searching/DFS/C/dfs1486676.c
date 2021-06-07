#include <stdio.h>
#define MAX 150

void DepthFirstSearch(int);
 
int graph[MAX][MAX];
int d[MAX],f[MAX];
int t=0, n;

int main()
{
  int u, k, v;
  int i, j;
  
  scanf("%d",&n);
  
  for(i=0; i<n; i++){
	scanf("%d%d", &u, &k);
	for(j=0; j<k; j++){
	  scanf("%d", &v);
	  graph[u-1][v-1] = 1;
	}
  }
  
  for(i=0; i<n; i++){
	if(d[i]==0) DepthFirstSearch(i);
  }
  
  for(i=0; i<n; i++){
	printf("%d %d %d\n", i+1, d[i], f[i]);
  }

  return 0;
}

void DepthFirstSearch(int i)
{
  int j;
  t++;
  d[i] = t;
 
  for(j=0; j<n; j++){
	if(graph[i][j]!=0 && d[j]==0){
	  DepthFirstSearch(j);
	}
  }
  t++;
  f[i]=t;
}
