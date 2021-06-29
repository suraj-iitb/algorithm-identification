#include <stdio.h>
#include <stdlib.h>

#define INF -1

typedef struct{
  int d;
  int f;
}timestamp;

typedef struct{
  int u;
  int k;
  int *v;
}graph;

graph g[110];
timestamp t[110];
int mytime = 0;
int q[110];

void bfs(void);

int main(void){
  int i,j,n;

  scanf("%d", &n);


  for(i = 0; i <= n; i++){
    q[i] = t[i].d = t[i].f = INF;
  }

  for(i = 1; i <= n; i++){
    scanf("%d%d", &g[i].u, &g[i].k);
    g[i].v = (int *)malloc(sizeof(int) * (g[i].k+1));
    for(j = 1; j <= g[i].k; j++){
      scanf("%d", &g[i].v[j]);
    }
  }

  bfs();

  for(i = 1; i <= n; i++)
    printf("%d %d\n", i, t[i].d);
 
  return 0;
}

void bfs(void){
  int s = 1;
  int first = 1, last = 1;
  int i, u;

  t[s].d = 0;
  //enqueue
  q[last] = s;
  last++;
  while(first != last){
    //dequeue
    u = q[first];
    q[first] = INF;
    first++;
    for(i = 1; i <= g[u].k; i++){
      if( t[ g[u].v[i] ].d == INF){
        t[g[u].v[i]].d = t[u].d + 1;
        //enqueue
        q[last] = g[u].v[i];
        last++;
      }
    }
  }
}
