#include <stdio.h>
#define N 101
#define INF 200000000
#define MAX 100

int A[N][N],color[N],f[N],d[N],q[MAX];
int n, time, head, tail, u;

void enqueue(x)
{
  q[tail] = x;
  if((tail+1)==MAX)
    tail = 0;
  else tail++;
}

int dequeue()
{
  int x;
  x = q[head];
  if((head+1)==MAX)
    head = 0;
  else
    head++;
  return x;
}

void bfs(int s)
{
  int i, Q;
  for(i=1 ; i<=n-s ; i++ ){
    color[u] = 0;
    d[u] = INF;
  }
  color[s] = 2;
  d[s] = 0;
  enqueue(1);
  while(head!=tail){
    u = dequeue();
    for(i=1 ; i<=n ; i++){
      if(A[u][i]!=0){
	if(color[i]==0){
	  color[i] = 2;
	  d[i] = d[u]+1;
	  enqueue(i);
	}
      }
    }
    color[u] = 3;
  }
}

int main()
{
  int i, j, k, a;
  scanf("%d",&n);
  for(i=0 ; i<=n ; i++ )
    for(j=0 ; j<=n ; j++ )
      A[i][j] = 0;
  
  for(i=1 ; i<=n ; i++ ){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=1 ; j<=k ; j++ ){
      scanf("%d",&a);
      A[u][a] = 1;
    }
  }
  bfs(1);

  for( i=1 ; i<=n ;i++){
    if(i!=1 && (d[i]==0 || d[i]==INF)) printf("%d -1\n",i);
    else printf("%d %d\n",i,d[i]);
  }

  return 0;
}
